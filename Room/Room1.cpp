//
// Room1.cpp
// Created by Claudia Rodriguez-Schroeder on 1/3/20.

#include "Room1.h"

Room1::Room1() {
	set_name("Front Garden");
	set_extra_description("There is a general feeling of drearyness and unease in the air.");
	set_room_id(0);

	set_feature_x(new Feature1, 0);
	set_feature_x(new Feature2, 1);
	
	init_long_short_desc();
	//set exits; name, direction
	set_exit_name("Front door", 0);
	string exit_desc = "A large, imposing front door in the north, dark and heavy looking. It appears to be slightly adjar. ";
	set_exit_desc(exit_desc, 0);
	set_exit_id(1, 0);//exit at north goes to Room2

	init_long_short_desc();
	//object set in Game, therefor description initialized in Game
	
}
int Room1::event_one(){
	printf("The dagger resonates in your hand as you pick it up. The item has great power, and you can feel the power within your hand. The gilded handle reminds you of someting powerful and ancient.\n");
	set_event_triggered(0, 1);
	return 1;
}
//if you attack() tree
int Room1::event_two(){
	printf("The tree shakes and suddenly the face of the tree comes alive. You see a face more old and ancient and angry than any human could ever be, and in that moment you realize you have made an enormous error. That's the last thought you have before the tree swallows you whole.\n");
	set_event_triggered(1, 1);
	return -1;
}
//if you eat() knife
int Room1::event_three(){
	printf("The floor opens up and swallows you whole\n");
	set_event_triggered(2, 1);
	return -1;
}

Room1::~Room1() {
	
}