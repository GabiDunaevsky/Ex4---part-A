#pragma once
#include "vector"
#include "string"
#include <exception>
#include <stdexcept>
#include <iostream>

namespace coup {
    class Game {
    private:
        std::vector<std::string> _players;
        size_t _turn = 0;
    public:

        void addPlayerToGame(const std::string& name);
        std::vector<std::string> players();
        std::string turn();
        std::string winner();
        void nextTuren();
    };
}

