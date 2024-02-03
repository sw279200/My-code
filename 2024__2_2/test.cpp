#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <thread>
#include <chrono>

void printHeart() {
    std::string heart[] = {
        "  ***   ***  ",
        " ***** ***** ",
        "*************",
        " *********** ",
        "  *********  ",
        "   *******   ",
        "    *****    ",
        "     ***     ",
        "      *      "
    };

    for (int i = 0; i < sizeof(heart) / sizeof(heart[0]); i++) {
        std::cout<< heart[i] << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }

    for (int i = sizeof(heart) / sizeof(heart[0]) - 2; i <= 0; i--) {
        std::cout << heart[i] << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
}

int main() {
    printHeart();

    return 0;
}