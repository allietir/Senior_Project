//
// Room1.cpp
// Created by Claudia Rodriguez-Schroeder on 1/3/20.

#include "Room1.h"

Room1::Room1() {
	set_name("\033[0;36mFront Garden\033[0m");
	set_extra_description("The air feels dreary and uneasy. ");
	set_room_id(0);

	set_feature_x(new Feature1, 0);
	set_feature_x(new Feature2, 1);
	
	init_long_short_desc();
	//set exits; name, direction
	set_exit_name("Door", 0);
	string exit_desc = "There is a large and dark-colored front door to the \033[0;32mnorth\033[0m. It appears to be slightly ajar. You can see what looks like an \033[0;36mentranceway\033[0m to the house. ";
	set_exit_desc(exit_desc, 0);
	set_exit_id(1, 0);//exit at north goes to Room2

	init_long_short_desc();
	//object set in Game, therefor description initialized in Game
	set_num_events(3);
	set_event_triggered(0,0);
	set_event_triggered(1,0);
	set_event_triggered(2,0);
	
}
int Room1::event_one(){
	printf("The silver \033[1;35mdagger\033[0m resonates with power as you pick it up. You look over the ancient runes inscribed into the handle. You feel a sense of strength and confidence as you hold onto it.  ");
	set_event_triggered(0, 1);
	
	return 4;
}
//if you attack() tree
int Room1::event_two(){
	printf("The \033[1;31mtree\033[0m shakes and suddenly its face comes alive. You see a menacing face, and it looks angry. Actually, it looks really really angry. Your last word escapes your lips... oops. The tree swallows you whole. ");
	set_event_triggered(1, 1);
	//return 4;
	return -1;
}
//if you eat() knife
int Room1::event_three(){
	printf("You feel a tremor as the ground beneath you opens and swallows you whole. ");
	set_event_triggered(2, 1);
	return -1;
}

Room1::~Room1() {
	
}