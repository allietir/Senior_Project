//
// Room7.cpp
// Created by Claudia Rodriguez-Schroeder on 1/3/20.

#include "Room7.h"
//exit west->upstaris hallway:3

Room7::Room7() {
	set_name("\033[0;36mGuest Bedroom\033[0m");
	set_extra_description("You feel a heavy sadness; the grief of loss, the pain of lonliness");
	set_room_id(6);

	set_feature_x(new Feature13, 0);//Mother
	set_feature_x(new Feature14, 1);//Dresser
	
	set_exit_name("Door to hallway", 3);

	string exit_desc3 = "The doorway to the \033[0;36mhallway\033[0m is back to the \033[0;32mwest\033[0m.";
	set_exit_desc(exit_desc3, 3);

	set_exit_id(2, 3);//exit at west goes to upstairs hallway
	
	init_long_short_desc();
	//object set in Game, therefor description initialized in Game	
	set_num_events(3);

	
}
int Room7::event_one(){
	printf("The notes on the paper light up on the page briefly before settingling back down on to the page.\n");
	set_event_triggered(0, 1);
	printf(" =======new event triggered val: %i======", get_event_triggered(0));
	return 4;
}
int Room7::event_two(){
	printf("------ REACHED THIS EVENT---------- value of %i\n",  get_event_triggered(0));
	//this vent can only be triggered after you take the music
	if (get_event_triggered(0)==1){
		set_event_triggered(1, 1);
		printf("The \033[1;31mdresser\033[0m mirror shatters and you see the spirit in the mirror shriek noiselessly; yet, somehow, you can hear the sound within your very soul. The spirit sppears to crumble like dust in the wind");
		get_feature_x(0)->set_desc("The \033[1;31mwoman\033[0m in the bed seems to flush with life, for a moment, like she has been freed of some terrible trap. But she still sleeps. Perhaps she needs somone to wake her?");
		//use the unused count to indicate whether you are able to SPEAK to her.
		get_feature_x(0)->set_togg_count_x(READ, 666);//
		get_feature_x(1)->set_desc("The \033[1;31mdresser\033[0m is cracked and broken, the spirit you saw before nowhere to be seen in the shattered glass.");
		

	}
	else{
		printf("You have another task to complete before this event can occur.\n");
	}
	init_long_short_desc();
	return 4;
	
}
int Room7::event_three(){
	//this vent can only be triggered after you take the music
	if (get_event_triggered(1)==1){
		set_event_triggered(2, 1);
		printf("The \033[1;31mwomans\033[0m eyes open and she sighs happily. 'Thank you. I was trapped by sleep and the mirror for so very long. I will go find my family now.'\nWith that, she slips out of bed and glides as though a ghost throug the bedroom walls.\n");
		get_feature_x(0)->set_desc("The \033[1;31mwoman\033[0m left the bed, so she is now gone from this room.\n");
	}
	else{
		printf("You have another task to complete before this event can occur.\n");
	}
	init_long_short_desc();
	return 4;
}
Room7::~Room7() {
	//printf("Destroying derived class Room7\n");
}
