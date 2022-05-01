#pragma once
#include "string"
#include "Game.hpp"
#include <exception>
#include <stdexcept>
#include <iostream>

namespace coup {

    class Player {

    protected:
        std::string _name;
        int _numOfCoins;
        Game &_game;

        Player(Game &game, const std::string& name);
        void canPlay();
    public:
        void income();
        void foreign_aid();
        virtual void coup(Player &other_player);
        virtual std::string role() const = 0;
        int coins() const;
        void ifNeedToCoup();
    };
}

