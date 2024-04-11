#ifndef COMPUTATIONAL_INTENSIVE_TASK_H
#define COMPUTATIONAL_INTENSIVE_TASK_H

#include <vector>

class ComputationalIntensiveTask {
public:
    // Constructor
    ComputationalIntensiveTask(const std::vector<int>& vec);

    // Function to perform computationally intensive task
    long long computeTask();

private:
    std::vector<int> vec;
};

#endif
