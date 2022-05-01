#include "Player.hpp"
#include "Game.hpp"
#include "Duke.hpp"
#include "string"

namespace coup {

    Duke::Duke(Game &game, const std::string &name) : Player{game, name} {}
    
    void Duke::tax() {
        this->ifNeedToCoup();
        this->_numOfCoins += 3;
        this->_game.nextTuren();
    }

    void Duke::block(Player &toBlock) {
    }
    std::string Duke::role() const {
        return "Duke";
    }
}
