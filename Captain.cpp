
#include "Captain.hpp"

namespace coup {
    Captain::Captain(Game &game, const std::string& name) :
            Player{game, name} {}

    void Captain::block(Player &player) {
    }

    void Captain::steal(Player &player) {
        this->ifNeedToCoup();
        this->_numOfCoins +=2;
        this->_game.nextTuren();
    }
    std::string Captain::role() const {
        return "Captain";
    }
}