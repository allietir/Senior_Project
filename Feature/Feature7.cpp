//
// Feature7.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Feature7.h"

Feature7::Feature7() {
	set_name("Faceless");
	set_desc("There is a still, mummified looking man at the end of the table. The create is absolutly still and appears to have no features at all; no eyes, no mouth, not an orafice in sight. The create's hands are laid on the table, enormous and clawed.");
	set_index_id(6);
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
void Feature7::listen(){
	string listen_response = "";
	if (get_times_toggled(6)==1){
		listen_response="You hear a voice, as if inside your head. 'I need my face. Find my face. Help me see' \n";
		func_togg_count_x(7);
		
	}
	if (get_times_toggled(6)==2){
		printf(" 'There's a ring on the table. Place the ring on my finger and I will be able to see.' \n");
		func_togg_count_x(7);
		Room4 r4;
		r4.event_one();
	}
	//trigger event
	//Room4 r4;
	//r4.event_one();
	printf("%s\n", listen_response.c_str());
	
}
void Feature7::attack(){

}
Feature7::~Feature7() {
	
}
