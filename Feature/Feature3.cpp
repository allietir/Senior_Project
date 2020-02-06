//
// Feature3.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Feature3.h"

Feature3::Feature3() {
	set_name("Portrait");
	desc1 = "There is a paiting of a stern looking family on the wall. Their features are blurred but they are dressed in old fashioned clothing and are unsmiling. There's a tall, darkly hansome man with what you swear is a bloodthirsty look in his eye. There's a meek looking woman who seems to be staring, not at the artist but at her hands. And there is a little girl clutching what looks like a doll, but you can't see much more. It looks like a corner of the paining is peeling. What could be underneath?";
	set_desc(desc1);
	set_index_id(2);
}
int Feature3::smell(){
	if(get_times_toggled(1)==0){
		string smell_event = "The painting seems to groan and suddenly the father's eyes seem to shift directly towards you, but it's dark so you might be seeing things. You decide not to smell the painting again";
		func_togg_count_x(1);
		printf("%s\n", smell_event.c_str());
	}
	else
	{
		string smell_event = "Nothing happens; you wonder if you imagined it before.\n";
		func_togg_count_x(1);
		printf("%s\n", smell_event.c_str());
	}
	return 4;
}
int Feature3::use(int feat_obj_id){
	
	if(get_times_toggled(2)==0){
		string use_event = "You feel a chill and you see the doll in the girls arms disapear. The girls face suddenly goes even sadder, and you see a single tear drop out of theh panting and onto your feet.\n";
			func_togg_count_x(2);
			printf("%s\n", use_event.c_str());
	}
	if(get_times_toggled(2)>1){
		string use_event = "Poor little girl. You are creeped out but sad for the family in the portrait.\n";
		func_togg_count_x(2);
		printf("%s\n", use_event.c_str());

	}
	return 4;
}
Feature3::~Feature3() {
	
}
