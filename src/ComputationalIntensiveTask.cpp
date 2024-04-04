#include "ComputationalIntensiveTask.h"
#include <cmath>

// Constructor
ComputationalIntensiveTask::ComputationalIntensiveTask(const std::vector<int>& inputVec) : vec(inputVec) {}

// Function to perform computationally intensive task
long long ComputationalIntensiveTask::computeTask() {
    long long result = 0;
    for (int num : vec)
    {
        result += static_cast<long long>(sqrt(num));
    }
    return result;
}
