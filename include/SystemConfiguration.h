#ifndef SYSTEM_CONFIGURATION_H
#define SYSTEM_CONFIGURATION_H

#include <string>

class SystemConfiguration {
public:
    SystemConfiguration();
    ~SystemConfiguration();

    std::string getOperatingSystem() const;
    int getNumCPUCores() const;
    unsigned long long getTotalMemory() const;
    unsigned int getCPUCacheSize() const;
    int getNumGPUs() const;
    std::string getCPUArchitecture() const;
    int getCPUBits() const;
};

#endif // SYSTEM_CONFIGURATION_H
