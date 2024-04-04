#include "SystemConfiguration.h"

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

int SystemConfiguration::getNumCPUCores() const {
#ifdef _WIN32
    SYSTEM_INFO sysInfo;
    GetSystemInfo(&sysInfo);
    return sysInfo.dwNumberOfProcessors;
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
