/*
   Copyright 2022 The Silkworm Authors

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

#pragma once

#include <string>

#include <silkworm/db/stage.hpp>

namespace silkworm::stagedsync {

class Finish : public Stage {
  public:
    explicit Finish(SyncContext* sync_context, std::string build_info)
        : Stage(sync_context, db::stages::kFinishKey),
          build_info_(std::move(build_info)) {}
    ~Finish() override = default;

    Stage::Result forward(db::RWTxn& txn) final;
    Stage::Result unwind(db::RWTxn& txn) final;

    // Finish does not prune.
    Stage::Result prune(db::RWTxn&) final { return Stage::Result::kSuccess; };

  private:
    std::string build_info_;
};
}  // namespace silkworm::stagedsync
