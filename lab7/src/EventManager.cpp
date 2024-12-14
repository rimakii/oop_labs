#include "../include/EventManager.h"

void EventManager::addObserver(const std::shared_ptr<Logger>& logger) {
    observers.push_back(logger);
}

void EventManager::notify(const std::string& event) {
    for (const auto& observer : observers) {
        observer->log(event);
    }
}
