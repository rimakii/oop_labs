#include <iostream>
#include <thread>
#include <vector>
#include <memory>
#include <chrono>
#include <random>
#include <mutex>
#include "include/factory.h"
#include "include/logger.h"
#include "include/visitor.h"
#include "include/EventManager.h" 

const int MAP_SIZE_X = 100;
const int MAP_SIZE_Y = 100;
const int NUM_NPCS = 50;
const int GAME_DURATION = 30; 

std::mutex cout_mtx; 
std::mutex npcs_mtx; 


void moveNPCs(std::vector<std::shared_ptr<NPC>>& npcs) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(-10, 10);

    while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));

        std::lock_guard<std::mutex> lock(npcs_mtx);
        for (auto& npc : npcs) {
            if (!npc->isDead()) {
                int dx = dist(gen);
                int dy = dist(gen);
                npc->move(dx, dy);
                if (!npc->isWithinBounds(MAP_SIZE_X, MAP_SIZE_Y)) {
                    npc->move(-dx, -dy); 
                }
            }
        }
    }
}

void combatNPCs(std::vector<std::shared_ptr<NPC>>& npcs, Logger& logger) {
    CombatVisitor combatVisitor(10, logger); 

    while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        std::lock_guard<std::mutex> lock(npcs_mtx);
        for (auto it1 = npcs.begin(); it1 != npcs.end();) {
            bool removed = false;
            for (auto it2 = std::next(it1); it2 != npcs.end();) {
                if (!(*it1)->isDead() && !(*it2)->isDead() && (*it1)->distanceTo(**it2) <= 10) {
                    logger.log("Battle between " + (*it1)->getName() + " and " + (*it2)->getName());

                    if (auto ork = dynamic_cast<Ork*>(it1->get())) {
                        combatVisitor.visit(*ork, **it2);
                    } else if (auto knight = dynamic_cast<Knight*>(it1->get())) {
                        combatVisitor.visit(*knight, **it2);
                    } else if (auto bear = dynamic_cast<Bear*>(it1->get())) {
                        combatVisitor.visit(*bear, **it2);
                    }

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
                } else {
                    ++it2;
                }
            }
            if (!removed) ++it1;
        }
    }
}

void printMap(const std::vector<std::shared_ptr<NPC>>& npcs) {
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(1));

        std::lock_guard<std::mutex> lock(cout_mtx);
        std::cout << "Map:" << std::endl;
        for (const auto& npc : npcs) {
            if (!npc->isDead()) {
                std::cout << npc->getName() << " at (" << npc->getX() << ", " << npc->getY() << ")" << std::endl;
            }
        }
    }
}

int main() {
    std::vector<std::shared_ptr<NPC>> npcs;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 100);

    for (int i = 0; i < NUM_NPCS; ++i) {
        std::string type = (i % 3 == 0) ? "Orc" : (i % 3 == 1) ? "Bear" : "Knight";
        npcs.push_back(NPCFactory::createNPC(type, "NPC" + std::to_string(i), dist(gen), dist(gen), npcs));
    }

    ConsoleLogger logger;

    std::thread moveThread(moveNPCs, std::ref(npcs));
    std::thread combatThread(combatNPCs, std::ref(npcs), std::ref(logger));
    std::thread printThread(printMap, std::ref(npcs));

    std::this_thread::sleep_for(std::chrono::seconds(GAME_DURATION));

    moveThread.detach();
    combatThread.detach();
    printThread.detach();

    std::lock_guard<std::mutex> lock(cout_mtx);
    std::cout << "Game over. Survivors:" << std::endl;
    for (const auto& npc : npcs) {
        if (!npc->isDead()) {
            std::cout << npc->getName() << " at (" << npc->getX() << ", " << npc->getY() << ")" << std::endl;
        }
    }

    return 0;
}