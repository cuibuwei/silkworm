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

#include "txn_segment_collation.hpp"

#include <stdexcept>

#include <silkworm/db/access_layer.hpp>
#include <silkworm/infra/common/log.hpp>

#include "txn_segment.hpp"

namespace silkworm::db {

void TransactionSegmentCollation::copy(ROTxn& txn, const SegmentCollationCommand& command, snapshots::SegmentFileWriter& file_writer) const {
    BlockNumRange range = command.range;
    snapshots::TransactionSegmentWriter writer{file_writer};
    auto out = writer.out();
    auto system_tx = snapshots::empty_system_tx();

    for (BlockNum i = range.start; i < range.end; ++i) {
        BlockBody body;
        bool found = read_canonical_body(txn, i, /* read_senders = */ true, body);
        if (!found) throw std::runtime_error{"TransactionSegmentCollation::copy missing body for block " + std::to_string(i)};

        *out++ = system_tx;
        for (auto& value : body.transactions) {
            *out++ = value;
        }
        *out++ = system_tx;
    }
}

void TransactionSegmentCollation::prune(RWTxn& txn, BlockNumRange range) const {
    for (BlockNum i = range.start, count = 1; i < range.end; ++i, ++count) {
        auto hash_opt = read_canonical_header_hash(txn, i);
        if (!hash_opt) continue;
        auto hash = *hash_opt;

        delete_senders(txn, hash, i);

        auto body_opt = read_canonical_body_for_storage(txn, i);
        if (body_opt) {
            auto& body = *body_opt;
            delete_transactions(txn, body.base_txn_id + 1, body.txn_count - 2);
        }

        if ((count > 10000) && ((count % 10000) == 0)) {
            SILK_DEBUG_M("TransactionSegmentCollation") << "cleaned up until block " << i;
        }
    }
}

}  // namespace silkworm::db