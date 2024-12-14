#pragma once
#include "NPC.h"

class Ork : public NPC {
public:
    Ork(const std::string& name, int x, int y);
    void accept(CombatVisitor& visitor, NPC& target) override;
    std::string getType() const override {
        return "Orc";
    }
};
