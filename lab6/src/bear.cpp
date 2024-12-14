#include "../include/bear.h"
#include "../include/visitor.h"

Bear::Bear(const std::string& name, int x, int y) : NPC(name, x, y) {}

void Bear::accept(CombatVisitor& visitor, NPC& other) {
    visitor.visit(*this, other);
}