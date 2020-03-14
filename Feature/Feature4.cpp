//
// Feature4.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Feature4.h"

Feature4::Feature4() {
	set_name("\033[1;31mMusicbox\033[0m");
	set_desc("At the \033[0;36mentranceway\033[0m of the foyer there is table. On top of the table is a little \033[1;31mmusicbox\033[0m. It looks clamped shut with some sticky subtance. Do you have anything you can use to open it? Maybe something sharp, to open the \033[1;31mmusicbox\033[0m?");
	set_desc_no_obj(get_desc());
	set_index_id(3);
}
int Feature4::speak(){
	if (get_times_toggled(PLAY)>=1)
	{
		string speak_response = "You lower your face down to the \033[1;31mmusicbox\033[0m and you whisper your name. The ballerina stops and appears to sink into the\033[1;31mmusicbox\033[0m. On the little platform appears a tiny miniature of yourself. ";
		func_togg_count_x(SPEAK);
		printf("%s", speak_response.c_str());
	}
	else
	{
		Feature::speak();
	}
	return 4;
}
int Feature4::play(){
if (get_times_toggled(OPEN)>=1)
{
	string play_response = "The \033[1;31mmusicbox\033[0m plays an eerie tune and the ballerina twirls. The music gets stranger and stranger until it starts to sound like a message. The message sounds like 'Tell me your name, tell me your name, tell me your name. ";
		func_togg_count_x(PLAY);
		printf("%s", play_response.c_str());

	}
	else{
		printf("Musicbox is shut, so cannot be played.");
		
	}
	return 4;
}			

int Feature4::open(int room_id, int feat_obj_id){
	
	if (feat_obj_id!=DAGGER){
		if (get_times_toggled(OPEN)==0){
			printf("The \033[1;31mmusicbox\033[0m is stuck shut, you can't make it open with just your hands. If only you had something that could cut that sticky substance. Then, you could try to open the \033[1;31mmusicbox\033[0m. ");
		}
		else if (get_times_toggled(OPEN)>=1){
				printf("The musicbox is already open. ");
			}
			else{
					printf("None of the conditions to open exist. ");
				}
	}
	else if (feat_obj_id==DAGGER){
		if (get_times_toggled(OPEN)==0){
		string open_response = "The \033[1;31mmusicbox\033[0m is opened to reveal a little ballerina. It has a switch that says 'play'. ";
		func_togg_count_x(OPEN);
		set_desc("At the \033[0;36mentranceway\033[0m of the foyer there is table. On top of the table is a little \033[1;31mmusicbox\033[0m. It is wide open and you can see the little ballarina, and the switch that says 'play'");
		printf("%s", open_response.c_str());
		return 4;
		}
		else if (get_times_toggled(OPEN)>=1){
				printf("The musicbox is already open. ");
			}
			else{
					printf("None of the conditions to open exist. ");
				}
	}
	else if (get_times_toggled(OPEN)>=1){
		printf("The musicbox is already open. ");
	}
	else{
		printf("None of the conditions to open exist. ");
	}
	return 4;
	
	
}



Feature4::~Feature4() {
	
}
