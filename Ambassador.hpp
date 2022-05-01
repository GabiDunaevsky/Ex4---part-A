#pragma once
#include "Player.hpp"

namespace coup {

    class Ambassador : public Player {
    public:
        Ambassador(Game &game, const std::string& name);
        void transfer(const Player &player1, const Player &player2);
        void block(const Player &player);
        std::string role() const override;
    };
}
 
