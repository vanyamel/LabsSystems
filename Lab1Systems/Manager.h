#ifndef MANAGER_H
#define MANAGER_H

#include <functional>
#include "SharedMemory.h"

class Manager {
public:
    void StartComputation(int x, std::function<int(int)> f, std::function<int(int)> g);
    void Compute(std::function<int(int)> func, int x);

private:
    SharedMemory shared_memory_;
};

#endif // MANAGER_H
