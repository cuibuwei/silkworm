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

#include "segment_reader.hpp"

#include <stdexcept>

#include <silkworm/core/common/util.hpp>
#include <silkworm/infra/common/log.hpp>

namespace silkworm::snapshots {

SegmentFileReader::SegmentFileReader(
    SnapshotPath path,
    std::optional<MemoryMappedRegion> segment_region)
    : path_(std::move(path)),
      decompressor_{path_.path(), segment_region} {}

SegmentFileReader::~SegmentFileReader() {
    close();
}

MemoryMappedRegion SegmentFileReader::memory_file_region() const {
    const auto memory_file{decompressor_.memory_file()};
    if (!memory_file) return MemoryMappedRegion{};
    return memory_file->region();
}

void SegmentFileReader::reopen_segment() {
    close();

    // Open decompressor that opens the mapped file in turns
    decompressor_.open();
}

SegmentFileReader::Iterator& SegmentFileReader::Iterator::operator++() {
    bool has_next = it_.has_next();
    ++it_;

    if (has_next) {
        decoder_->decode_word(*it_);
        decoder_->check_sanity_with_metadata(path_);
    } else {
        decoder_.reset();
    }
    return *this;
}

SegmentFileReader::Iterator& SegmentFileReader::Iterator::operator+=(size_t count) {
    while ((count > 1) && it_.has_next()) {
        it_.skip();
        --count;
    }
    if (count > 0) {
        ++*this;
    }
    return *this;
}

bool operator==(const SegmentFileReader::Iterator& lhs, const SegmentFileReader::Iterator& rhs) {
    return (lhs.decoder_ == rhs.decoder_) &&
           (!lhs.decoder_ || (lhs.it_ == rhs.it_));
}

SegmentFileReader::Iterator SegmentFileReader::begin(std::shared_ptr<Decoder> decoder) const {
    auto it = decompressor_.begin();
    if (it == decompressor_.end()) {
        return end();
    }
    decoder->decode_word(*it);
    decoder->check_sanity_with_metadata(path_);
    return SegmentFileReader::Iterator{std::move(it), std::move(decoder), path()};
}

SegmentFileReader::Iterator SegmentFileReader::end() const {
    return SegmentFileReader::Iterator{decompressor_.end(), {}, path()};
}

seg::Decompressor::Iterator SegmentFileReader::seek_decompressor(uint64_t offset, std::optional<Hash> hash_prefix) const {
    return decompressor_.seek(offset, hash_prefix ? ByteView{hash_prefix->bytes, 1} : ByteView{});
}

SegmentFileReader::Iterator SegmentFileReader::seek(uint64_t offset, std::optional<Hash> hash_prefix, std::shared_ptr<Decoder> decoder) const {
    auto it = seek_decompressor(offset, hash_prefix);
    if (it == decompressor_.end()) {
        return end();
    }
    try {
        decoder->decode_word(*it);
    } catch (...) {
        return end();
    }
    decoder->check_sanity_with_metadata(path_);
    return SegmentFileReader::Iterator{std::move(it), std::move(decoder), path()};
}

void SegmentFileReader::close() {
    // Close decompressor that closes the mapped file in turns
    decompressor_.close();
}

}  // namespace silkworm::snapshots