#include <iostream>
#include "Game.h"
//#include "globals.h"
#include "parser.h"
#include "savesystem.h"
using namespace std;
void convert_string_to_array(int* arr, string str);
int main(int argc, char *argv[]) {
//Game new_game;
//
///*BUG FIX 1 DEMO*/
////---player cant' take if in tree now//
//new_game.run_func(1, -1, 8);
//new_game.take(4);
//new_game.run_func(1, -1, 8);
//new_game.take(4);
//
///*BUG FIX 2 DEMO*/
////--- player move count is only incremented if exit is valid--/ 
//Game new_game1;
//new_game1.start();
//int mc = new_game1.get_player()->get_move_count();
//printf("mc start: %i\n", mc);
//
//new_game1.exit_room(2);
//mc = new_game1.get_player()->get_move_count();
//printf("mc: %i\n", mc);
//new_game1.exit_room(0);
//mc = new_game1.get_player()->get_move_count();
//printf("mc: %i\n", mc);
//
//
///*PARSER HELPER FOR ROOM EXIT*/
//Game tph;
////valid exit
//tph.exit_current_from_room_id(1);
////invalid exit
//tph.exit_current_from_room_id(13);
////invalid room
//tph.exit_current_from_room_id(33);
//
//
//
///**/
//tph.exit_current_from_room_id(2);
//tph.exit_current_from_room_id(3);
//tph.exit_current_from_room_id(4);
//
//tph.take(0);
//tph.exit_current_from_room_id(3);
//tph.exit_current_from_room_id(12);
//
//
//
////*ROOM TESTS*/
//
//Game test_exits;
//test_exits.start();
////artifically giving player lamp so player can go through all rooms
//test_exits.get_player()->set_has_objects(0, 1);
//for (int j = 0; j < NUM_ROOMS; j++){
//	//test exit for each room
//	for (int i = 0; i < MAX_EXITS; i++){
//		test_exits.get_player()->set_current_room(j);
//		//test player event functionality//
//		string x = test_exits.get_all_room_events_triggered();
//		printf("RET: %s\n", x.c_str());
//		test_exits.exit_room(i);
//		//*TEST ROOM TOGGLE ROOM VISITED FUNCTIONALITY*//
//		string rooms_visited = test_exits.get_all_times_rooms_visited();
//		printf("%s\n", rooms_visited.c_str());
//	}
//}
////**TEST TAKE AND INVENTORY AND SAVE/LOAD**/
//	Game test_take_drop;
//	for (int i = 0; i < NUM_ROOMS; i++){
//		test_take_drop.get_player()->set_current_room(i);
//		//try to take each object in each room
//		for (int j = 0; j < NUM_OBJECTS; j++){
//			test_take_drop.take(j);
//			string x = test_take_drop.get_all_player_objects();
//			printf("%s\n", x.c_str());
//			
//		}
//	}
//	//after you have all items in your inventory...
//	for (int i = 0; i < NUM_ROOMS; i++){
//		test_take_drop.get_player()->set_current_room(i);
//		//...try to drop each item in each room and then take it again
//		for (int j = 0; j < NUM_OBJECTS; j++){
//			test_take_drop.drop(j);
//			test_take_drop.take(j);
//		}
//	}
//	printf("-artificially setting all player objects to have all--");
//	int y[]={1, 1, 1, 1, 1, 1, 1, 1};
//	test_take_drop.set_all_player_objects(y);
//	test_take_drop.inventory();
//	printf("-artificially setting all player objects to have non--");
//	int x[]={0, 0, 0, 0, 0, 0, 0, 0};
//	test_take_drop.set_all_player_objects(x);
//	test_take_drop.inventory();
//	
//	Game test_has_objs;
//	test_has_objs.start();
//	printf("%s\n", test_has_objs.get_all_room_objects().c_str());
//	int set[]={9, 8, 1, 5, 2, 4, 1, 2};
//	test_has_objs.set_all_room_objects(set);
//	printf("%s\n", test_has_objs.get_all_room_objects().c_str());
// 
///*FEATURE TESTS*/
//
//	Game test_feat_verbs;
//	string feat_list[] = {"Gravestone", "Tree", "Portrait", "Musicbox", "Mirror", "Carpet", "Faceless", "Table", "Piano", "Trapdoor", "Child", "Dollhouse", "Mother", "Dresser", "Vampire", "Blood", "Mirror", "Sink", "Chest", "Pirate", "Bookshelf", "Fireplace", "Fountain", "Guardian", "Stove", "Cupboard", "Pedestal", "Statue", "Alex", "Demon"};
//	string obj_list[]={"Lamp", "Diary", "Locket", "Music", "Dagger", "Doll", "Key", "Chalice"};
//	string verb_list[]={STR_VERB1, STR_VERB2, STR_VERB3, STR_VERB4, STR_VERB5, STR_VERB6, STR_VERB7, STR_VERB8, STR_VERB9, STR_VERB10};
//	//string verb_list[]={STR_VERB1, STR_VERB2, STR_VERB3, STR_VERB}
//	test_feat_verbs.start();
//	//test feat_valid
////	int xy = test_feat_verbs.feat_valid(0);
////	printf("%i::", xy);
////	xy = test_feat_verbs.feat_valid(1);
////		printf("%i::", xy);
////		xy = test_feat_verbs.feat_valid(2);
////			printf("%i::", xy);
//	
//	
//	
//	
//	//string obj_list[]=
//	//for each room
//	for (int i = 0; i < NUM_ROOMS; i++)
//	{
//		test_feat_verbs.get_player()->set_current_room(i);
//		//try to run it with the FEATURE
//		for (int j=0; j < TOTAL_FIXED; j++){
//			//try to run each FEATURE with each OBJECT
//			for (int k=0; k < NUM_OBJECTS; k++)
//			{
//				//try to run each VERB with each MIXTURE of FEATURE and OBJECT
//				for (int l=0; l < RUN_FUNC_VERBS; l++){
//					test_feat_verbs.run_func(j, k, l);
//				}
//			}
//		}
//		//try to run it with OBJECT
//		for (int x=0; x < NUM_OBJECTS; x++)
//		{
//			//try to run each VERB with OBJECT
//			for (int m=0; m < RUN_FUNC_VERBS; m++){
//				test_feat_verbs.run_func(-1, x, m);
//			}
//		}
//	}	
//	//run take through the func
//	for (int i = 0; i < NUM_ROOMS; i++)
//	{
//		test_feat_verbs.get_player()->set_current_room(i);
//		//try to run it with the FEATURE
//		for (int j=0; j < TOTAL_FIXED; j++){
//			//try to run each FEATURE with each OBJECT
//			for (int k=0; k < NUM_OBJECTS; k++)
//			{
//				//try to run each VERB with each MIXTURE of FEATURE and OBJECT
//				for (int l=0; l < RUN_FUNC_VERBS; l++){
//					test_feat_verbs.run_func(j, k, l);
//				}
//			}
//		}
//		//try to run it with OBJECT
//		for (int x=0; x < NUM_OBJECTS; x++)
//		{
//			test_feat_verbs.run_func(-1, x, 11);
//			test_feat_verbs.inventory();
//		}
//	
//	}
//	
//		//printf("%s", g.c_str());
/////*OBJECT TESTS*/
/////*PLAYER TESTS*/
/////*GAME TESTS*/
/////*FLOW TESTS*/
////
/////*PARSER TESTS*/
////
//
//	
//	
//	Game explore_rooms;
//	
//	explore_rooms.start();
//	explore_rooms.get_room_x(0)->get_feature_x(0)->get_name();
//
//	explore_rooms.output_room_list();
//	for (int i = 0; i < NUM_ROOMS; i++){
//		explore_rooms.get_player()->set_current_room(i);
//		printf("---------------ROOM %s-------------\n", explore_rooms.get_room_x(i)->get_name().c_str());
//		for (int j = 0; j < RUN_FUNC_VERBS; j++){
//			
//			//get room id
//			//run both features with all the verbs
//			int room_id_zero = explore_rooms.get_room_x(i)->get_feature_x(0)->get_index_id();
//			int room_id_one = explore_rooms.get_room_x(i)->get_feature_x(1)->get_index_id();
//			explore_rooms.run_func(room_id_zero, -1, j);
//			explore_rooms.run_func(room_id_one, -1, j);
//		}
//		
//		
//	}
//
//	/*TESTS FOR GETTER SETTERS*/
//	Game get_set;
//	get_set.start();
//	string a = get_set.get_all_room_objects();
//	string b = get_set.get_all_player_objects();
//	string c = get_set.get_all_times_rooms_visited();
//	string d = get_set.get_all_game_events_triggered();
//	string e = get_set.get_all_room_events_triggered();
//	printf("%s\n", a.c_str());
//	printf("%s\n", b.c_str());
//	printf("%s\n", c.c_str());
//	printf("%s\n", d.c_str());
//	printf("%s\n", e.c_str());



/*ALLIE SAVESYSTEM*/

//		new_game.start();
//		save_game(new_game);
//		load_game(new_game);
//		save_game(new_game);	

//	
//	Game parse_test;
//	parse_test.start();
//	string userInput = ""; 
//		while (1) {
//			cout << "what would you like to do: \n";
//			getline(cin, userInput);
//			inputParsing(parse_test, userInput);
//		}
		
//		Game get_things;
//		get_things.output_obj_list();
		
//		Game test_desc_change;
//		test_desc_change.start();
//		test_desc_change.look();
//		test_desc_change.take(4);
//		test_desc_change.look();
//		test_desc_change.drop(4);
//		test_desc_change.look();
		
		 /*
		Game test_event_trigger;
		test_event_trigger.get_player()->set_current_room(BASEMENT);
		//give player the chalice
		test_event_trigger.get_player()->set_has_objects(CHALICE, 1);
		
		
		test_event_trigger.inventory();
		//try to exit before
		test_event_trigger.exit_current_from_room_id(CRYPT);
		
		test_event_trigger.run_func(PEDESTAL, CHALICE, USE);
		//try to exit after
		test_event_trigger.exit_current_from_room_id(CRYPT);
		
		
		Game locket_test;
		locket_test.get_player()->set_current_room(NURSURY);
		locket_test.get_player()->set_has_objects(DOLL, 1);
		locket_test.run_func(CHILD, DOLL, GIVE);
		locket_test.run_func(-1, LOCKET, 11);
		locket_test.run_func(-1, DOLL, 11);
		//now try to open the locket in a room other than the crypt.
		locket_test.run_func(-1, LOCKET, OPEN);
		locket_test.get_player()->set_current_room(CRYPT);
		locket_test.run_func(-1, LOCKET, OPEN);//triggers capturing demon
		
		printf("\n========================================================================\\n");
		Game chest_test;
		//give player key
		chest_test.get_player()->set_has_objects(KEY, 1);
		//try look
		chest_test.run_func(CHEST, -1, 10);
		//put player in attic
		printf("setting current room to be attic\n");
		chest_test.get_player()->set_current_room(ATTIC);
		//try look
		chest_test.run_func(CHEST, -1, 10);
		chest_test.run_func(CHEST, KEY, OPEN);
		//try look
		chest_test.run_func(CHEST, -1, 10);
		chest_test.run_func(-1, DOLL, 11);
		chest_test.run_func(CHEST, -1, 10);
		
		Game test_piano;
		test_piano.get_player()->set_current_room(PARLOR);
		test_piano.get_player()->set_has_objects(MUSIC, 1);
		test_piano.run_func(PIANO, -1, PLAY);
		test_piano.run_func(PIANO, MUSIC, USE);
		test_piano.run_func(PIANO, -1, PLAY);
		
		Game test_burn;
		test_burn.get_player()->set_current_room(KITCHEN);
		test_burn.get_player()->set_has_objects(DIARY, 1);
		test_burn.drop(DIARY);
		test_burn.take(DIARY);
		test_burn.drop(DIARY);
		test_burn.run_func(STOVE, DIARY, USE);
		test_burn.take(DIARY);
		*/
	
//		Game sink_test;
//		sink_test.get_player()->set_current_room(BATHROOM);
//		sink_test.run_func(SINK, -1, LOOK);
//		sink_test.run_func(SINK, -1, USE);
//		sink_test.run_func(SINK, -1, LOOK);
//		sink_test.run_func(SINK, -1, USE);
//		
//		sink_test.run_func(SINK, -1, SMELL);
//		sink_test.run_func(SINK, -1, EAT);
//		Game test_desc;
//		test_desc.print_all_feature_desc();

		Game blood_test;
		blood_test.get_player()->set_current_room(MASTER);
		blood_test.run_func(VAMPIRE, CHALICE, GIVE);
		blood_test.get_player()->set_current_room(BATHROOM);
		blood_test.get_player()->set_has_objects(CHALICE, 1);
		blood_test.run_func(SINK, CHALICE, USE);	
		blood_test.get_player()->set_current_room(MASTER);
		blood_test.run_func(VAMPIRE, CHALICE, GIVE);
		

}
	
	
