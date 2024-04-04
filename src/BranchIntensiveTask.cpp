#include "BranchIntensiveTask.h"

BranchIntensiveTask::BranchIntensiveTask(const std::vector<int>& inputData) : data(inputData) {}

long long BranchIntensiveTask::computeTask() {
    long long result = 0;
    for (int num : data) {
        if (num % 2 == 0) {
            result += num;
        } else {
            result -= num;
        }
    }
    return result;
}
