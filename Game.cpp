#include "exception"
#include "vector"
#include <exception>
#include <stdexcept>
#include <iostream>
#include "Game.hpp"


namespace coup {
    std::string Game::turn() {
        return this->_players[this->_turn];
    }
    std::vector<std::string> Game::players() {
        return this->_players;
    }
    void Game::addPlayerToGame(const std::string &name) {
        if(this->_players.size() == 6){
            throw std::invalid_argument("alrady has 6 players");
        }
        this->_players.push_back(name);
    }
    std::string Game::winner() {
        if (this->_players.size() > 1) {
            throw std::invalid_argument("The game is not over yet");
        }
        return this->_players[0];
    }
    void Game::nextTuren() {
        this->_turn++;
        this->_turn = this->_turn % this->_players.size();
    }

}
