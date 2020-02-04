//
// Feature7.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Feature7.h"

Feature7::Feature7() {
	set_name("Faceless");
	set_desc("There is a still, mummified looking man at the end of the table. The create is absolutly still and appears to have no features at all; no eyes, no mouth, not an orafice in sight. The create's hands are laid on the table, enormous and clawed.");
	set_index_id(6);
	set_attack_obj_id(4);//uses gilded knife to attack
}
void Feature7::speak(){
	string speak_response="";
	if (get_times_toggled(7)==0){
		speak_response="Hello? Do you need help?";
		func_togg_count_x(6);
		
	}
	if (get_times_toggled(7)==1)
	{
		speak_response="Your face? Where can I help you find your face? How did you lose it? I have so many questions.\n";
		func_togg_count_x(6);
		
	}
	printf("%s\n", speak_response.c_str());
	
}
void Feature7::give(){
	string give_response = "";
	if (get_times_toggled(6)==1){
		give_response="You hear a voice, as if inside your head. 'I need my face. Find my face. Help me see' \n";
		func_togg_count_x(7);
		
	}
	if (get_times_toggled(6)==2){
		printf(" 'There's a ring on the table. Place the ring on my finger and I will be able to see.' \n");
		func_togg_count_x(7);
	}

	printf("%s\n", give_response.c_str());
	//in game, triggers event_one
	
}
int Feature7::attack(string obj_name){
	printf("You attack the %s with the %s. The creature raises his hand and with a single motion, stills your hand. ' You shouldn't have done that ' the creatue says, sadly. You watch in horror as the %s turns towards yourself. This is the end.\n", get_name().c_str(), obj_name.c_str(), obj_name.c_str());
	func_togg_count_x(9);
	return -1;
} 
Feature7::~Feature7() {
	
}
