#pragma once
#include <vector>
#include <memory>
#include "logger.h"

class Observer {
public:
    virtual ~Observer() = default;
    virtual void onEvent(const std::string& message) = 0;
};

class EventManager {
private:
    std::vector<std::shared_ptr<Logger>> observers; 
public:
    void addObserver(const std::shared_ptr<Logger>& logger);
    void notify(const std::string& event);
};
