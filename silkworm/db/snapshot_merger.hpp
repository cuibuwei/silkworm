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

#pragma once

#include "data_migration.hpp"
#include "snapshots/snapshot_repository.hpp"

namespace silkworm::db {

class SnapshotMerger : public DataMigration {
  public:
    SnapshotMerger(
        snapshots::SnapshotRepository& snapshots,
        std::filesystem::path tmp_dir_path)
        : snapshots_(snapshots),
          tmp_dir_path_(std::move(tmp_dir_path)) {}

  private:
    static constexpr size_t kBatchSize = 10;
    static constexpr size_t kMaxSnapshotSize = 100'000;

    const char* name() const override { return "SnapshotMerger"; }
    std::unique_ptr<DataMigrationCommand> next_command() override;
    std::shared_ptr<DataMigrationResult> migrate(std::unique_ptr<DataMigrationCommand> command) override;
    void index(std::shared_ptr<DataMigrationResult> result) override;
    void commit(std::shared_ptr<DataMigrationResult> result) override;
    Task<void> cleanup() override;

    snapshots::SnapshotRepository& snapshots_;
    std::filesystem::path tmp_dir_path_;
};

}  // namespace silkworm::db