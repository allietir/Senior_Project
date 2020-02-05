#include <iostream>
#include "Game.h"


using namespace std;
int main(int argc, char *argv[]) {
Game new_game;
/*BUG FIX 1 DEMO*/
//---player cant' take if in tree now//
new_game.run_func("Tree", "none", "climb");
new_game.take(4);
new_game.run_func("Tree", "none", "climb");
new_game.take(4);

/*ROOM TESTS*/

/*FEATURE TESTS*/
/*OBJECT TESTS*/
/*PLAYER TESTS*/
/*GAME TESTS*/
/*FLOW TESTS*/
	
}