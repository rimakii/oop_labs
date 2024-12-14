#pragma once
#include "NPC.h"
#include "bear.h"
#include "knight.h"
#include "ork.h"
#include "logger.h"
#include <iostream>


class CombatVisitor {
private:
    double range;
    Logger& logger;

public:
    CombatVisitor(double range, Logger& logger);
    bool visit(Ork& orc, NPC& other);
    bool visit(Knight& knight, NPC& other);
    bool visit(Bear& bear, NPC& other);
};
