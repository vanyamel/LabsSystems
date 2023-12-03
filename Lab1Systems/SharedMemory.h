#ifndef SHARED_MEMORY_H
#define SHARED_MEMORY_H

#include <mutex>
#include <condition_variable>
#include <queue>
#include <optional>
#include "ComputationResult.h"

class SharedMemory {
public:
    void PutResult(const ComputationResult& result);
    std::optional<ComputationResult> TryGetResult();

private:
    std::mutex mutex_;
    std::condition_variable cond_var_;
    std::queue<ComputationResult> results_;
};

#endif // SHARED_MEMORY_H
