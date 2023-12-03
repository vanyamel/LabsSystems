#include "Manager.h"
#include <iostream>
#include <stdexcept>
#include <cassert>

const int CONDITION_FOR_SUCCESS = 10;
const int CONDITION_FOR_NONCRITICAL_FAILURE = 20;
const int MAX_RETRIES = 3;

int f(int x) {
    static int f_retries = 0;
    if (x < CONDITION_FOR_SUCCESS) {
        return x * x;
    }
    else if (x < CONDITION_FOR_NONCRITICAL_FAILURE && f_retries < MAX_RETRIES) {
        std::cout << "Non-critical failure in f, retrying...\n";
        f_retries++;
        return -1; 
    }
    else {
        throw std::runtime_error("Critical failure in f");
    }
}

int g(int x) {
    static int g_retries = 0;
    if (x < CONDITION_FOR_SUCCESS) {
        return x + 1;
    }
    else if (x < CONDITION_FOR_NONCRITICAL_FAILURE && g_retries < MAX_RETRIES) {
        std::cout << "Non-critical failure in g, retrying...\n";
        g_retries++;
        return -1; 
    }
    else {
        throw std::runtime_error("Critical failure in g");
    }
}
void testFunctionF() {
    assert(f(2) == 4);
    assert(f(-3) == 9);
    assert(f(0) == 0);
    std::cout << "testFunctionF passed." << std::endl;
}

void testFunctionG() {
    assert(g(2) == 3);
    assert(g(-3) == -2);
    assert(g(0) == 1);
    std::cout << "testFunctionG passed." << std::endl;
}

void testManagerComputation() {
    Manager manager;
    int x = 2;
    manager.StartComputation(x, f, g);
}

int main() {
    Manager manager;
    int x;
    std::cout << "Enter an integer value for x: ";
    std::cin >> x;
    manager.StartComputation(x, f, g);
    return 0;

    testFunctionF();
    testFunctionG();
    testManagerComputation();
}
