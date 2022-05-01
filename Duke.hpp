#pragma once
#include "Player.hpp"

namespace coup {
    class Duke : public Player {

    public:
        Duke(Game &game, const std::string &name);
        void tax();
        void block(Player &toBlock);
        std::string role() const override;
    };
}

