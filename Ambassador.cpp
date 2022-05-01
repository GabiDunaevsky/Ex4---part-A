#include "Ambassador.hpp"

namespace coup {

    Ambassador::Ambassador(Game &game, const std::string& name) : Player{game, name} {}
    void Ambassador::block(const Player &player) {}
    void Ambassador::transfer(const Player &player1, const Player &player2) {
        this->ifNeedToCoup();
        this->_game.nextTuren();
    }
    std::string Ambassador::role() const {
        return "Ambassador";
    }
}
   