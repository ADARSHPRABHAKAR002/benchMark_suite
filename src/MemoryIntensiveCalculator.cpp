#include "MemoryIntensiveCalculator.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iostream>

MemoryIntensiveCalculator::MemoryIntensiveCalculator() {
    data = new int[arraySize];
}

MemoryIntensiveCalculator::~MemoryIntensiveCalculator() {
    delete[] data;
}

void MemoryIntensiveCalculator::performTask() {
   
    srand(static_cast<unsigned>(time(nullptr)));
    for (int i = 0; i < arraySize; ++i) {
        data[i] = rand();
    }

   
    for (int i = 0; i < arraySize / 2; ++i) {
        // Copy elements
        data[i + arraySize / 2] = data[i];
        // Swap elements
        std::swap(data[i], data[arraySize - i - 1]);
    }


    std::sort(data, data + arraySize);


    volatile int sum = 0;
    for (int i = 0; i < arraySize; ++i) {
        sum += data[i];
    }


}
