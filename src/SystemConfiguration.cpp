#include "SystemConfiguration.h"
#include <iostream>
#include <thread>
#include <string>
#include <fstream>


#ifdef _WIN32
#include <windows.h>
#include <tchar.h>
#include <winnt.h>
#include <VersionHelpers.h>
#elif __linux__
#include <unistd.h>
#include <sys/sysinfo.h>
#elif __APPLE__
#include <sys/sysctl.h>
#endif

#if defined(__linux__)
#include <fstream>
#elif defined(__APPLE__)
#include <sys/sysctl.h>
#endif

SystemConfiguration::SystemConfiguration() {}

SystemConfiguration::~SystemConfiguration() {}

std::string SystemConfiguration::getOperatingSystem() const {
#ifdef _WIN32
    return "Windows";
#elif __linux__
    return "Linux";
#elif __APPLE__
    return "macOS";
#else
    return "Unknown";
#endif
}
int SystemConfiguration::getNumCPUCore(SystemConfiguration &obj) const {
    if(obj.getOperatingSystem()=="Windows")
    {
       return obj.getNumCPUCores();
       //return 0;
    }
    else if(obj.getOperatingSystem()=="Linux")
    {
        return obj.getNumCPUCores();
        //return 0;
    }
    else if(obj.getOperatingSystem()=="macOS")
    {
        return obj.getNumCPUCores();
        //return 0;
    }
    return 0;

}
/*int SystemConfiguration::Linux_core() const
{
    std::ifstream cpuinfo("/proc/cpuinfo");
    std::string line;
    int physicalCores = 0;
    while (std::getline(cpuinfo, line)) {
        if (line.find("cpu cores") != std::string::npos) {
            physicalCores = std::stoi(line.substr(line.find(":") + 1));
            break;
        }
    }
    cpuinfo.close();
    return physicalCores;
}

int SystemConfiguration::Mac_core() const
{
    int nm[2];
    size_t len = 4;
    uint32_t count;

   // nm[0] = CTL_HW;
    //nm[1] = HW_PHYSICALCPU;
    //sysctl(nm, 2, &count, &len, NULL, 0);

    return count;
}
*/
/*int SystemConfiguration::Win_core() {
    SYSTEM_INFO sysInfo;
    GetSystemInfo(&sysInfo);
    
    //DWORD logicalProcessorCount = sysInfo.dwNumberOfProcessors;

    DWORD physicalProcessorCount = 0;
    DWORD length = 0;
    GetLogicalProcessorInformation(nullptr, &length);

    SYSTEM_LOGICAL_PROCESSOR_INFORMATION* buffer = (SYSTEM_LOGICAL_PROCESSOR_INFORMATION*)malloc(length);
    GetLogicalProcessorInformation(buffer, &length);

    DWORD byteOffset = 0;
    while (byteOffset + sizeof(SYSTEM_LOGICAL_PROCESSOR_INFORMATION) <= length) {
        if (buffer->Relationship == RelationProcessorCore) {
            physicalProcessorCount++;
        }
        byteOffset += sizeof(SYSTEM_LOGICAL_PROCESSOR_INFORMATION);
        buffer++;
    }
    free(buffer);

    return physicalProcessorCount;

}
*/
int SystemConfiguration::getNumCPUCores() const {
#ifdef _WIN32
    SYSTEM_INFO sysInfo;
    GetSystemInfo(&sysInfo);
    return sysInfo.dwNumberOfProcessors/2;
#elif __linux__ || __APPLE__
    return sysconf(_SC_NPROCESSORS_ONLN);
#endif
}

unsigned long long SystemConfiguration::getTotalMemory() const {
#ifdef _WIN32
    MEMORYSTATUSEX memInfo;
    memInfo.dwLength = sizeof(MEMORYSTATUSEX);
    GlobalMemoryStatusEx(&memInfo);
    return memInfo.ullTotalPhys / (1024 * 1024);
#elif __linux__
    struct sysinfo memInfo;
    sysinfo(&memInfo);
    return memInfo.totalram / (1024 * 1024);
#elif __APPLE__
    size_t length = sizeof(int);
    int total_memory;
    int mib[2];
    mib[0] = CTL_HW;
    mib[1] = HW_MEMSIZE;
    sysctl(mib, 2, &total_memory, &length, NULL, 0);
    return total_memory / (1024 * 1024);
#endif
}

unsigned int SystemConfiguration::getCPUCacheSize() const {
#ifdef _WIN32
    // Unsupported on Windows
    return 0;
#elif __linux__ || __APPLE__
    // Unsupported on Linux and macOS
    return 0;
#endif
}

int SystemConfiguration::getNumGPUs() const {
#ifdef _WIN32
    // Unsupported on Windows
    return 0;
#elif __linux__
    // Unsupported on Linux
    return 0;
#elif __APPLE__
    // Unsupported on macOS
    return 0;
#endif
}

std::string SystemConfiguration::getCPUArchitecture() const {
#ifdef _WIN32
    SYSTEM_INFO sysInfo;
    GetSystemInfo(&sysInfo);
    switch (sysInfo.wProcessorArchitecture) {
    case PROCESSOR_ARCHITECTURE_AMD64:
        return "x64 (AMD or Intel)";
    case PROCESSOR_ARCHITECTURE_ARM:
        return "ARM";
    case PROCESSOR_ARCHITECTURE_IA64:
        return "Intel Itanium-based";
    case PROCESSOR_ARCHITECTURE_INTEL:
        return "x86";
    default:
        return "Unknown architecture";
    }
#elif __linux__ || __APPLE__
    // Unsupported on Linux and macOS
    return "Unknown";
#endif
}

int SystemConfiguration::getCPUBits() const {
#ifdef _WIN32
    return sizeof(void*) * 8;
#elif __linux__ || __APPLE__
    // Unsupported on Linux and macOS
    return 0;
#endif
}


int SystemConfiguration::get_threads() const{
    unsigned int numThreads = std::thread::hardware_concurrency();
    if (numThreads == 0) {
        std::cout << "Unable to determine the number of threads." << std::endl;
        return 0;
    } else {
        return numThreads;
    }

}

int SystemConfiguration::get_logical_processors() const{
    unsigned int numLogicalProcessors = std::thread::hardware_concurrency();
    if (numLogicalProcessors == 0) {
        std::cout << "Unable to determine the number of logical processors." << std::endl;
        return 0;
    } else {
        return numLogicalProcessors;
    }

}