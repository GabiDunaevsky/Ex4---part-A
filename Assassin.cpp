
#include "Assassin.hpp"
#include "exception"
#include "Assassin.hpp"

namespace coup {

    Assassin::Assassin(Game &game, const std::string &name)
            : Player{game, name} {
    }
    void Assassin::coup(Player &other_player) {
        if (this->_numOfCoins < 3) {
            throw std::invalid_argument("Not enogh Coins!!");
        }
        this->_game.nextTuren();
    }
    std::string Assassin::role() const {
        return "Assassin";
    }
}