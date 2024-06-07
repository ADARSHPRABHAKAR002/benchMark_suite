#include <iostream>
#include "TimePrinter.h"
#include "SystemConfiguration.h"
#include "Chrono_timer.h"
#include "MemoryIntensiveCalculator.h"
#include "ComputationalIntensiveTask.h"
#include "BranchIntensiveTask.h"
#include <vector>
#include <random>

int main() {
    auto start_t = std::chrono::high_resolution_clock::now();
    // Print current time
    std::cout << "=== Current Time ===" << std::endl;
    TimePrinter::printCurrentTime();
    std::cout << std::endl;

    // Get system configurations
    SystemConfiguration sysConfig;
    std::cout << "=== System Configurations ===" << std::endl;
    std::cout << "Operating System: " << sysConfig.getOperatingSystem() << std::endl;
    std::cout << "Number of CPU Cores: " << sysConfig.getNumCPUCores() << std::endl;
    std::cout << "Total Memory: " << sysConfig.getTotalMemory() << " MB" << std::endl;
    //std::cout << "CPU Architecture: " << sysConfig.getCPUArchitecture() << std::endl;
    //std::cout << "CPU Bits: " << sysConfig.getCPUBits() << std::endl;
    std::cout << std::endl;

    

    //Memory intensive
    std::cout << "=== Memory Intensive Operation ===" << std::endl;
    MemoryIntensiveCalculator calculator;
    auto start_m = std::chrono::high_resolution_clock::now();
    
    calculator.performTask();
   
    auto end_m = std::chrono::high_resolution_clock::now();
    auto duration_m = std::chrono::duration_cast<std::chrono::milliseconds>(end_m - start_m);    
    std::cout << "Time taken for memory-intensive operation: " << duration_m.count() << " ms" << std::endl;
    std::cout << std::endl;


    

    //computaional intensive
	std::cout << "=== Computaional Intensive Operation ===" << std::endl;
    int dimensions = 10;
    int numSamples = 1000000;
    ComputationalIntensiveTask task(dimensions, numSamples);
    auto start_c = std::chrono::high_resolution_clock::now();
    
    double result = task.monteCarloIntegration();
    
    auto end_c = std::chrono::high_resolution_clock::now();
    auto duration_c = std::chrono::duration_cast<std::chrono::milliseconds>(end_c - start_c);    
    std::cout << "Time taken for computataional-intensive operation: " << duration_c.count() << " ms" << std::endl;
    std::cout << std::endl;




    //branch internsive task
    std::cout << "=== Branch Intensive Operation ===" << std::endl;
    const int SIZE = 1000000; // Size of the vector
    std::vector<int> arr(SIZE);
    std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> dist(1, 1000000); 
    for (int i = 0; i < SIZE; ++i) {
        arr[i] = dist(rng);
    }
    BranchIntensiveTask sorter;
    auto start_b = std::chrono::high_resolution_clock::now();

    sorter.sort(arr);

    auto end_b = std::chrono::high_resolution_clock::now();
    auto duration_b = std::chrono::duration_cast<std::chrono::milliseconds>(end_b - start_b);  
    std::cout << "Time taken for branch-intensive operation: " <<  duration_b.count() << " ms" << std::endl;
    std::cout << std::endl;

    //Total time
    auto end_t = std::chrono::high_resolution_clock::now();
    auto duration_t = std::chrono::duration_cast<std::chrono::milliseconds>(end_t - start_t); 
	std::cout << "=== Total Time ===" << std::endl;
    std::cout << "Time taken for all operations: " <<  duration_t.count() << " ms" << std::endl;



    return 0;
}
