#ifndef SYSTEM_CONFIGURATION_H
#define SYSTEM_CONFIGURATION_H

#include <string>

class SystemConfiguration {
public:
    SystemConfiguration();
    ~SystemConfiguration();

    std::string getOperatingSystem() const;
    int getNumCPUCore(SystemConfiguration &obj) const;
    int Win_core() ;
    int Linux_core() const;
    int Mac_core() const;
    int getNumCPUCores() const;
    unsigned long long getTotalMemory() const;
    unsigned int getCPUCacheSize() const;
    int getNumGPUs() const;
    std::string getCPUArchitecture() const;
    int getCPUBits() const;
    int get_threads() const;
    int get_logical_processors() const;

};

#endif // SYSTEM_CONFIGURATION_H
