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
int mc = new_game1.get_player()->get_move_count();
printf("mc start: %i\n", mc);

new_game1.exit_room(2);
mc = new_game1.get_player()->get_move_count();
printf("mc: %i\n", mc);
new_game1.exit_room(0);
mc = new_game1.get_player()->get_move_count();
printf("mc: %i\n", mc);


/*PARSER HELPER FOR ROOM EXIT*/
Game tph;
//valid exit
tph.exit_current_from_room_id(1);
//invalid exit
tph.exit_current_from_room_id(13);
//invalid room
tph.exit_current_from_room_id(33);



/**/
tph.exit_current_from_room_id(2);
tph.exit_current_from_room_id(3);
tph.exit_current_from_room_id(4);

tph.take(0);
tph.exit_current_from_room_id(3);
tph.exit_current_from_room_id(12);



//*ROOM TESTS*/

Game test_exits;
test_exits.start();
//artifically giving player lamp so player can go through all rooms
test_exits.get_player()->set_has_objects(0, 1);
for (int j = 0; j < NUM_ROOMS; j++){
	//test exit for each room
	for (int i = 0; i < MAX_EXITS; i++){
		test_exits.get_player()->set_current_room(j);
		test_exits.exit_room(i);
		//*TEST ROOM TOGGLE ROOM VISITED FUNCTIONALITY*//
		string rooms_visited = test_exits.get_all_times_rooms_visited();
		printf("%s\n", rooms_visited.c_str());
	}
}
//**TEST TAKE AND INVENTORY AND SAVE/LOAD**/
	Game test_take_drop;
	for (int i = 0; i < NUM_ROOMS; i++){
		test_take_drop.get_player()->set_current_room(i);
		//try to take each object in each room
		for (int j = 0; j < NUM_OBJECTS; j++){
			test_take_drop.take(j);
		}
	}
	//after you have all items in your inventory...
	for (int i = 0; i < NUM_ROOMS; i++){
		test_take_drop.get_player()->set_current_room(i);
		//...try to drop each item in each room and then take it again
		for (int j = 0; j < NUM_OBJECTS; j++){
			test_take_drop.drop(j);
			test_take_drop.take(j);
		}
	}

/*FEATURE TESTS*/
/*OBJECT TESTS*/
/*PLAYER TESTS*/
/*GAME TESTS*/
/*FLOW TESTS*/
	
}