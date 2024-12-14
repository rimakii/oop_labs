#include <iostream>
#include <vector>
#include "include/factory.h"
#include "include/logger.h"
#include "include/visitor.h"
#include "include/EventManager.h" 


int main() {
    std::vector<std::shared_ptr<NPC>> npcs;
    std::vector<std::shared_ptr<NPC>> npcs1;

    auto consoleLogger = std::make_shared<ConsoleLogger>();
    auto fileLogger = std::make_shared<FileLogger>("log.txt");

    EventManager eventManager;
    eventManager.addObserver(consoleLogger);
    eventManager.addObserver(fileLogger);

    try {
        npcs.push_back(NPCFactory::createNPC("Orc", "Gorok", 100, 200, npcs));
        eventManager.notify("Orc created: Gorok at (100, 200)");

        npcs.push_back(NPCFactory::createNPC("Knight", "Sir Lancelot", 150, 200, npcs));
        eventManager.notify("Knight created: Sir Lancelot at (150, 200)");

        npcs.push_back(NPCFactory::createNPC("Bear", "Grizzly", 200, 150, npcs));
        eventManager.notify("Bear created: Grizzly at (200, 150)");

        consoleLogger->log("NPCs created.");

        NPCFactory::saveToFile(npcs, "npcs.txt", *consoleLogger);
        eventManager.notify("NPCs saved to file.");

        npcs1 = NPCFactory::loadFromFile("npcs.txt", *consoleLogger);
        eventManager.notify("NPCs loaded from file.");

        NPCFactory::printAllNPCs(*consoleLogger, npcs);
        eventManager.notify("NPCs printed.");

        NPCFactory::battleMode(npcs, 150.0, *consoleLogger);
        eventManager.notify("Battle finished.");

    } catch (const std::exception& e) {
        eventManager.notify("Error: " + std::string(e.what()));
    }

    return 0;
}
