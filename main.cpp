#include <iostream>
#include "Game.h"


using namespace std;
int main(int argc, char *argv[]) {
Game new_game;
/*BUG FIX 1 DEMO*/
//---player cant' take if in tree now//
new_game.run_func(1, -1, 8);
new_game.take(4);
new_game.run_func(1, -1, 8);
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
		//test player event functionality//
		string x = test_exits.get_all_room_events_triggered();
		printf("RET: %s\n", x.c_str());
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
			string x = test_take_drop.get_all_player_objects();
			printf("%s\n", x.c_str());
			
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
	printf("-artificially setting all player objects to have all--");
	int y[]={1, 1, 1, 1, 1, 1, 1, 1};
	test_take_drop.set_all_player_objects(y);
	test_take_drop.inventory();
	printf("-artificially setting all player objects to have non--");
	int x[]={0, 0, 0, 0, 0, 0, 0, 0};
	test_take_drop.set_all_player_objects(x);
	test_take_drop.inventory();
	
	Game test_has_objs;
	test_has_objs.start();
	printf("%s\n", test_has_objs.get_all_room_objects().c_str());
	int set[]={9, 8, 1, 5, 2, 4, 1, 2};
	test_has_objs.set_all_room_objects(set);
	printf("%s\n", test_has_objs.get_all_room_objects().c_str());
 
/*FEATURE TESTS*/

	Game test_feat_verbs;
	string feat_list[] = {"Gravestone", "Tree", "Portrait", "Musicbox", "Mirror", "Carpet", "Faceless", "Table", "Piano", "Trapdoor", "Child", "Dollhouse", "Mother", "Dresser", "Vampire", "Blood", "Mirror", "Sink", "Chest", "Pirate", "Bookshelf", "Fireplace", "Fountain", "Guardian", "Stove", "Cupboard", "Pedestal", "Statue", "Alex", "Demon"};
	string obj_list[]={"Lamp", "Diary", "Locket", "Music", "Dagger", "Doll", "Key", "Chalice"};
	string verb_list[]={STR_VERB1, STR_VERB2, STR_VERB3, STR_VERB4, STR_VERB5, STR_VERB6, STR_VERB7, STR_VERB8, STR_VERB9, STR_VERB10};
	//string verb_list[]={STR_VERB1, STR_VERB2, STR_VERB3, STR_VERB}
	test_feat_verbs.start();
	//test feat_valid
//	int xy = test_feat_verbs.feat_valid(0);
//	printf("%i::", xy);
//	xy = test_feat_verbs.feat_valid(1);
//		printf("%i::", xy);
//		xy = test_feat_verbs.feat_valid(2);
//			printf("%i::", xy);
	
	
	
	
	//string obj_list[]=
	//for each room
	for (int i = 0; i < NUM_ROOMS; i++)
	{
		test_feat_verbs.get_player()->set_current_room(i);
		//try to run it with the FEATURE
		for (int j=0; j < TOTAL_FIXED; j++){
			//try to run each FEATURE with each OBJECT
			for (int k=0; k < NUM_OBJECTS; k++)
			{
				//try to run each VERB with each MIXTURE of FEATURE and OBJECT
				for (int l=0; l < NUM_VERB_FUNCS; l++){
					test_feat_verbs.run_func(j, k, l);
				}
			}
		}
		//try to run it with OBJECT
		for (int x=0; x < NUM_OBJECTS; x++)
		{
			//try to run each VERB with OBJECT
			for (int m=0; m < NUM_VERB_FUNCS; m++){
				test_feat_verbs.run_func(-1, x, m);
			}
		}
	}	
	

		//printf("%s", g.c_str());
/*OBJECT TESTS*/
/*PLAYER TESTS*/
/*GAME TESTS*/
/*FLOW TESTS*/
	
}