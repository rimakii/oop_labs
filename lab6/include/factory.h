#include <vector>
#include <memory>
#include <string>
#include <exception>
#include <unordered_set>
#include "NPC.h"
#include "logger.h"
#include <iomanip>

class NPCFactory {
private:
    static bool isUniqueName(const std::string& name, const std::vector<std::shared_ptr<NPC>> npcs);
    static bool areCoordinatesValid(int x, int y);

public:
    static std::shared_ptr<NPC> createNPC(const std::string& type, const std::string& name, int x, int y, const std::vector<std::shared_ptr<NPC>> npcs);
    static void saveToFile(const std::vector<std::shared_ptr<NPC>>& npcs, const std::string& filename, Logger& logger);
    static std::vector<std::shared_ptr<NPC>> loadFromFile(const std::string& filename, Logger& logger);
    static void printAllNPCs(Logger& logger, const std::vector<std::shared_ptr<NPC>> npcs);
    static void battleMode(std::vector<std::shared_ptr<NPC>>& npcs, double range, Logger& logger);
};