#include "TimePrinter.h"

void TimePrinter::printCurrentTime() {
   
    std::time_t currentTime = std::time(nullptr);

    // Convert the current time to a string
    std::string timeString = std::ctime(&currentTime);

    
    std::cout << "Current Time: " << timeString;
}
