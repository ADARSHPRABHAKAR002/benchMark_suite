#ifndef MEMORY_INTENSIVE_CALCULATOR_H
#define MEMORY_INTENSIVE_CALCULATOR_H

class MemoryIntensiveCalculator {
public:
    MemoryIntensiveCalculator();
    ~MemoryIntensiveCalculator();

    void performTask();

private:
    int* data;
    const int arraySize = 1000000; // 1 million elements
};

#endif // MEMORY_INTENSIVE_CALCULATOR_H
