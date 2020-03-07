//
// Room4.cpp
// Created by Claudia Rodriguez-Schroeder on 1/3/20.

#include "Room4.h"

Room4::Room4() {
	set_name("\033[0;36mDining Room\033[0m");
	set_extra_description("The room is uncomfortably warm and the smell of cooking flesh wafts in the air, of fresh blood. ");
	set_room_id(3);

	set_feature_x(new Feature7, 0);
	set_feature_x(new Feature8, 1);
	

	//set exits; name, direction
	set_exit_name("Kitchen Door", 2);//kitchen, 
	set_exit_name("West hallway", 3);//entranceway,

	string exit_desc_2 = "A dirty \033[0;36mkitchen\033[0m door with burn and smoke stains upon it to the \033[0;32mwest\033[0m.";
	string exit_desc_3 = "To the \033[0;32mwest\033[0m a dark hallway that you cannot see past.";
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
	
	printf("The \033[1;35mdiary\033[0m is heavy and sturdy in your hands. You believe it could hold important answers to your questions.");
	return 4;
}
int Room4::event_two(){
	printf("You consider the situation. You can help the \033[1;31mfaceless\033[0m monster find his face and he may attack you once he has power. You simply do not know what the right thing to do is in this situation.\n The creature seems to sense your hesitance. You hear his voice in your head. 'I know where your friend is. The one that came with you. I can tell you where they are. But I cannot see without my eyes. Please. Lend me the \033[1;35mlamp\033[0m that will give me back my face, and I will tell you where to find your friend.\n You decide to lend the creature the \033[1;35mlamp\033[0m.");
	set_event_triggered(1, 1);
	return 4;
}
int Room4::event_three(){
	printf("The \033[1;31mfaceless\033[0m creature holds the \033[1;35mlamp\033[0m up to his face and his skin begins to melt off, leaving a disgusting puddle on the floor. However, in his place is a small, elf like creature. ' Thank you for freeing me' says the small creature. 'I will keep my promise. Your friend is below ground. I can sense them.'\n The creature then scurries out before you can say anything else.\n What does it mean, that your friend is below ground? Are they alive? \n\n");
	set_event_triggered(2, 1);
	return 4;
}
Room4::~Room4() {
	//printf("Destroying derived class Room4\n");
}
