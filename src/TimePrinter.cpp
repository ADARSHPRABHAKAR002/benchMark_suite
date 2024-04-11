#include "TimePrinter.h"

void TimePrinter::printCurrentTime() {
    // Get the current time
    std::time_t currentTime = std::time(nullptr);

    // Convert the current time to a string
    std::string timeString = std::ctime(&currentTime);

    // Print the current time
    std::cout << "Current Time: " << timeString;
}
