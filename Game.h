//
// Game.h
// Created by Claudia Rodriguez-Schroeder on 1/2/20.

#ifndef _Game_h_
#define _Game_h_
#include "Room/Room.h"
#include "Player.h"
#include "Room/Room1.h"
#include "Room/Room2.h"
#include "Room/Room3.h"
#include "Room/Room4.h"
#include "Room/Room5.h"
#include "Room/Room6.h"
#include "Room/Room7.h"
#include "Room/Room8.h"
#include "Room/Room9.h"
#include "Room/Room10.h"
#include "Room/Room11.h"
#include "Room/Room12.h"
#include "Room/Room13.h"
#include "Room/Room14.h"
#include "Room/Room15.h"

#include "Object/Object.h"
#include "globals.h"


//OBJECT
#include "Object/Object1.h"
#include "Object/Object2.h"
#include "Object/Object3.h"
#include "Object/Object4.h"
#include "Object/Object5.h"
#include "Object/Object6.h"
#include "Object/Object7.h"
#include "Object/Object8.h"


class Game {
public:
	Game();
	virtual ~Game();
	
	//-------------- I N I T I A L I Z E R S ------------//
	//FUNCTION ID: 1
	//PRECONDITION:
	//Room class object array
	//Array of initial object locations 
	//Functions set_has_objects, set_obj_location
	//POSTCONDIDION
	//sets each room to the array for reference
	//sets objects within the correct rooms 
	//sets whether a room needs a specific object to enter it
	void init_rooms();
	//FUNCTION ID: 2
	//PRECONDITIONS:
	//Object class array exits
	//POSTCONDITIONS:
	//object class array set to object
	void init_objects();
	//FUNCTION ID: 3
	//PRECONDITIONS:
	//Room array intialized to specific rooms
	//POSTCONDITIONS:
	//Feature list set to names of features. 
	void gen_feat_list();
	
	//-------------- S T A R T  G A M E --------------//
	//FUNCTION ID: 4
	//PRECONDITIONS:
	//Room array and object array initialized
	//POSTCONDITIONS:
	//first room visited and looked at 
	void start();
	
	//-------------- V E R B  F U N C T I O N  --------------//
	void take(int object_id);
	void drop(int object_id);
	void inventory();
	void exit_room(int dir);//take room of exit as parameter and update variables so that player is in new room
	void look();//trigger current room look
	void help();
	
	
	
	//-------------- V E R B  F U N C T I O N  H E L P E R S --------------//
	void trigger_take_event(int obj_id);
	
	int user_or_room_has_item(int item_id);
	int user_has_item(int item_id);
	int room_has_item(int item_id);
	

	

		
	//-------------- G E T  &  S E T --------------//	
	//----used by save_system---
	Player* get_player();
	void set_player(Player* playerx);
		
	void set_times_rooms_visited(int room_id, int new_time);
	int get_times_room_visited(int room_id);
	void set_game_events_triggered(int event_index, int val);
	int get_game_events_triggered(int event_index);	
	void set_room_events_triggered(int event_index, int val);
	int get_room_events_triggered(int event_index);
	void set_is_locked(int obj_index, int val);
	int get_is_locked(int obj_index);
	void set_needs_event(int roov_index, int event_numbers);
	int get_needs_event(int room_index);
	//so game can know where objects currently are, updated in "take" and "drop" functions
	void set_obj_location(int obj_id, int location);
	int get_obj_location(int obj_id);
	
	//------------- S E T  O N L Y ----------------------
	void set_player_has_all_objects(int set[NUM_OBJECTS]);

	//------ H E L P E R S  F O R  P A R S E R -----------//
	

	//calls the features objects verbs
	//check whether an exit to the requested room is available within the room
	int exit_current_from_room_id(int room_id);
	int run_func(int feat_index_id, int obj_index_id, int verb_id);
	
	
	//------ H E L P E R S  F O R  S A V E / L O A D -----------//
	
	void set_all_times_rooms_visited(int bin_arr[NUM_ROOMS]);
	string get_all_times_rooms_visited();
	
	void set_all_game_events_triggered(int bin_arr[NUM_GAME_EVENTS]);
	string get_all_game_events_triggered();
	
	void set_all_player_objects(int bin_arr[NUM_OBJECTS]);
	string get_all_player_objects();
	
	void set_all_room_objects(int bin_arr[NUM_OBJECTS]);
	string get_all_room_objects();
	
	void set_all_room_events_triggered(int bin_arr[NUM_EVENTS]);
	string get_all_room_events_triggered();
	
	void set_all_is_locked(int bin_arr[NUM_OBJECTS]);
	string get_all_is_locked();
	
	//----------- V A L I D I T Y  C H E C K E R S -------//
	//if the feauture id is valid, it checks agains the features within the current room, and returns 0 if is the first feature, 1 if the second feature, or -1 if it is not valid
	int feat_valid(int feat_index_id);
	
	int exit_valid(int next_room);
	
	//-------- O U T P U T / P R I N T  F U N C T I O N S ---//
	
	void output_current_object_locations();
	void output_feature_list_locations();
	void output_all_rooms();
	void output_all_rooms_and_features();
	//------------  O U T P U T  H E L P E R S ---------//
	string ret_curr_feat_list();
	string ret_curr_obj_loc();
	string concat_obj_descs();
	
	//------- MISC ----//
	int moves_left();
	
	//----------- C A L L  E V E N T S -------//	
	void event1();
	void event2();
	void event3();
	void event4();
	void event5();
	void event6(int obj_id);
	void event7();
	void event8();
	void event9();
	void event10();
	void event11();
	void event12();
	void event13();
	void event14();
	void event15();
	void event16();
	void event17();

	//-------- T E S T  / Q A ----------//
	void print_all_feature_desc();
	//get/sets only used for testing 
	Object* get_object_x(int x);
	Room* get_room_x(int x);
	int get_obj_starts_in(int obj_id);
	//PRECONDITIONS:
	//Have features and objects set up
	//POSTCONDITIONS:
	//times_toggled for each verb for each feature and object set to x times. 
	void set_all_verb_toggles_to_x(int x);
	//Have features and objects set up
	//POSTCONDITIONS:
	//times_toggled for verb y  for each feature and object set to x times. 
	void set_all_y_verb_toggles_to_x(int y, int x);
	int trigger_game_event_x(int x, int y);

	
private:	
	//implicitly initialized
	Object* o_array[NUM_OBJECTS];
	//reset in init_rooms
	Room* r_array[NUM_ROOMS];
	Player player1;

	
	//INTEGER ARRAYS that will have to be initialized to 0
	int game_events_triggered[NUM_GAME_EVENTS];
	int room_events_triggered[NUM_EVENTS];
	int times_rooms_visited[NUM_ROOMS];//called by init_rooms
	
	//initialized by gen_feat_list() called by init_rooms
	string feat_list[TOTAL_FIXED];
	
	
	//on start, locket is locked, doll, chalice is locked
	int is_locked[NUM_OBJECTS]={0, 0, 1, 0, 0, 1, 0, 1};
	
	
	int current_obj_location[NUM_OBJECTS]={ENTRANCEWAY, DINING, NURSERY, GUEST, FRONT, ATTIC, LIBRARY, CONSERVATORY};
	int room_obj_set[NUM_OBJECTS]={ENTRANCEWAY, DINING, NURSERY, GUEST, FRONT, ATTIC, LIBRARY, CONSERVATORY};
	int room_needs_object1[NUM_OBJECTS]={2, 3, 4, 5, 6, 7, 8, 13};
	

	//room i needs event at index to occur before you can enter. if -1, no event needed
	int room_needs_event_x[NUM_ROOMS]={-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 39};
	
	string verb_list[NUM_STR_VERBS]={STR_VERB1, STR_VERB2, STR_VERB3, STR_VERB4, STR_VERB5, STR_VERB6, STR_VERB7, STR_VERB8, STR_VERB9, STR_VERB10};
	string req_verb_list[NUM_REQ_VERBS]={STR_RVERB1, STR_RVERB2, STR_RVERB3, STR_RVERB4, STR_RVERB5, STR_RVERB6, STR_RVERB7, STR_RVERB8, STR_RVERB9, STR_RVERB10, STR_RVERB11, STR_RVERB12};
	string total_verb_list[NUM_STR_VERBS+NUM_REQ_VERBS]={STR_VERB1, STR_VERB2, STR_VERB3, STR_VERB4, STR_VERB5, STR_VERB6, STR_VERB7, STR_VERB8, STR_VERB9, STR_VERB10, STR_RVERB1, STR_RVERB2, STR_RVERB3, STR_RVERB4, STR_RVERB5, STR_RVERB6, STR_RVERB7, STR_RVERB8, STR_RVERB9, STR_RVERB10, STR_RVERB11, STR_RVERB12};
	

	
	
	
	
	int event8counter;

	
	
		
	
	

	
};

#endif