//
// Feature7.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Feature7.h"

Feature7::Feature7() {

	set_name("\033[1;31mFaceless\033[0m");
	set_desc("There is a still, mummified looking man at the end of the table. The creature has no face; you don't know why but you believe it can be called \033[1;31mFaceless\033[0m. The creature is absolutly still and appears to have no features at all; no eyes, no mouth, not an orafice in sight. The creature's hands are laid on the table, enormous and clawed. ");
	set_index_id(6);
	set_attack_obj_id(4);//uses gilded knife to attack
}
int Feature7::speak(){
	string speak_response="";
	if (get_times_toggled(SPEAK)==0){
		speak_response="\"Hello? Do you need help?\"\nYou hear a voice, as if inside your head. \"I need my face. Find my face. Help me see.\" Hmm, that was confusing. Maybe ask again. ";
		printf("%s\n", speak_response.c_str());
		func_togg_count_x(SPEAK);
		
	}
	else if (get_times_toggled(SPEAK)==1)
	{
		speak_response="\"Your face? Where can I help you find your face? How did you lose it? I have so many questions.\"\n\"Let me hold the lamp for a moment. It will help me see. And then, I can see myself.\" ";
		printf("%s\n", speak_response.c_str());
		func_togg_count_x(SPEAK);
		return 1;
		
	}

	return 4;	
}
int Feature7::give(int room_id, int obj_feat_id){
	if (obj_feat_id==0){
		func_togg_count_x(GIVE);
		return 2;
	}
	//in game, triggers event_one
	return 4;
}	
int Feature7::attack(int obj_id){
	if (obj_id!=-1){
		printf("You attack the %s with the %s. The creature raises his hand and with a single motion, stills your hand. \"You shouldn't have done that.\" the creatue says, sadly. You watch in horror as the %s turns towards you. \"This is the end.\" ", get_name().c_str(), get_obj_name(obj_id).c_str(),
		get_obj_name(obj_id).c_str());
			func_togg_count_x(ATTACK);
			return -1;
	}
	printf("You can't attack with nothing. ");
	return 4;
	
} 
Feature7::~Feature7() {
	
}
