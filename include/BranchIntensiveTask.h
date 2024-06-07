#ifndef BRANCH_INTENSIVE_TASK_HPP
#define BRANCH_INTENSIVE_TASK_HPP

#include <vector>
#include <random>

class BranchIntensiveTask {
public:
    BranchIntensiveTask();
    void sort(std::vector<int>& arr);

private:
    void quicksort(std::vector<int>& arr, int low, int high);
    int partition(std::vector<int>& arr, int low, int high);
    int getRandomPivot(int low, int high);

    std::mt19937_64 rng;
};

#endif 
