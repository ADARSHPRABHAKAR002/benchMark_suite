#include <iostream>
#include "TimePrinter.h"
#include "SystemConfiguration.h"
#include "Chrono_timer.h"
#include "MemoryIntensiveCalculator.h"
#include "ComputationalIntensiveTask.h"
#include "BranchIntensiveTask.h"
#include <vector>
#include <random>
void get_benchmark_score();
int main() {
    std::cout<<"*************************************************************************************"<<std::endl;
    std::cout<<"*************************************************************************************"<<std::endl;
    std::cout<<"----------------------------WELCOME_TO_BENCH_MARK_SUITE------------------------------"<<std::endl;
    std::cout<<"*************************************************************************************"<<std::endl;
    std::cout<<"*************************************************************************************"<<std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    auto start_t = std::chrono::high_resolution_clock::now();
    // Print current time
    std::cout << "=== Current Time ===" << std::endl;
    TimePrinter::printCurrentTime();
    std::cout << std::endl;

    //Get system configurations
    //make it singleton class
    SystemConfiguration sysConfig;
    std::cout << "=== System Configurations ===" << std::endl;
    std::cout << "Operating System: " << sysConfig.getOperatingSystem() << std::endl;
    std::cout << "Number of CPU Cores: " << sysConfig.getNumCPUCores() << std::endl;
    std::cout << "Number of Logical Processors: " << sysConfig.get_logical_processors() << std::endl;
    std::cout << "Number of Threads available: "<< sysConfig.get_threads() << std::endl;
    std::cout << "Total Memory: " << sysConfig.getTotalMemory() << " MB" << std::endl;
    //std::cout << "CPU Architecture: " << sysConfig.getCPUArchitecture() << std::endl;
    //std::cout << "CPU Bits: " << sysConfig.getCPUBits() << std::endl;
    std::cout << std::endl;
    
    
    //get benchmark score fucntion
    get_benchmark_score();


    //Total time
    auto end_t = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end_t - start_t;
	std::cout << "=== Total Time ===" << std::endl;
    std::cout << "Time taken for all operations: " <<  duration.count() << " seconds" << std::endl;



    return 0;
}

 void get_benchmark_score()
    {
    //Memory intensive
    std::cout << "=== Memory Intensive Operation ===" << std::endl;
    MemoryIntensiveCalculator calculator;
    auto start_m = std::chrono::high_resolution_clock::now();
    for(int i=0;i<50;i++)
    {
    calculator.performTask();
    }
    auto end_m = std::chrono::high_resolution_clock::now();
    auto duration_m = std::chrono::duration_cast<std::chrono::milliseconds>(end_m - start_m); 
    double avg_mem=duration_m.count()/50;   
    std::cout << "Avg Time taken for memory-intensive operation: " << avg_mem << " ms" << std::endl;
    double mem_score_float = ((1/avg_mem)*100)*1000*100;
    int mem_score = (int)mem_score_float;
    std::cout<<"Memory-intensive operation BenchMarkScore: "<<mem_score<<std::endl;

    std::cout << std::endl;


    

    //computaional intensive
	std::cout << "=== Computaional Intensive Operation ===" << std::endl;
    int dimensions = 10;
    int numSamples = 1000000;
    ComputationalIntensiveTask task(dimensions, numSamples);
    auto start_c = std::chrono::high_resolution_clock::now();
    for(int i=0;i<50;i++)
    {
    double result = task.monteCarloIntegration();
    }
    auto end_c = std::chrono::high_resolution_clock::now();
    auto duration_c = std::chrono::duration_cast<std::chrono::milliseconds>(end_c - start_c);
    double avg_com=duration_c.count()/50;    
    std::cout << "Time taken for computataional-intensive operation: " << avg_com << " ms" << std::endl;
    double com_score_float = ((1/avg_com)*100)*1000*100*3;
    int com_score = (int)com_score_float;
    std::cout<<"Computational-intensive operation BenchMarkScore: "<<com_score<<std::endl;
    std::cout << std::endl;

    //solid principals
    //iostream manupulations
    //endl or \n
    //make it singleton class
    //OOPs


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
    for(int i=0;i<50;i++)
    {
    sorter.sort(arr);
    }
    auto end_b = std::chrono::high_resolution_clock::now();
    auto duration_b = std::chrono::duration_cast<std::chrono::milliseconds>(end_b - start_b);
    double avg_brn=duration_b.count()/50;   
    std::cout << "Time taken for branch-intensive operation: " <<  avg_brn<< " ms" << std::endl;
    double brn_score_float = ((1/avg_brn)*100)*1000*100;
    int brn_score = (int)brn_score_float;
    std::cout<<"Branch-intensive operation BenchMarkScore: "<<brn_score<<std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout<<"--------------------------------BENCH_MARK_SCORE--------------------------------------"<<std::endl;
    std::cout<<"-------------------------------------"<<mem_score+com_score+brn_score<<"--------------------------------------------"<<std::endl;

    std::cout << std::endl;


}