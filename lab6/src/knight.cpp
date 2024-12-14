#include "../include/knight.h"
#include "../include/visitor.h"

Knight::Knight(const std::string& name, int x, int y) : NPC(name, x, y) {}

void Knight::accept(CombatVisitor& visitor, NPC& other) {
    visitor.visit(*this, other);
}