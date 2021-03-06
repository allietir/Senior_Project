//
// Feature5.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Feature5.h"

Feature5::Feature5() {
	
	current_time = 0;
	set_name("\033[1;31mClock\033[0m");
	string desc_a = "There is a \033[1;31mclock\033[0m at the end of the hallway, a grandfather \033[1;31mclock\033[0m, large and imposing. There's an inscription on the \033[1;31mclock\033[0m. It looks like there are two doors: one glass door, and a door inside of the; It has a key hole that looks exactly like a \033[1;35mdagger\033[0m hilt. What happens when the \033[1;31mclock\033[0m strikes midnight?\n" + get_time_str();
	set_desc(desc_a);
	set_desc_no_obj("There is a \033[1;31mclock\033[0m at the end of the hallway, a grandfather \033[1;31mclock\033[0m, large and imposing. There's an inscription on the \033[1;31mclock\033[0m. It looks like there are two doors: one glass door, and a door inside of the; It has a key hole that looks exactly like a \033[1;35mdagger\033[0m hilt. What happens when the \033[1;31mclock\033[0m strikes midnight?\n");
	set_index_id(4);
	
	
}

int Feature5::read(){
	func_togg_count_x(READ);
	printf("The \033[1;31clock's\033[0m inscription says, 'I slow as you hasten.' Well, that certainly doesn't feel true. What if you say those words aloud, though? You feel compelled to do so. Speak the words. ");
	return 4;
}
int Feature5::speak(){
	if (get_times_toggled(SPEAK)==0){
		func_togg_count_x(SPEAK);
			printf("You say the inscription you read on the clock outloud, \'I slow as you hasten.\' The latch on the door creaks open, and reveals a strange looking keyhole that doesn't look like it would fit a normal key; it looks more like a \033[1;35mdagger\033[0m hilt. ");
	}
	else{
		printf("The door is already open on the grandfather \033[1;31mclock\033[0m. ");
	}
	return 4;
	
	
}//6
int Feature5::use(int obj_feat_id){
	
	if (get_times_toggled(SPEAK)>=1){
		if (obj_feat_id==DAGGER){
			func_togg_count_x(USE);
				printf("You use the \033[1;35mDagger\033[0m in the hilt-like key hole and hear mechanisms unlock. Should you try to open it? ");
			}
			else{
					printf("An excellent attempt; simply try a different object. ");
				}

	}
	else{
		printf("It's hard to interact with the \033[1;31mclock\033[0m as it is still closed; perhaps some information exists to open this, like a spell. Try reading the \033[1;31mclock\033[0m. ");
	}
	return 4;
	
	
}//7
int Feature5::open(int room_id, int obj_feat_id){
	if (get_times_toggled(USE)>=1){
		func_togg_count_x(OPEN);
		printf("You open the door and you see a staircase down. Looks like you'll need to climb quite far to get down there... but where does it go? ");
		string desc = "The grandfather \033[1;31mclock\033[0m is open and a staircase down is revealed.\n" + get_time_str();
		
		set_desc(desc);
		set_desc_no_obj("The grandfather \033[1;31mclock\033[0m is open and a staircase down is revealed. ");
	}
	else{
		printf("First, read the \033[1;31mclock\033[0m and speak the spell.  Then, you must use the \033[1;35mdagger\033[0m with the \033[1;31mclock\033[0m before trying to open it. ");
	}
	return 4;
}//5
int Feature5::climb(){
	if (func_togg_count_x(OPEN)>=1)
	{
		func_togg_count_x(CLIMB);
		printf("You climb down into the darkness and hear the doors slam behind you. ");
		set_togg_count_x(OPEN, 0);
		set_togg_count_x(USE, 0);
		set_togg_count_x(SPEAK, 0);
		set_togg_count_x(READ, 0);
		set_togg_count_x(EAT, 0);
		return CRYPT+10;
	}
	else{
		printf("There is nothing to climb up or down to. ");
	}
	return 4;
}
string Feature5::get_time_str(){
	
	
	string am_pm = "";
	int PM_Time = 0;
	if (current_time+9<=12){
		am_pm = "AM";
		return "It is currently " + to_string(current_time+9) + am_pm;
	}
	else{
		PM_Time = current_time+9-12;
		am_pm = "PM";
		return "It is currently " + to_string(PM_Time) + am_pm;
	}	 
	return "no time at all. ";
}
int Feature5::get_time(){
	return current_time;
}
void Feature5::set_time(int the_time){
	current_time = the_time;

	//printf("===========%s===========", get_time_str().c_str());
	set_desc(get_desc_no_obj()+get_time_str());
	
	//printf("=============%s==============", get_desc().c_str());
}
int Feature5::look(){
	if (get_times_toggled(EAT)!=666){
		string desc_a =  "There is a \033[1;31mclock\033[0m at the end of the hallway, a grandfather \033[1;31mclock\033[0m, large and imposing. There's an inscription on the \033[1;31mclock\033[0m. It looks like there are two doors: one glass door, and a door inside of the; It has a key hole that looks exactly like a \033[1;35mdagger\033[0m hilt. What happens when the \033[1;31mclock\033[0m strikes midnight?\n"+ get_time_str();
		set_desc(desc_a);
		Feature::look();
	}
	else
	{
		Feature::look();
	}
	
	return 4;
}

Feature5::~Feature5() {
	
}
