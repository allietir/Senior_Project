//
// Room7.cpp
// Created by Claudia Rodriguez-Schroeder on 1/3/20.

#include "Room7.h"
//exit west->upstaris hallway:3

Room7::Room7() {
	set_name("\033[0;36mGuest Bedroom\033[0m");
	set_extra_description("You feel a heavy sadness... the grief of loss, the pain of loneliness. ");
	set_room_id(6);

	set_feature_x(new Feature13, 0);//Mother
	set_feature_x(new Feature14, 1);//Dresser
	
	set_exit_name("Door to \033[0;36mhallway\033[0m", 3);

	string exit_desc3 = "The door to the \033[0;36mhallway\033[0m is back to the \033[0;32meast\033[0m. ";
	set_exit_desc(exit_desc3, 3);

	set_exit_id(2, 3);//exit at west goes to upstairs hallway
	
	init_long_short_desc();
	//object set in Game, therefor description initialized in Game	
	set_num_events(3);

	
}
int Room7::event_one(){
	printf("The notes on the paper light up on the page briefly before settling back down on to the page. ");
	set_event_triggered(0, 1);
	//printf(" =======new event triggered val: %i======", get_event_triggered(0));
	return 4;
}
int Room7::event_two(){

//	printf("------ REACHED THIS EVENT---------- value of %i\n",  get_event_triggered(0));

	//this vent can only be triggered after you take the music
	if (get_event_triggered(0)==1){
		set_event_triggered(1, 1);
		printf("The \033[1;31mdresser\033[0m mirror shatters and you see the spirit in the mirror shriek. You cannot hear the sound, but your soul can feel it. The spirit crumbles away like dust in the wind. ");
		get_feature_x(0)->set_desc("The \033[1;31mwoman\033[0m in the bed is flush with life, like she has been freed of some terrible trap. But she still sleeps. Perhaps she needs someone to wake her? ");
		//use the unused count to indicate whether you are able to SPEAK to her.
		get_feature_x(0)->set_togg_count_x(READ, 666);//
		get_feature_x(1)->set_desc("The \033[1;31mdresser\033[0m is cracked and broken, the spirit you saw before is nowhere to be seen in the shattered glass. ");
		

	}
	else{
		printf("Look at the dresser; there is something you need from there before you attack. ");
	}
	init_long_short_desc();
	return 4;
	
}
int Room7::event_three(){
	//this vent can only be triggered after you take the music
	if (get_event_triggered(1)==1){
		set_event_triggered(2, 1);
		printf("The \033[1;31mwomans\033[0m eyes open and she sighs happily. \"Thank you. I was trapped in the mirror with a deathly sumber for so long. I will go find my family now.\"\nWith that, she slips out of bed and disappears through the bedroom walls. ");
		get_feature_x(0)->set_desc("The \033[1;31mwoman\033[0m left the bed, so she is now gone from this room. ");
	}
	else{
		printf("You have another task to complete before this event can occur. ");
	}
	init_long_short_desc();
	return 4;
}
Room7::~Room7() {
	//printf("Destroying derived class Room7");
}
