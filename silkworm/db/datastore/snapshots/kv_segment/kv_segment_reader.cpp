/*
   Copyright 2024 The Silkworm Authors

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#include "kv_segment_reader.hpp"

#include <array>
#include <stdexcept>

#include <silkworm/core/common/util.hpp>
#include <silkworm/infra/common/log.hpp>

namespace silkworm::snapshots {

KVSegmentFileReader::KVSegmentFileReader(
    SnapshotPath path,
    seg::CompressionKind compression_kind,
    std::optional<MemoryMappedRegion> segment_region)
    : path_(std::move(path)),
      decompressor_{path_.path(), segment_region, compression_kind} {}

KVSegmentFileReader::~KVSegmentFileReader() {
    close();
}

MemoryMappedRegion KVSegmentFileReader::memory_file_region() const {
    const auto memory_file = decompressor_.memory_file();
    if (!memory_file) return MemoryMappedRegion{};
    return memory_file->region();
}

void KVSegmentFileReader::reopen_segment() {
    close();

    // Open decompressor that opens the mapped file in turns
    decompressor_.open();
}

KVSegmentFileReader::Iterator& KVSegmentFileReader::Iterator::operator++() {
    for (auto& decoder : std::array{decoders_.first, decoders_.second}) {
        bool has_next = it_.has_next();
        ++it_;

        if (has_next) {
            decoder->decode_word(*it_);
            decoder->check_sanity_with_metadata(path_);
        } else {
            decoders_.first.reset();
            decoders_.second.reset();
            break;
        }
    }
    return *this;
}

KVSegmentFileReader::Iterator& KVSegmentFileReader::Iterator::operator+=(size_t count) {
    count *= 2;
    while ((count > 2) && it_.has_next()) {
        it_.skip_auto();
        --count;
    }
    if (count >= 2) {
        ++*this;
    }
    return *this;
}

bool operator==(const KVSegmentFileReader::Iterator& lhs, const KVSegmentFileReader::Iterator& rhs) {
    return (lhs.decoders_ == rhs.decoders_) &&
           (!lhs.decoders_.first || (lhs.it_ == rhs.it_));
}

KVSegmentFileReader::Iterator KVSegmentFileReader::begin(std::shared_ptr<Decoder> key_decoder, std::shared_ptr<Decoder> value_decoder) const {
    auto it = decompressor_.begin();
    if (it == decompressor_.end()) {
        return end();
    }
    if (!it.has_next()) {
        return end();
    }

    key_decoder->decode_word(*it);
    key_decoder->check_sanity_with_metadata(path_);

    ++it;
    value_decoder->decode_word(*it);
    value_decoder->check_sanity_with_metadata(path_);

    return KVSegmentFileReader::Iterator{std::move(it), std::move(key_decoder), std::move(value_decoder), path()};
}

KVSegmentFileReader::Iterator KVSegmentFileReader::end() const {
    return KVSegmentFileReader::Iterator{decompressor_.end(), {}, {}, path()};
}

seg::Decompressor::Iterator KVSegmentFileReader::seek_decompressor(uint64_t offset, std::optional<Hash> hash_prefix) const {
    return decompressor_.seek(offset, hash_prefix ? ByteView{hash_prefix->bytes, 1} : ByteView{});
}

KVSegmentFileReader::Iterator KVSegmentFileReader::seek(
    uint64_t offset,
    std::optional<Hash> hash_prefix,
    std::shared_ptr<Decoder> key_decoder,
    std::shared_ptr<Decoder> value_decoder) const {
    auto it = seek_decompressor(offset, hash_prefix);
    if (it == decompressor_.end()) {
        return end();
    }
    if (!it.has_next()) {
        return end();
    }

    try {
        key_decoder->decode_word(*it);
    } catch (...) {
        return end();
    }
    key_decoder->check_sanity_with_metadata(path_);

    ++it;
    value_decoder->decode_word(*it);
    value_decoder->check_sanity_with_metadata(path_);

    return KVSegmentFileReader::Iterator{std::move(it), std::move(key_decoder), std::move(value_decoder), path()};
}

void KVSegmentFileReader::close() {
    // Close decompressor that closes the mapped file in turns
    decompressor_.close();
}

}  // namespace silkworm::snapshots