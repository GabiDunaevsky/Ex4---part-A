#include "exception"

#include "Captain.hpp"
#include "Contessa.hpp"
#include "Duke.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"

#include "Player.hpp"
#include "Game.hpp"

#include "doctest.h"

using namespace coup;

TEST_CASE ("Test A single Game") {

    Game game{};
    Game game1{};

    Duke duke{game, "Gabi"};
    Assassin assassin{game, "Omer"};
    Ambassador ambassador{game, "Guy"};
    Captain captain{game, "Lidor"};
    Contessa contessa1{game, "Snir"};
    Contessa contessa2{game, "Omri"};


    Duke duke1{game1,"Zohi"};
    Ambassador ambassador1 {game1,"Zohi"};
    
    SUBCASE("Checking Game"){
        CHECK_THROWS(game.winner());
        CHECK_EQ(game.turn(), "Gabi");
        CHECK_THROWS(game.addPlayerToGame("Eli"));
    }
    
    SUBCASE("Player Generally") {
        CHECK_NOTHROW(duke.income());
        CHECK_EQ(duke.coins(), 1);
        for(int i = 0 ; i < 10 ;i++){
            duke1.income();
            ambassador1.income();
        }
        CHECK_THROWS(duke1.tax());// because he has 10 points.
        CHECK_THROWS(ambassador1.transfer(duke1,ambassador1));// because he has 10 points.
        CHECK_NOTHROW(assassin.foreign_aid());
        CHECK_THROWS(contessa1.coup(contessa2));//  Not his turn
    }

    SUBCASE("Charecters") {
        CHECK_NOTHROW(duke.role());
        CHECK_EQ(duke.coins(),1);
        CHECK_EQ(duke1.coins(),10);
        CHECK_EQ(duke.role(), "Duke");
        CHECK_NOTHROW(assassin.role());
        CHECK_EQ(assassin.coins(),2);
        CHECK_EQ(assassin.role(), "Assassin");
        CHECK_NOTHROW(ambassador.role());
        CHECK_EQ(ambassador.role(), "Ambassador");
        CHECK_EQ(ambassador.coins(),0);
        CHECK_EQ(ambassador1.coins(),10);
        CHECK_NOTHROW(captain.role());
        CHECK_EQ(captain.coins(),0);
        CHECK_EQ(contessa1.coins(),0);
        CHECK_EQ(contessa2.coins(),0);
        CHECK_EQ(captain.role(), "Captain");
        CHECK_NOTHROW(contessa1.role());
        CHECK_EQ(contessa1.role(), "Contessa");
    }
}