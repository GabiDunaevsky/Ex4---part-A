#pragma once
#include "Player.hpp"

namespace coup {
    class Assassin : public Player {
    public:
        Assassin(Game &game,const std::string& name);
        virtual void coup(Player& player) override;
        std::string role() const override;
    };
}


