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

    // Start the chrono timer
    Chrono chrono;
    chrono.start();
    // Perform memory-intensive operation
    std::cout << "=== Memory Intensive Operation ===" << std::endl;
    std::vector<std::vector<int>> largeMatrix = MemoryIntensiveCalculator::generateLargeMatrix(1000, 1000);
    // Stop the chrono timer
    chrono.stop();
    // Print elapsed time
    std::cout << "Time taken for memory-intensive operation: " << chrono.elapsedMilliseconds() << " ms" << std::endl;


	std::cout << std::endl;
	std::cout << "=== Computaional Intensive Operation ===" << std::endl;
    //computaional intensive
    const int SIZE = 1000000; // Adjust this value for larger datasets

    // Create a vector to store random integers
    std::vector<int> data(SIZE);

    // Seed for random number generation
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 1000); // Adjust the range as needed

    // Generate random integers and store them in the vector
    for (int i = 0; i < SIZE; ++i) {
        data[i] = dis(gen);
    }

    // Create an object of ComputationalIntensiveTask
    ComputationalIntensiveTask task(data);

    // Perform the computational intensive task
    Chrono chrono_com;
    chrono_com.start();
    long long result_com = task.computeTask();
    chrono_com.stop();

    // Output the result
    std::cout << "Time taken for computataional-intensive operation: " << chrono_com.elapsedMilliseconds() << " ms" << std::endl;


    //branch internsive task
    std::cout << std::endl;
	std::cout << "=== Branch Intensive Operation ===" << std::endl;
    BranchIntensiveTask task_b(data);
    // Perform the branch intensive task
    Chrono chrono_branch;
    chrono_branch.start();
    long long result_branch = task_b.computeTask();
    chrono_branch.stop();

    std::cout << "Time taken for branch-intensive operation: " << chrono_branch.elapsedMilliseconds() << " ms" << std::endl;

	std::cout << std::endl;
	std::cout << "=== Total Time ===" << std::endl;



    return 0;
}
