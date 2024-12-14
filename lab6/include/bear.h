#pragma once
#include "NPC.h"

class Bear : public NPC {
public:
    Bear(const std::string& name, int x, int y);
    void accept(CombatVisitor& visitor, NPC& target) override;
    std::string getType() const override {
        return "Bear";
    }
};

