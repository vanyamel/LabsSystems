#include "Manager.h"
#include <iostream>
#include <thread>
#include <optional>

void Manager::StartComputation(int x, std::function<int(int)> f, std::function<int(int)> g) {
    std::thread f_thread([this, f, x]() { Compute(f, x); });
    std::thread g_thread([this, g, x]() { Compute(g, x); });

    f_thread.join();
    g_thread.join();

    auto f_result = shared_memory_.TryGetResult();
    auto g_result = shared_memory_.TryGetResult();

    if (f_result && g_result) {
        if (f_result->isSuccess && g_result->isSuccess) {
            int xor_result = f_result->result ^ g_result->result;
            std::cout << "f(x) XOR g(x) = " << xor_result << std::endl;
        }
        else {
            std::cerr << "One of the computations failed." << std::endl;
        }
    }
    else {
        std::cerr << "Did not receive results from both computations." << std::endl;
    }
}

void Manager::Compute(std::function<int(int)> func, int x) {
    ComputationResult result;
    try {
        result.result = func(x);
        result.isSuccess = result.result != -1;
        result.isCriticalFailure = false;
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Exception caught in Compute: " << e.what() << std::endl;
        result.isSuccess = false;
        result.isCriticalFailure = true;
    }
    shared_memory_.PutResult(result);
}

