#include "../include/visitor.h"
#include "../include/ork.h"
#include "../include/knight.h"
#include "../include/bear.h"
#include "../include/logger.h"

CombatVisitor::CombatVisitor(double range, Logger& logger) : range(range), logger(logger) {}

bool CombatVisitor::visit(Ork& orc, NPC& other) {
    if (orc.distanceTo(other) <= range) {
        if (dynamic_cast<Bear*>(&other)) {
            other.kill();
            logger.log(orc.getName() + " killed " + other.getName());
            return true;
        }
        if (dynamic_cast<Knight*>(&other)) {
            orc.kill();
            logger.log(other.getName() + " killed " + orc.getName());
            return true;
        }
    }
    return false;
}

bool CombatVisitor::visit(Knight& knight, NPC& other) {
    if (knight.distanceTo(other) <= range) {
        if (dynamic_cast<Ork*>(&other)) {
            other.kill();
            logger.log(knight.getName() + " killed " + other.getName());
            return true;
        }
        if (dynamic_cast<Bear*>(&other)) {
            knight.kill();
            logger.log(other.getName() + " killed " + knight.getName());
            return true;
        }
    }
    return false;
}

bool CombatVisitor::visit(Bear& bear, NPC& other) {
    if (bear.distanceTo(other) <= range) {
        if (dynamic_cast<Knight*>(&other)) {
            other.kill();
            logger.log(bear.getName() + " killed " + other.getName());
            return true;
        }
        if (dynamic_cast<Ork*>(&other)) {
            bear.kill();
            logger.log(other.getName() + " killed " + bear.getName());
            return true;
        }
    }
    return false;
}

