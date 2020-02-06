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

/*BUG FIX 2 DEMO*/
//--- player move count is only incremented if exit is valid--/ 
Game new_game1;
new_game1.start();
int mc = new_game1.player1.get_move_count();
printf("mc start: %i\n", mc);

new_game1.exit_room(2);
mc = new_game1.player1.get_move_count();
printf("mc: %i\n", mc);
new_game1.exit_room(0);
mc = new_game1.player1.get_move_count();
printf("mc: %i\n", mc);
/*ROOM TESTS*/

/*FEATURE TESTS*/
/*OBJECT TESTS*/
/*PLAYER TESTS*/
/*GAME TESTS*/
/*FLOW TESTS*/
	
}