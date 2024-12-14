#pragma once
#include <string>
#include <fstream>

class Logger {
public:
    virtual ~Logger() = default;

    virtual void log(const std::string& message) = 0;
};

class ConsoleLogger : public Logger {
public:
    ~ConsoleLogger() override = default;

    void log(const std::string& message) override;
};

class FileLogger : public Logger {
private:
    std::ofstream file;
public:
    explicit FileLogger(const std::string& filename);
    ~FileLogger() override;

    void log(const std::string& message) override;
};
