//
// Feature3.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Feature3.h"

Feature3::Feature3() {
	set_name("\033[1;31mPortrait\033[0m");
	desc1 = "There is a \033[1;31mportrait\033[0m of a stern looking family on the wall. A \033[1;35mlamp\033[0m appears below it. Their features are blurred but they are dressed in old fashioned clothing and are unsmiling. There's a tall, dark handsome man with a blood-thirsty look in his eyes. There's a meek looking woman who seems to be staring, not at the artist, but at her hands. And there is a little girl clutching what looks like a doll but you can't see much more. It looks like a corner of the \033[1;31mportrait\033[0m is peeling. What could be underneath? Can you try to open it? ";
	string desc2 = "There is a \033[1;31mportrait\033[0m of a stern looking family on the wall. Their features are blurred but they are dressed in old fashioned clothing and are unsmiling. There's a tall, dark handsome man with a bloodthirsty look in his eyes. There's a meek looking woman who seems to be staring, not at the artist, but at her hands. And there is a little girl clutching what looks like a doll, but you can't see much more. It looks like a corner of the \033[1;31mportrait\033[0m is peeling. What could be underneath? Can you try to open it? ";
	set_desc(desc1);
	set_desc_no_obj(desc2);
	
	set_index_id(2);
}
int Feature3::open(int room_id, int obj_feat_id){
	if(get_times_toggled(OPEN)==0){
		string open_event = "The \033[1;31mportrait\033[0m groans and suddenly the father's eyes seem to shift directly towards you, but it's dark so you might be seeing things. You decide not to open the \033[1;31mportrait\033[0m again. ";
		func_togg_count_x(OPEN);
		printf("%s", open_event.c_str());
	}
	else
	{
		string open_event = "You want to look closer, but it is too dark. What can you use to look at the details? ";
		func_togg_count_x(OPEN);
		printf("%s", open_event.c_str());
	}
	return 4;
}
int Feature3::use(int feat_obj_id){
	
	if (feat_obj_id == 0){
		if(get_times_toggled(2)==0){
				string use_event = "You feel a chill and you see the doll in the girl arms disapear. The girl face grows even sadder, and you see a single tear drop out of the \033[1;31mportrait\033[0m and onto your feet. ";
					func_togg_count_x(2);
					printf("%s", use_event.c_str());
			}
			if(get_times_toggled(2)>1){
				string use_event = "Poor little girl. You are creeped out but sad for the family in the \033[1;31mportrait\033[0m. ";
				func_togg_count_x(2);
				printf("%s", use_event.c_str());

			}
	}
	else{
		Feature::use(feat_obj_id);
	}
	
	return 4;
}
Feature3::~Feature3() {
	
}
