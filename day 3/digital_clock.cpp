#include <iostream>
#include <ctime>
#include <chrono>
#include <thread>
#include <cstdlib>

int main() {
    while (true) {
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
        time_t now = time(0);
        tm* localTime = localtime(&now);

        std::cout << (localTime->tm_hour < 10 ? "0" : "") << localTime->tm_hour << ":"
                  << (localTime->tm_min < 10 ? "0" : "") << localTime->tm_min << ":"
                  << (localTime->tm_sec < 10 ? "0" : "") << localTime->tm_sec << std::endl;

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    return 0;
}
