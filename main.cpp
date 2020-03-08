#include <iostream>
#include <cstring>
#include "Game.h"
//#include "globals.h"
#include "parser.h"
#include "savesystem.h"
#include "wordwrap.h"

using namespace std;
void convert_string_to_array(int* arr, string str);
int main(int argc, char *argv[]) {

	string wrap_one = 	"The tree shakes and suddenly the face of the tree comes alive. "
						"You see a face more old and ancient and angry than any human could ever be, and in that moment you realize you have made an enormous error. "
						"That's the last thought you have before the tree swallows you whole. "
						"Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. "
						"Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.\n";

	string wrap_two = 	"The smell of apple pie wafts pleasently under your nose, but you don't see any pie. However, as your eyes adjust from the dark, you smell an undertone of rot and decay. "
						"Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. "
						"Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.\n";

	printf("%s", word_wrap(wrap_one.c_str(), 80).c_str());

	printf("%s",word_wrap(wrap_two.c_str(), 80).c_str());
	
	
	

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
		
		*/

/*
		Game locket_test;
		locket_test.get_player()->set_current_room(NURSERY);
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
		

		Game test_burn;
		test_burn.get_player()->set_current_room(KITCHEN);
		test_burn.get_player()->set_has_objects(DIARY, 1);
		test_burn.drop(DIARY);
		test_burn.take(DIARY);
		test_burn.drop(DIARY);
		test_burn.run_func(STOVE, DIARY, USE);
		test_burn.take(DIARY);
		
	
		Game sink_test;
		sink_test.get_player()->set_current_room(BATHROOM);
		sink_test.run_func(SINK, -1, LOOK);
		sink_test.run_func(SINK, -1, USE);
		sink_test.run_func(SINK, -1, LOOK);
		sink_test.run_func(SINK, -1, USE);
		
		sink_test.run_func(SINK, -1, SMELL);
		sink_test.run_func(SINK, -1, EAT);


	
	
		//now try to open the locket in a room other than the crypt.

		Game fam_test;
		fam_test.get_player()->set_current_room(PARLOR);
		fam_test.get_player()->set_has_objects(MUSIC, 1);
		fam_test.run_func(PAINTING, -1, LOOK);
		fam_test.run_func(PIANO, -1, PLAY);
		fam_test.run_func(PIANO, MUSIC, USE);
		fam_test.run_func(PIANO, -1, PLAY);
		fam_test.run_func(PAINTING, -1, LOOK);
		fam_test.run_func(PAINTING, -1, SPEAK);
		
		//21, 13, 15

		//give player key
		fam_test.get_player()->set_has_objects(KEY, 1);
		//try look
		fam_test.run_func(CHEST, -1, 10);
		//put player in attic
		printf("setting current room to be attic\n");
		fam_test.get_player()->set_current_room(ATTIC);
		//try look
		fam_test.run_func(CHEST, -1, 10);
		fam_test.run_func(CHEST, KEY, OPEN);
		//try look
		fam_test.run_func(CHEST, -1, 10);
		fam_test.run_func(-1, DOLL, 11);
		fam_test.run_func(CHEST, -1, 10);
		
		
		fam_test.get_player()->set_current_room(NURSERY);
		

		fam_test.run_func(CHILD, DOLL, GIVE);
		fam_test.run_func(-1, LOCKET, TAKE);

		
		
		fam_test.get_player()->set_current_room(MASTER);
		fam_test.run_func(VAMPIRE, CHALICE, GIVE);
		fam_test.get_player()->set_current_room(BATHROOM);
		fam_test.get_player()->set_has_objects(CHALICE, 1);
		fam_test.run_func(SINK, CHALICE, USE);	
		fam_test.get_player()->set_current_room(MASTER);
		fam_test.run_func(VAMPIRE, CHALICE, GIVE);
		
		Game test_is_locked;
		printf("%s\n", test_is_locked.get_all_is_locked().c_str());
		int x[8]={1, 0, 1, 1, 1, 0, 0, 1};
		test_is_locked.set_all_is_locked(x);
		printf("%s\n", test_is_locked.get_all_is_locked().c_str());

		*/
		


		/*TEST ALL EVENTS*/	
//		printf("=================START: ALL INITIAL FEATURE DESCRIPTIONS=========\n");
//		Game test_desc;
//		test_desc.print_all_feature_desc();		
//		printf("=================END : ALL INITIAL FEATURE DESCRIPTIONS=========\n");
//		/*TEST ALL EVENTS*/	
//		printf("======START: TEST ALL EVENTS========\n");
//		Game test_events;
//		for (int i = 0; i < NUM_ROOMS; i++){
//			for (int j = 0; j < test_events.get_room_x(i)->get_num_events(); j++){
//				printf("ROOM %i EVENT %i of %i:", i+1, j+1, test_events.get_room_x(i)->get_num_events());
//				test_events.get_room_x(i)->trigger_event(j);
//
//			}
//		}
//		printf("======END: TEST ALL EVENTS========\n");
		
//		
//				Game parse_test;
//				parse_test.start();
//				string userInput = ""; 
//					while (1) {
//						cout << "what would you like to do: \n";
//						getline(cin, userInput);
//						inputParsing(parse_test, userInput);
//					}

//
//		Game burn_test;
//		burn_test.get_player()->set_current_room(KITCHEN);
//		burn_test.get_player()->set_has_objects(0, 1);
//		burn_test.get_player()->set_has_objects(1, 1);
//		burn_test.get_player()->set_has_objects(2, 1);
//		burn_test.run_func(STOVE, 0, USE);
//		burn_test.run_func(STOVE, 1, USE);
//		burn_test.run_func(STOVE, 2, USE);
		
//		printf("==================testing take / drop====================\n");
//			Game test_take_drop;
//			int ba[]={0,0,0,0,0,0,0,0};
//			test_take_drop.set_all_is_locked(ba);
//			for (int i = 0; i < NUM_ROOMS; i++){
//				test_take_drop.get_player()->set_current_room(i);
//				//try to take each object in each room
//				for (int j = 0; j < NUM_OBJECTS; j++){
//					test_take_drop.take(j);
//					string x = test_take_drop.get_all_player_objects();
//					printf("%s\n", x.c_str());
//					
//				}
//			}
//			//after you have all items in your inventory...
//			for (int i = 0; i < NUM_ROOMS; i++){
//				test_take_drop.get_player()->set_current_room(i);
//				//...try to drop each item in each room and then take it again
//				for (int j = 0; j < NUM_OBJECTS; j++){
//					test_take_drop.drop(j);
////					test_take_drop.take(j);
//				}
//			}
//			printf("================FINISHED TESTING DROP/TAKE==========\n");
			
//		Game crypt_test;
//		crypt_test.get_player()->set_current_room(CRYPT);
//		int has_objs[]={1, 1, 1, 1, 1, 1, 1, 1};
//		crypt_test.set_player_has_all_objects(has_objs);
//		crypt_test.look();
//		crypt_test.look();
//		printf("-----------then------------\n");
//		crypt_test.run_func(DEMON, -1, LOOK);
//		crypt_test.run_func(ALEX, -1, LOOK);
//		crypt_test.run_func(DEMON, -1, SPEAK);
//		
//		Game mother_test;
//		mother_test.get_player()->set_current_room(GUEST);
//		mother_test.run_func(DRESSER, DAGGER, ATTACK);
//		mother_test.run_func(-1, MUSIC, TAKE);
//		mother_test.get_player()->set_has_objects(DAGGER, 1);
//
//		mother_test.look();
//		printf("--------------ABOUT TO ATTACK WITH DAGGER------------");
//		mother_test.run_func(DRESSER, DAGGER, ATTACK);
//		printf("--------------AFTER ATTACK WITH DAGGER------------");
//		mother_test.run_func(MOTHER, -1, SPEAK);
//		mother_test.look();
//		
//		Game cupboard_test;
//		cupboard_test.get_player()->set_current_room(KITCHEN);
//		cupboard_test.run_func(CUPBOARD, DIARY, USE);		
//		cupboard_test.run_func(CUPBOARD, -1, LOOK);
//		cupboard_test.take(LAMP);
//	    cupboard_test.look();
//		
//		Game clock_test;
//		int has_objs[]={1, 1, 1, 1, 1, 1, 1, 1};
//		clock_test.set_player_has_all_objects(has_objs);
//		clock_test.get_player()->set_current_room(UPSTAIRS);
////		clock_test.get_room_x(UPSTAIRS)->get_feature_x(0)->set_time(2);
//		string x = clock_test.get_room_x(UPSTAIRS)->get_feature_x(0)->get_time_str();
//		printf("===========%s", x.c_str());
//		clock_test.run_func(CLOCK, -1, LOOK);
//		clock_test.exit_room(1);
//		clock_test.exit_room(0);
//		clock_test.run_func(CLOCK, -1, LOOK);
//		clock_test.run_func(CLOCK, -1, LOOK);
//		clock_test.exit_room(1);
//		clock_test.exit_room(0);
//		clock_test.run_func(CLOCK, -1, LOOK);
//		clock_test.run_func(CLOCK, -1, READ);
//		clock_test.run_func(CLOCK, -1, SPEAK);
//		clock_test.run_func(CLOCK, DAGGER, USE);
//		clock_test.run_func(CLOCK, -1, OPEN);
//		clock_test.run_func(CLOCK, -1, CLIMB);
//		
//		Game book_test;
//		book_test.get_player()->set_current_room(LIBRARY);
//		int has_objs[]={1, 1, 1, 1, 1, 1, 1, 1};
//		
//		book_test.set_player_has_all_objects(has_objs);
//	//	book_test.run_func(-1, DIARY, READ);
//		book_test.run_func(BOOKSHELF, DIARY, USE);
//		book_test.run_func(BOOKSHELF, -1, SPEAK);
//		book_test.run_func(BOOKSHELF, -1, READ);
//		book_test.run_func(BOOKSHELF, -1, SPEAK);
//		book_test.run_func(BOOKSHELF, -1, READ);		
//		book_test.run_func(BOOKSHELF, -1, SPEAK);
//		book_test.run_func(BOOKSHELF, -1, READ);
//		book_test.run_func(-1, DIARY, READ);
//		book_test.drop(DAGGER);
//		book_test.run_func(-1, DIARY, READ);
//		
//		
//		Game midnight_test;
//		midnight_test.get_player()->set_move_count(14);
//		midnight_test.get_player()->set_current_room(PARLOR);
//		midnight_test.exit_room(2);
//		
//		
//		Game lamp_test;
//		lamp_test.get_player()->set_has_objects(LAMP, 1);
//		lamp_test.get_player()->set_current_room(ENTRANCEWAY);
//		lamp_test.exit_room(0);
//		printf("\n////////////////////////////////\n");
//		lamp_test.run_func(-1, LAMP, USE);
//		printf("\n////////////////////////////////\n");
//		lamp_test.exit_room(0);
//		lamp_test.exit_room(1);
//		lamp_test.exit_room(0);
		
		
//		Game blood_test;
//		int has_objs[]={1, 1, 1, 1, 1, 1, 1, 1};
//		blood_test.set_player_has_all_objects(has_objs);
//		blood_test.get_player()->set_current_room(BATHROOM);
//		blood_test.run_func(SINK, CHALICE, USE);
//		blood_test.get_player()->set_current_room(MASTER);
//		blood_test.run_func(VAMPIRE, CHALICE, GIVE);
//		blood_test.run_func(VAMPIRE, CHALICE, GIVE);
//		blood_test.get_player()->set_current_room(CONSERVATORY);
//		blood_test.run_func(FOUNTAIN, CHALICE, USE);
//		blood_test.run_func(FOUNTAIN, -1, EAT);
//		blood_test.run_func(FOUNTAIN, -1, EAT);
//		blood_test.get_player()->set_current_room(CONSERVATORY);
//		blood_test.run_func(FOUNTAIN, CHALICE, USE);
//		blood_test.get_player()->set_current_room(CRYPT);
//		blood_test.run_func(DEMON, CHALICE, GIVE);
//		blood_test.get_player()->set_current_room(CONSERVATORY);
//		blood_test.run_func(FOUNTAIN, CHALICE, USE);
//		blood_test.get_player()->set_current_room(CRYPT);
//		blood_test.run_func(DEMON, CHALICE, GIVE);
		
		
//		Game doll_test;
//		int has_objs[]={1, 1, 1, 1, 1, 1, 1, 1};
//		doll_test.set_player_has_all_objects(has_objs);
//		doll_test.get_player()->set_current_room(UPSTAIRS);
//		doll_test.look();
//		doll_test.get_player()->set_current_room(NURSERY);
//		doll_test.run_func(DOLLHOUSE, DOLL, USE);
//		doll_test.run_func(DOLLHOUSE, DOLL, USE);
//		doll_test.run_func(DOLLHOUSE, DOLL, USE);
//		doll_test.run_func(DOLLHOUSE, DOLL, USE);
//		doll_test.run_func(DOLLHOUSE, DOLL, USE);
//		doll_test.run_func(DOLLHOUSE, DOLL, USE);
//		doll_test.run_func(DOLLHOUSE, DOLL, USE);
//		doll_test.run_func(DOLLHOUSE, DOLL, USE);
//		doll_test.get_player()->set_current_room(UPSTAIRS);
//		doll_test.look();
//		doll_test.get_player()->set_current_room(NURSERY);
//		doll_test.run_func(DOLLHOUSE, DOLL, USE);
//		
//		doll_test.get_player()->set_current_room(UPSTAIRS);
//		doll_test.look();

//		Game mirror_test;
//		int has_objs[]={1, 1, 1, 1, 1, 1, 1, 1};
//		mirror_test.set_player_has_all_objects(has_objs);
//		mirror_test.get_player()->set_current_room(BATHROOM);
//		mirror_test.run_func(SINK, CHALICE, USE);
//		mirror_test.run_func(-1, MIRROR, SPEAK);
//		mirror_test.run_func(SINK, CHALICE, USE);
//		mirror_test.run_func(-1, MUSIC, PLAY);
//		mirror_test.run_func(-1, MIRROR, SPEAK);
//		mirror_test.run_func(-1, DAGGER, USE);
//		mirror_test.run_func(-1, MIRROR, SPEAK);
//		mirror_test.run_func(SINK, CHALICE, USE);
		
//		Game chalice_fire_test;
//		int has_objs[]={1, 1, 1, 1, 1, 1, 1, 1};
//		chalice_fire_test.set_player_has_all_objects(has_objs);
//		chalice_fire_test.get_player()->set_current_room(LIBRARY);
//		chalice_fire_test.run_func(FIREPLACE, -1, USE);
//		chalice_fire_test.run_func(FIREPLACE, DIARY, USE);
//		chalice_fire_test.run_func(FIREPLACE, -1, SPEAK);
//		chalice_fire_test.run_func(FIREPLACE, CHALICE, USE);
//		chalice_fire_test.get_player()->set_current_room(UPSTAIRS);
//		chalice_fire_test.run_func(CARPET, -1, READ);
//		chalice_fire_test.run_func(CARPET, CHALICE, USE);
//		chalice_fire_test.run_func(CARPET, -1, READ);
		
//		Game alex_test;
//		int has_objs[]={1, 1, 1, 1, 1, 1, 1, 1};
//		alex_test.set_player_has_all_objects(has_objs);
//		alex_test.get_player()->set_current_room(CRYPT);
//		for (int i = 0; i < NUM_OBJECTS; i++){
//			alex_test.run_func(ALEX, i, GIVE);
//			alex_test.run_func(ALEX, 3, GIVE);
//		}
		
//		Game statue_test;
//		int has_objs[]={1, 1, 1, 1, 1, 1, 1, 1};
//		statue_test.set_player_has_all_objects(has_objs);
//		statue_test.get_player()->set_current_room(BASEMENT);
//		statue_test.run_func(STATUE, DIARY, USE);
//		statue_test.run_func(STATUE, -1, SPEAK);
//		statue_test.run_func(STATUE, -1, SPEAK);
//		statue_test.run_func(STATUE, -1, SPEAK);
//		statue_test.run_func(STATUE, -1, SPEAK);
		
//		/*START ALLIE SAVESYSTEM TESTS*/
//
//			int success = 0;
//			int total = 0;
//
//			Game test_take_drop;
//
//			test_take_drop.start();
//
//			int ba[]={0,0,0,0,0,0,0,0};
//			test_take_drop.set_all_is_locked(ba);
//
//			//Run the save_load_test for the player in each room and before any action is taken
//			for (int i = 0; i < NUM_ROOMS; i++) {
//				
//				test_take_drop.get_player()->set_current_room(i);
//
//				if (save_load_test(test_take_drop) == true) 
//				{
//					printf("save_load_test = SUCCESS\n");
//					success++;
//				}
//				else
//				{
//					printf("save_load_test = FAIL\n");
//				}
//				total++;
//			}
//
//			for (int i = 0; i < NUM_ROOMS; i++){
//
//				test_take_drop.get_player()->set_current_room(i);
//
//				//try to take each object in each room
//				for (int j = 0; j < NUM_OBJECTS; j++){
//					test_take_drop.take(j);
//					string x = test_take_drop.get_all_player_objects();
//					printf("all player object: %s\n", x.c_str());
//
//					//Run the save_load_test for each of these single actions
//					if (save_load_test(test_take_drop) == true) 
//					{
//						printf("save_load_test = SUCCESS\n");
//						success++;
//					}
//					else
//					{
//						printf("save_load_test = FAIL\n");
//					}
//					total++;
//
//				}
//			}
//
//			//Test dropping and picking up items in each room
//			//after you have all items in your inventory
//			for (int i = 0; i < NUM_ROOMS; i++){
//
//				test_take_drop.get_player()->set_current_room(i);
//
//				//try to drop each item in room 
//				for (int j = 0; j < NUM_OBJECTS; j++){
//					test_take_drop.drop(j);
//
//					//Run the save_load_test for each of these single actions
//					if (save_load_test(test_take_drop) == true) 
//					{
//						printf("save_load_test = SUCCESS\n");
//						success++;
//					}
//					else
//					{
//						printf("save_load_test = FAIL\n");
//					}
//					total++;
//
//				}
//
//				//try to take each item in the room
//				for (int k = 0; k < NUM_OBJECTS; k++){
//					test_take_drop.take(k);
//
//					//Run the save_load_test for each of these single actions
//					if (save_load_test(test_take_drop) == true) 
//					{
//						printf("save_load_test = SUCCESS\n");
//						success++;
//					}
//					else
//					{
//						printf("save_load_test = FAIL\n");
//					}
//					total++;
//
//				}
//			}
//
//			//print overall results
//			printf("\nsave_load_test report: %d out of %d tests passed", success, total);
//
//			//new_game.start();
//			//save_game(new_game);
//			//load_game(new_game);
//
//		/*END ALLIE SAVESYSTEM TESTS*/	
		
		
		Game parse_test;
		//using https://stackoverflow.com/questions/19485536/redirect-output-of-an-function-printing-to-console-to-string/19499003
		char buffer[1024];
		memset(buffer, '\0', 1024);
		FILE *fp;
		fp = fmemopen(buffer, 1024, "w");
		if ( !fp ) { std::printf("error"); 
		
		return 0; }

		auto old = stdout;
		stdout = fp;

		parse_test.start();
		
		fclose(fp);
		stdout = old; //reset
		
		string strbuff = buffer; 
		
		printf("%s",word_wrap(buffer, MAX_WIDTH).c_str());
		char userInput[100] = {'\0'}; 
		int x=0;
		int y_flag = 0;
		while (x==0) {
			
			if (y_flag == 0){
				printf("What would you like to do?\n");
			}
			
				

				

				
		
			cin.getline(userInput, 100);
			//cin.ignore(2, '\n');
			
			//printf("got %s", userInput);
			if (userInput[0]=='\0'){
				//cout << "Nothing was entered\n";
				y_flag = 1;
				cin.clear();
				cin.ignore(1000000000000, '\n');
				memset(userInput, '\0', 100);
			
			}
			else if (strcmp("go", userInput)==0){
				printf("Where do you want to go?\n");
				y_flag = 1;
			}
			else{
				y_flag = 0;
				
				//using https://stackoverflow.com/questions/19485536/redirect-output-of-an-function-printing-to-console-to-string/19499003
				char buffer[1024]={'\0'};
				FILE *fp = fmemopen(buffer, 1023, "w");
				if ( !fp ) { std::printf("the error"); return 0; }
				printf("STDOUT: %i", stdout);
				FILE *old = stdout;
				stdout = fp;
				fflush(stdout);
				
				inputParsing(parse_test, userInput);
				
				fclose(fp);
				stdout = old; //reset
				
				string strbuff = buffer; 
				
				printf("HERE:::%s",word_wrap(strbuff.c_str(), 80).c_str());
				//printf(word_wrap(strbuff, 80));
				
			}
 
		}
	
	/*TEST EVERY VERB WITH EVERY FEATURE AND EVERY OBJECT IN EVERY ROOM*/
//	Game rf_test;
//	int num_fails=0;
//	int num_passes=0;
//	
//	for (int i = 0; i < NUM_ROOMS; i++)
//	{	printf("TESTING IN ROOM %s\n", rf_test.get_room_x(rf_test.get_player()->get_current_room())->get_name().c_str());
//		int x[8]={0, 0, 0, 0, 0, 0, 0, 0};
//		rf_test.set_all_is_locked(x);
//		rf_test.get_player()->set_current_room(i);
//		for (int k = -1; k < TOTAL_FIXED; k++)
//		{
//			for (int j= -1; j < NUM_OBJECTS; j++)
//			{
//				for (int x=0; x < RUN_FUNC_VERBS; x++)
//				{
//					printf("TEST: %i, %i, %i, %i\n", i, k, j, x);
//					if (x==TAKE){
//						printf("------------RUNNING TAKE---------\n");
//					}
//					rf_test.run_func(k, j, x);
//				}
//			}
//		}
//		
//	}	
//	/*check that all take events triggered*/
//	int obj_first_take_test=0; 
//	for (int i = 0; i < NUM_OBJECTS; i++){
//		
//		int check_room = rf_test.get_obj_starts_in(i);
//		if (rf_test.get_room_x(check_room)->get_event_triggered(0)==1)
//		{
//			printf("%s was taken\n", rf_test.get_object_x(i)->get_name().c_str()); 
//			obj_first_take_test++;
//		}
//		if (rf_test.get_room_x(check_room)->get_event_triggered(0)==0)
//		{
//			printf("%s was not taken\n", rf_test.get_object_x(i)->get_name().c_str()); 
//			
//		}
//	}
//	//all objects but doll, locked and chalice should be taken. 
//	if (obj_first_take_test==8){
//		printf("-----PASS-----\n");
//		num_passes++;
//	}
//	else{
//		printf("-----FAIL----\n");
//		printf("took %i", obj_first_take_test);
//		num_fails++;
//	}
//	
//	
//	Game rf1_test;
//	//only test locking take
//	for (int i = 0; i < NUM_ROOMS; i++)
//	{	
//		printf("TESTING IN ROOM %s", rf1_test.get_room_x(rf1_test.get_player()->get_current_room())->get_name().c_str());
//		int y[8]={1, 1, 1, 1, 1, 1, 1, 1};
//		rf1_test.set_all_is_locked(y);
//		
//		for (int k = -1; k < TOTAL_FIXED; k++)
//		{
//			for (int j= -1; j < NUM_OBJECTS; j++)
//			{
//				for (int x=0; x < RUN_FUNC_VERBS; x++)
//				{
//					
//					
//					printf("%i, %i, %i, %i\n", i, k, j, x);
//					rf_test.run_func(k, j, x);
//
//				}
//				
//				
//			}
//		}
//		
//	}	
//	/*check that all take events triggered*/
//	int not_taken = 0; 
//	for (int i = 0; i < NUM_OBJECTS; i++){
//		
//		int check_room = rf1_test.get_obj_starts_in(i);
//		if (rf1_test.get_room_x(check_room)->get_event_triggered(0)==1)
//		{
//			printf("%s was taken from %s\n", rf1_test.get_object_x(i)->get_name().c_str(), rf1_test.get_room_x(check_room)->get_name().c_str()); 
//			
//		}
//		if (rf1_test.get_room_x(check_room)->get_event_triggered(0)==0)
//		{
//			printf("%s was not taken\n", rf1_test.get_object_x(i)->get_name().c_str()); 
//			//not taken 
//			not_taken++;
//		}
//	} 
//	if (not_taken==8){
//		printf("-----PASS-----\n");
//		num_passes++;
//	}
//	else{
//		printf("-----FAIL----\n");
//		num_fails++;
//
//	}
//	
//	for (int i = 0; i < NUM_ROOMS; i++)
//	{	printf("TESTING IN ROOM %s\n", rf_test.get_room_x(rf_test.get_player()->get_current_room())->get_name().c_str());
//		int x[8]={0, 0, 0, 0, 0, 0, 0, 0};
//		rf_test.set_all_is_locked(x);
//		rf_test.get_player()->set_current_room(i);
//		for (int k = -1; k < TOTAL_FIXED; k++)
//		{
//			for (int j= -1; j < NUM_OBJECTS; j++)
//			{
////					for (int x=0; x < RUN_FUNC_VERBS; x++)
////					{
////						printf("TEST: %i, %i, %i, %i\n", i, k, j, x);
////						if (x==TAKE){
////							printf("------------RUNNING TAKE---------\n");
////						}
//					printf("------------RUNNING LOOK---------\n");
//					rf_test.run_func(k, j, LOOK);
//					
////					}
//			}
//		}
//		
//	}	
//	
//	int look_count = 0;
//	for (int i = 0; i < NUM_ROOMS; i++)
//	{	printf("TESTING IN ROOM %s\n", rf_test.get_room_x(rf_test.get_player()->get_current_room())->get_name().c_str());
//		int x[8]={0, 0, 0, 0, 0, 0, 0, 0};
//		rf_test.set_all_is_locked(x);
//		int y[8]={1, 1, 1, 1, 1, 1, 1, 1};
//		rf_test.set_all_player_objects(y);
//		rf_test.get_player()->set_current_room(i);
//		for (int k = -1; k < TOTAL_FIXED; k++)
//		{
//			for (int j= -1; j < NUM_OBJECTS; j++)
//			{
////					for (int x=0; x < RUN_FUNC_VERBS; x++)
////					{
////						printf("TEST: %i, %i, %i, %i\n", i, k, j, x);
////						if (x==TAKE){
////							printf("------------RUNNING TAKE---------\n");
////						}
//					printf("------------RUNNING LOOK---------\n");
//					int x = rf_test.run_func(k, j, LOOK);
//					printf("x: %i", x);
//					if (x==4){
//						look_count++;
//					}
//					
////					}
//			}
//			printf("look count: %i", look_count);
//			look_count = 0;
//
//		}
//		
//	}	

	
	
	//check toggled
	//printf("%i of %i tests passed", num_passes, num_passes+num_fails);
	
	
	

}	
	