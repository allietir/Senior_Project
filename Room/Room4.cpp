//
// Room4.cpp
// Created by Claudia Rodriguez-Schroeder on 1/3/20.

#include "Room4.h"

Room4::Room4() {
	set_name("Dining Room");
	set_extra_description("The room is uncomfortably warm and the smell of cooking flesh wafts in the air, of fresh blood. ");
	set_room_id(3);

	set_feature_x(new Feature7, 0);
	set_feature_x(new Feature8, 1);
	

	//set exits; name, direction
	set_exit_name("Kitchen Door", 2);//kitchen, east
	set_exit_name("West hallway", 3);//entranceway, west

	string exit_desc_2 = "A dirty kitchen door with burn and smoke stains upon it.";
	string exit_desc_3 = "A dark hallway you cannot see past.";
	set_exit_desc(exit_desc_2, 2);
	set_exit_desc(exit_desc_3, 3);
	set_exit_id(12, 2);//exit at east goes to Room13
	set_exit_id(1, 3);//exit at east goes to Room13
	init_long_short_desc();
	//object set in Game, therefor description initialized in Game	
}
void Room4::event_one(){
	printf("You consider the situation. You can help the monster find his face and he may attack you once he has power. You simply do now know what the right thing to do is in this situation.\n The creature seems to sense your hesitance. You hear his voice in your head. 'I know where your friend is. The one that came with you. I can tell you where they are. But I cannot see without my eyes. Please. Find the ring that will give me back my face, and I will tell you where to find your friend.\n You decide to locate the ring.");
}
void Room4::event_two(){
	printf("The create places the ring on his hand and his skin begins to melt off, leaving a disgusting puddle on the floor. However, in his place is a small, elf like creature. ' Thank you for freeing me' says the small creature. 'I will keep my promise. Your friend is below ground. I can sense them.'\n The creature then scurries out before you can say anything else.\n What does it mean, that your friend is below ground? Are they alive? \n\n");
}
Room4::~Room4() {
	//printf("Destroying derived class Room4\n");
}
