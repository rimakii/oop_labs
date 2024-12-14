#pragma once
#include "NPC.h"

class Knight : public NPC {
public:
    Knight(const std::string& name, int x, int y);
    void accept(CombatVisitor& visitor, NPC& target) override;
    std::string getType() const override {
        return "Knight";
    }
};

