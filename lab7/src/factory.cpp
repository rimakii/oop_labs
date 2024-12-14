#include "../include/factory.h"
#include "../include/ork.h"
#include "../include/knight.h"
#include "../include/bear.h"
#include "../include/visitor.h"
#include "../include/logger.h"
#include <fstream>
#include <iomanip> 
#include <iostream>

const int MAP_SIZE_X = 100;
const int MAP_SIZE_Y = 100;

bool NPCFactory::isUniqueName(const std::string& name,const std::vector<std::shared_ptr<NPC>> npcs) {
    for (const auto& npc : npcs) {
        if (npc->getName() == name) {
            return false;  // Name is not unique
        }
    }
    return true;  // Name is unique
}

std::shared_ptr<NPC> NPCFactory::createNPC(const std::string& type, const std::string& name, int x, int y, const std::vector<std::shared_ptr<NPC>> npcs) {
    if (!areCoordinatesValid(x, y)) {
        throw std::invalid_argument("Invalid coordinates: " + std::to_string(x) + ", " + std::to_string(y));
    }

    if (!isUniqueName(name, npcs)) {
        throw std::invalid_argument("NPC name must be unique: " + name);
    }

    std::shared_ptr<NPC> npc;
    if (type == "Orc") {
        npc = std::make_shared<Ork>(name, x, y);
    } else if (type == "Knight") {
        npc = std::make_shared<Knight>(name, x, y);
    } else if (type == "Bear") {
        npc = std::make_shared<Bear>(name, x, y);
    } else {
        throw std::invalid_argument("Unknown NPC type: " + type);
    }

    return npc;
}

void NPCFactory::saveToFile(const std::vector<std::shared_ptr<NPC>>& npcs, const std::string& filename, Logger& logger) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        logger.log("Failed to open file for saving NPCs.");
        throw std::ios_base::failure("Failed to open file for saving NPCs.");
    }

    for (const auto& npc : npcs) {
        file << npc->getType() << " "
             << npc->getName() << " "
             << npc->getX() << " "
             << npc->getY() << "\n";
        logger.log("Saved NPC: " + npc->getName() + " to file.");
    }
    file.close();
    logger.log("NPCs saved to file: " + filename);
}

void NPCFactory::printAllNPCs(Logger& logger, const std::vector<std::shared_ptr<NPC>> npcs) {
    if (npcs.empty()) {
        logger.log("No NPCs available.");
        return;
    }

    logger.log("NPCs List:");
    for (const auto& npc : npcs) {
        logger.log("NPC: " + npc->getType() + " - " + npc->getName() + " at (" + std::to_string(npc->getX()) + ", " + std::to_string(npc->getY()) + ")");
    }
}

std::vector<std::shared_ptr<NPC>> NPCFactory::loadFromFile(const std::string& filename, Logger& logger) {
    std::vector<std::shared_ptr<NPC>> npcs;
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::ios_base::failure("Failed to open file for loading NPCs.");
    }

    std::string type, name;
    int x, y;
    while (file >> type >> name >> x >> y) {
        try {
            npcs.push_back(createNPC(type, name, x, y, npcs));
        } catch (const std::exception& e) {
            std::cerr << "Error creating NPC from file: " << e.what() << std::endl;
        }
    }
    return npcs;
}

void NPCFactory::battleMode(std::vector<std::shared_ptr<NPC>>& npcs, double range, Logger& logger) {
    CombatVisitor combat(range, logger);
    for (auto it1 = npcs.begin(); it1 != npcs.end();) {
        bool removed = false;
        for (auto it2 = std::next(it1); it2 != npcs.end();) {
            logger.log("Battle between " + (*it1)->getName() + " and " + (*it2)->getName());
            (*it1)->accept(combat, **it2);

            if ((*it1)->isDead()) {
                logger.log((*it1)->getName() + " is dead.");
                it1 = npcs.erase(it1);
                removed = true;
                break;
            }

            if ((*it2)->isDead()) {
                logger.log((*it2)->getName() + " is dead.");
                it2 = npcs.erase(it2);
            } else {
                ++it2;
            }
        }
        if (!removed) ++it1;
    }
}

bool NPCFactory::areCoordinatesValid(int x, int y) {
    return x >= 0 && x <= MAP_SIZE_X && y >= 0 && y <= MAP_SIZE_Y;
}