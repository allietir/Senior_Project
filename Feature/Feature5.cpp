//
// Feature5.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Feature5.h"

Feature5::Feature5() {
	
	set_name("Clock");
	string desc_a = "There is a clock at the end of the highway, a grandfather clock, large and imposing. What happens when the clock strikes midnight?\n" + get_time_str();
	set_desc(desc_a);
	set_desc_no_obj("There is a clock at the end of the highway, a grandfather clock, large and imposing. What happens when the clock strikes midnight?\n");
	set_index_id(4);
}

int Feature5::read(){
	func_togg_count_x(READ);
	printf("The clock's inscription says, 'I slow as you hasten'. Well, that certainly doesn't feel true.\n");
	return 4;
}
int Feature5::speak(){
	if (get_times_toggled(SPEAK)==0){
		func_togg_count_x(SPEAK);
			printf("You say the inscription outloud, 'I slow as you hasten.' . The latch on the door creaks open, and reveals a strange looking keyhole that doesn't look like it would fit a normal key; it looks more like a daggers hilt.\n");
	}
	else{
		printf("The door is already open on the grandfather clock.\n");
	}
	return 4;
	
	
}//6
int Feature5::use(int obj_feat_id){
	
	if (get_times_toggled(SPEAK)>=1){
		if (obj_feat_id==DAGGER){
			func_togg_count_x(USE);
				printf("You use the dagger in the hilt-like key hold, and hear mechanisms unlock. Should you try to open it?\n");
			}
	}
	else{
		printf("It's hard to interact with the clock as it is still closed. ");
	}
	return 4;
	
	
}//7
int Feature5::open(int room_id, int obj_feat_id){
	if (get_times_toggled(USE)>=1){
		func_togg_count_x(OPEN);
		printf("You open the door and you see a staircase down. Looks like you'll need to climb quite a bit to get down there... but where does it go?");
		string desc = "The grandfather clock is open and a staircase down is revealed.\n" + get_time_str();
		
		set_desc(desc);
		set_desc_no_obj("The grandfather clock is open and a staircase down is revealed.\n");
	}
	return 4;
}//5
int Feature5::climb(){
	if (func_togg_count_x(OPEN)>=1)
	{
		func_togg_count_x(CLIMB);
		printf("You climb down into the darkness.");
		return CRYPT+10;
	}
	else{
		printf("There is nothing to climb up or down to.\n");
	}
	return 4;
}
string Feature5::get_time_str(){
	
	string am_pm = "";
	int PM_Time = 0;
	if (current_time+9<=12){
		am_pm = "AM";
		return "It is currenty " + to_string(current_time+9) + am_pm;
	}
	else{
		PM_Time = current_time+9-12;
		am_pm = "PM";
		return "It is currenty " + to_string(PM_Time) + am_pm;
	}	 
	return "no time at all";
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
	string desc_a = "There is a clock at the end of the highway, a grandfather clock, large and imposing. What happens when the clock strikes midnight?\n" + get_time_str();
	set_desc(desc_a);
	Feature::look();
	return 4;
}

Feature5::~Feature5() {
	
}
