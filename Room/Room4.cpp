//
// Room4.cpp
// Created by Claudia Rodriguez-Schroeder on 1/3/20.

#include "Room4.h"

Room4::Room4() {
	set_name("\033[0;36mDining Room\033[0m");
	set_extra_description("The room is uncomfortably warm and the smell of fresh blood wafts in the air. Is someone cooking... flesh? ");
	set_room_id(3);

	set_feature_x(new Feature7, 0);
	set_feature_x(new Feature8, 1);
	

	//set exits; name, direction
	set_exit_name("\033[0;36mKitchen\033[0m Door", 2);//kitchen, 
	set_exit_name("Hall to \033[0;36mentranceway\033[0m", 3);//entranceway,

	string exit_desc_2 = "There is a dirty \033[0;36mkitchen\033[0m door with burn marks and smoke stains upon it to the \033[0;32mwest\033[0m. ";
	string exit_desc_3 = "To the \033[0;32meast\033[0m is a dark hallway that you cannot see past. ";
	set_exit_desc(exit_desc_2, 2);
	set_exit_desc(exit_desc_3, 3);
	set_exit_id(12, 2);//exit at west goes to Room13
	set_exit_id(1, 3);//exit at east goes to Room13
	init_long_short_desc();
	set_num_events(3);
	//object set in Game, therefor description initialized in Game	
}
int Room4::event_one(){
	
	set_event_triggered(0, 1);
	
	printf("The \033[1;35mdiary\033[0m feels heavy and sturdy. You believe it could hold some answers to your questions. ");
	return 4;
}
int Room4::event_two(){

	printf("You consider the situation. You can help the \033[1;31mfaceless\033[0m monster find his face and he may attack you once he has power. You don't know what the right thing to do is.\nThe creature seems to sense your thoughts. You hear his voice in your head. \"I know where your friend is. The one that came with you. I can tell you where they are. But I cannot see without my eyes. Please, lend me a \033[1;35mlamp\033[0m that will give me back my face, and I will tell you where to find your friend.\" ");

	set_event_triggered(1, 1);
	return 4;
}
int Room4::event_three(){
	printf("The \033[1;31mfaceless\033[0m creature holds the \033[1;35mlamp\033[0m up to his face and his skin begins to melt off, leaving a disgusting puddle on the floor. However, in his place is a small, elf like creature. \"Thank you for freeing me\" says the small creature. \"I will keep my promise. Your friend is below ground. I can sense them.\"\nThe creature then scurries out of the room before you can say anything else.\nYour friend is below ground? Are they buried, are they alive? Are they buried alive?! ");
	get_feature_x(0)->set_desc("The creature is no longer there, but the puddle they left behind is still oozing. Gross.");
	set_event_triggered(2, 1);
	return 4;
}
Room4::~Room4() {
	//printf("Destroying derived class Room4\n");
}
