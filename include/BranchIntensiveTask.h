#ifndef BRANCH_INTENSIVE_TASK_H
#define BRANCH_INTENSIVE_TASK_H

#include <vector>

class BranchIntensiveTask {
public:
    BranchIntensiveTask(const std::vector<int>& data);
    long long computeTask();

private:
    std::vector<int> data;
};

#endif
