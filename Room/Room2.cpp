//
// Room2.cpp
// Created by Claudia Rodriguez-Schroeder on 1/3/20.

#include "Room2.h"

Room2::Room2() {
//ON EXIT: friend dissapers from the room
	set_name("\033[0;36mEntranceway\033[0m");
	set_extra_description("The room is dark and damp, simultaneously cloistering yet overwhelmingly large. ");
	set_room_id(1);
	set_feature_x(new Feature3, 0);
	set_feature_x(new Feature4, 1);
	//set exits; name, direction
	set_exit_name("Staircase", 0);//to Upstairs Hallway 3/2
	set_exit_name("Front Door", 1);//to Front Garden 1/0
	set_exit_name("Hallway", 2);//to Dinign Room 4/3
	set_exit_name("Hallway", 3);//to Parlor/lounge 5/4
	set_exit_id(2, 0);//room_id, exit_index
	set_exit_id(0, 1);//room_id, exit_index
	set_exit_id(3, 2);//room_id, exit_index 
	set_exit_id(4, 3);//room_id, exit_index
	string exit_desc_0 = "There is a staircase before you to the \033[0;32mnorth\033[0m, winding up to an eternal unknown. Strangely, a fog seems to be drifting down from the top of the stairs. ";
	string exit_desc_1 = "Behind you to the \033[0;32msouth\033[0m the front door to the \033[0;36mgarden\033[0m shows the path leading out. There is still time to go back. You have the sense that you could leave and the house would forgive you. ";
	string exit_desc_2 = "There is a dark hallway to the \033[0;32mwest\033[0m. You can't see a thing. You can smell food however. Perhaps it is a \033[0;36mdining room\033[0m?";
	string exit_desc_3 = "There is another dark hallway toward the \033[0;32meast\033[0m. You hear faint music that seems to be coming from there.";
	set_exit_desc(exit_desc_0, 0);
	set_exit_desc(exit_desc_1, 1);
	set_exit_desc(exit_desc_2, 2);
	set_exit_desc(exit_desc_3, 3);
	
	init_long_short_desc();
	//object set in Game, therefor description initialized in Game
	set_num_events(1);
	set_event_triggered(0, 0);

}
int Room2::event_one(){

	printf("The \033[1;35mlamp\033[0m turns on when it is in your hands. The light is soft and delightful. You feel somewhat safter already. A breeze blows from somewhere deep in the house, and the lamp sparks, then turns off. ");

	set_event_triggered(0, 1);

	return 4;
}


Room2::~Room2() {
	
}
