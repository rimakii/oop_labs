#include "../include/ork.h"
#include "../include/visitor.h"

Ork::Ork(const std::string& name, int x, int y) : NPC(name, x, y) {}

void Ork::accept(CombatVisitor& visitor, NPC& other) {
    visitor.visit(*this, other);
}