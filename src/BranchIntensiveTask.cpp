#include "BranchIntensiveTask.h"
#include <random>
#include <chrono>

BranchIntensiveTask::BranchIntensiveTask()
    : rng(std::chrono::steady_clock::now().time_since_epoch().count()) {}

void BranchIntensiveTask::sort(std::vector<int>& arr) {
    quicksort(arr, 0, arr.size() - 1);
}

void BranchIntensiveTask::quicksort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quicksort(arr, low, pivotIndex - 1);
        quicksort(arr, pivotIndex + 1, high);
    }
}

int BranchIntensiveTask::partition(std::vector<int>& arr, int low, int high) {
    int pivotIndex = getRandomPivot(low, high);
    int pivotValue = arr[pivotIndex];
    std::swap(arr[pivotIndex], arr[high]); 
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivotValue) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

int BranchIntensiveTask::getRandomPivot(int low, int high) {
    std::uniform_int_distribution<int> dist(low, high);
    return dist(rng);
}
