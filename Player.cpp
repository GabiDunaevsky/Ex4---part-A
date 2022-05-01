#include "Player.hpp"
#include "Game.hpp"
#include "exception"
#include <exception>
#include <stdexcept>
#include <iostream>

namespace coup {
    Player::Player(Game &game, const std::string &name)
            : _game(game), _name(name), _numOfCoins(0) {
        this->_game.addPlayerToGame(name);
    }

    void Player::income() {
        this->canPlay();
        this->ifNeedToCoup();
        this->_numOfCoins++;
        this->_game.nextTuren();
    }
    int Player::coins() const {
        return this->_numOfCoins;
    }

    void Player::foreign_aid() {
        this->canPlay();
        this->ifNeedToCoup();
        this->_numOfCoins += 2;
        this->_game.nextTuren();
    }
    void Player::coup(Player &other_player) {
        this->canPlay();
        if (this->_numOfCoins < 7) {
            throw std::invalid_argument("Not enough Coins!!");
        }
        this->_numOfCoins -= 7;
        this->_game.nextTuren();
    }
    void Player::canPlay() {
        if (this->_game.turn() != this->_name) {
        }
    }
    void Player::ifNeedToCoup(){
        if(this->_numOfCoins >= 10){
            throw std::invalid_argument( "You must coup!");
        }
    }
}
