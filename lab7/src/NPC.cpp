#include "../include/NPC.h"

NPC::NPC(const std::string& name, int x, int y) : name(name), x(x), y(y), dead(false) {}

std::string NPC::getName() const { return name; }

int NPC::getX() const { return x; }

int NPC::getY() const { return y; }

double NPC::distanceTo(const NPC& other) const {
    return std::sqrt(std::pow(x - other.x, 2) + std::pow(y - other.y, 2));
}

bool NPC::isDead() const { return dead; }

void NPC::kill() { dead = true; }

void NPC::move(int dx, int dy) {
    std::lock_guard<std::mutex> lock(mtx);
    x += dx;
    y += dy;
}

bool NPC::isWithinBounds(int maxX, int maxY) const {
    return x >= 0 && x <= maxX && y >= 0 && y <= maxY;
}