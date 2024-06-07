#ifndef COMPUTATIONAL_INTENSIVETASK_HPP
#define COMPUTATIONAL_INTENSIVETASK_HPP

#include <vector>
#include <random>

class ComputationalIntensiveTask {
private:
    int dimensions;
    int numSamples;
    std::mt19937_64 rng;
    std::uniform_real_distribution<double> dist;

    
    
    double complexFunction(const std::vector<double>& point);

public:
    // Constructor 
    ComputationalIntensiveTask(int dimensions, int numSamples);

    // Monte Carlo integration method
    double monteCarloIntegration();
};

#endif // COMPUTATIONALINTENSIVETASK_HPP

