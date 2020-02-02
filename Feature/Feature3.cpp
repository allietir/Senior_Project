//
// Feature3.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Feature3.h"

Feature3::Feature3() {
	set_name("Family Portrait");
	desc1 = "There is a paiting of a stern looking family on the wall. Their features are blurred but they are dressed in old fashioned clothing and are unsmiling. There's a tall, darkly hansome man with what you swear is a bloodthirsty look in his eye. There's a meek looking woman who seems to be staring, not at the artist but at her hands. And there is a little girl clutching what looks like a doll, but you can't see much more. ";
	desc2 = "It looks like a corner of the paining is peeling. What could be underneath?";
	set_desc(desc1);
	set_index_id(2);
}
void Feature3::look(){
	if (get_look_count()==0){
		set_desc(desc1);
		set_look_count(1);
	}

	if (get_look_count()==1){
		set_desc(desc2);
		set_look_count(0);
	}
	func_togg_count_x(0);
	printf("%s\n", get_desc().c_str());
	
}
void Feature3::pull(){
	
	if(get_times_toggled(1)==0){
		string pull_event = "The painting seems to groan and suddenly the father's eyes seem to shift directly towards you, but it's dark so you might be seeing things. You decide not to pull the painting again";
	func_togg_count_x(1);
	printf("%s\n", pull_event.c_str());
	}
	else{
		string pull_event = "Nothing happens; you wonder if you imagined it before.\n";
		func_togg_count_x(1);
		printf("%s\n", pull_event.c_str());
		
	}
}
void Feature3::push(){
	
	if(get_times_toggled(2)==0){
		string push_event = "You feel a chill and you see the doll in the girls arms dissapear. The girls face suddenly goes even sadder, and you see a single tear drop out of theh panting and onto your feet.\n";
			func_togg_count_x(2);
			printf("%s\n", push_event.c_str());

	}
	if(get_times_toggled(2)>1){
		string push_event = "Poor little girl. You are creeped out but sad for the family in the portrait.\n";
		func_togg_count_x(2);
		printf("%s\n", push_event.c_str());

	}
}
Feature3::~Feature3() {
	
}
