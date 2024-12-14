#pragma once
#include <string>
#include <cmath>
#include <mutex>

class CombatVisitor;

class NPC {
protected:
    std::string name;
    int x, y;
    bool dead;
    std::mutex mtx; // ??? ???????? ??????? ? NPC

public:
    NPC(const std::string& name, int x, int y);
    virtual ~NPC() = default;

    virtual void accept(CombatVisitor& visitor, NPC& other) = 0;
    std::string getName() const;
    int getX() const;
    int getY() const;
    virtual std::string getType() const = 0;
    double distanceTo(const NPC& other) const;
    bool isDead() const;
    void kill();

    void move(int dx, int dy); // ????? ??? ??????????? NPC
    bool isWithinBounds(int maxX, int maxY) const; // ???????? ?????? ?????
};