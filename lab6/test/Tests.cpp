#include "gtest/gtest.h"
#include "../include/NPC.h"
#include "../include/ork.h"
#include "../include/knight.h"
#include "../include/bear.h"
#include "../include/factory.h"
#include "../include/logger.h"
#include "../include/visitor.h"
#include "../include/EventManager.h"
#include <memory>
#include <vector>
#include <fstream>
#include <sstream>


class TestNPC : public NPC {
public:
    TestNPC(const std::string& name, int x, int y) : NPC(name, x, y) {}
    void accept(CombatVisitor& visitor, NPC& other) {};
    std::string getType() const {
    return "TestNPC";
    }
};

std::shared_ptr<ConsoleLogger> consoleLogger;
std::shared_ptr<FileLogger> fileLogger;

void SetUpLogging() {
    consoleLogger = std::make_shared<ConsoleLogger>();
    fileLogger = std::make_shared<FileLogger>("test_log.txt");
}

void TearDownLogging() {
    if (fileLogger) {
        std::remove("test_log.txt");
    }
}

TEST(NPCTest, ConstructorTest) {
    TestNPC npc("TestName", 10, 20);

    EXPECT_EQ(npc.getName(), "TestName");
    EXPECT_EQ(npc.getX(), 10);
    EXPECT_EQ(npc.getY(), 20);
    EXPECT_FALSE(npc.isDead());
}

TEST(NPCTest, DistanceToTest) {
    TestNPC npc1("NPC1", 0, 0);
    TestNPC npc2("NPC2", 3, 4);

    EXPECT_DOUBLE_EQ(npc1.distanceTo(npc2), 5.0); 
}

TEST(NPCTest, KillTest) {
    TestNPC npc("TestName", 10, 20);

    EXPECT_FALSE(npc.isDead());
    npc.kill();
    EXPECT_TRUE(npc.isDead());
}

TEST(NPCFactoryTest, CreateNPCTest) {
    SetUpLogging(); 

    std::vector<std::shared_ptr<NPC>> npcList;

    auto orc = NPCFactory::createNPC("Orc", "OrcName", 0, 0, npcList);
    auto knight = NPCFactory::createNPC("Knight", "KnightName", 1, 1, npcList);
    auto bear = NPCFactory::createNPC("Bear", "BearName", 2, 2, npcList);

    ASSERT_NE(orc, nullptr);
    ASSERT_NE(knight, nullptr);
    ASSERT_NE(bear, nullptr);

    EXPECT_EQ(orc->getType(), "Orc");
    EXPECT_EQ(orc->getName(), "OrcName");
    EXPECT_EQ(orc->getX(), 0);
    EXPECT_EQ(orc->getY(), 0);

    EXPECT_EQ(knight->getType(), "Knight");
    EXPECT_EQ(knight->getName(), "KnightName");
    EXPECT_EQ(knight->getX(), 1);
    EXPECT_EQ(knight->getY(), 1);

    EXPECT_EQ(bear->getType(), "Bear");
    EXPECT_EQ(bear->getName(), "BearName");
    EXPECT_EQ(bear->getX(), 2);
    EXPECT_EQ(bear->getY(), 2);

    TearDownLogging(); 
}




