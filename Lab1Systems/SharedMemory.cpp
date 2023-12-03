#include "SharedMemory.h"

void SharedMemory::PutResult(const ComputationResult& result) {
    std::lock_guard<std::mutex> lock(mutex_);
    results_.push(result);
    cond_var_.notify_one();
}

std::optional<ComputationResult> SharedMemory::TryGetResult() {
    std::unique_lock<std::mutex> lock(mutex_);
    if (!results_.empty()) {
        ComputationResult result = results_.front();
        results_.pop();
        return result;
    }
    return std::nullopt;
}
