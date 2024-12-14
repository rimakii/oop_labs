#include "../include/logger.h"
#include <iostream>


void ConsoleLogger::log(const std::string& message) {
    std::cout << "[Console]: " << message << std::endl;
}

FileLogger::FileLogger(const std::string& filename) {
    file.open(filename, std::ios::app);
    if (!file.is_open()) {
        throw std::runtime_error("Unable to open file for logging.");
    }
}

FileLogger::~FileLogger() {
    if (file.is_open()) {
        file.close();
    }
}

void FileLogger::log(const std::string& message) {
    if (file.is_open()) {
        file << "[File]: " << message << std::endl;
    }
}
