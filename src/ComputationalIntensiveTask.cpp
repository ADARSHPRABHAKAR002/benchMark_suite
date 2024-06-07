#include "ComputationalIntensiveTask.h"
#include <cmath>
#include <chrono>

// Constructor 
ComputationalIntensiveTask::ComputationalIntensiveTask(int dimensions, int numSamples)
    : dimensions(dimensions), numSamples(numSamples),
      rng(std::chrono::steady_clock::now().time_since_epoch().count()), dist(0.0, 1.0) {}


// find complex function
double ComputationalIntensiveTask::complexFunction(const std::vector<double>& point) {
    double result = 0.0;
    for (int i = 0; i < dimensions; ++i) {
        result += sin(point[i]) * exp(point[i]);
    }
    return result;
}

// Monte Carlo integration method
double ComputationalIntensiveTask::monteCarloIntegration() {
    double sum = 0.0;
    for (int i = 0; i < numSamples; ++i) {
        std::vector<double> point(dimensions);
        for (int j = 0; j < dimensions; ++j) {
            point[j] = dist(rng); 
        }
        sum += complexFunction(point);
    }

    // The volume of the unit hypercube in 'dimensions' dimensions is 1.0
    // So we just return the average of the function values
    return sum / numSamples;
}

