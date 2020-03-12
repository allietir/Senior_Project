//
// Feature2.cpp
// Created by Claudia Rodriguez-Schroeder on 1/25/20.

#include "Feature2.h"

Feature2::Feature2() {
	set_name("\033[1;31mTree\033[0m");
	desc1 = "A large, gnarled, black \033[1;31mtree\033[0m without a single leaf. It seems to be as tall as the second floor. The branches appear to poke directly into the open window of the second story. ";
	set_desc(desc1);//
	set_desc_no_obj(desc1);
	set_index_id(1);
	set_attack_obj_id(4);
	
}

int Feature2::climb(){
	if (get_times_toggled(CLIMB)==0){
		printf("You climb up the \033[1;31mtree\033[0m and the branch extends into an open window on the second story. The room is dark but it looks like a master bedroom. If you climb a little more you could get in. ");
		func_togg_count_x(8);
		return -2;//indicate to Game that you are not able to do other things.
	}
	else if (get_times_toggled(CLIMB)==1){
		printf("You climb accross the rest of the branch and into the room. ");
		set_togg_count_x(CLIMB, 0);
		return 17;
	}
	return 5;
}

int Feature2::read(){
	if (get_times_toggled(READ)==0){
		printf("This \033[1;31mtree\033[0m is not yet a book, so you cannot read it. ");
		func_togg_count_x(READ);
		return 4;
	}
	else
	{
		printf("I know you want to read this, but you can't. It's a \033[1;31mtree\033[0m. Books are made from trees, and you can read those. Perhaps you'll find a book soon. ");
		func_togg_count_x(READ);
		return 4;
	} 
	return 4;
	
}
int Feature2::smell(){
	
	printf("The \033[1;31mtree\033[0m smells earthy; it looks cold and gnarled, but it smells alive, like sap and new life. ");
	func_togg_count_x(SMELL);
	return 4;
	
}
int Feature2::attack(int obj_feat_id){
	
	if (obj_feat_id==get_attack_obj_id())
	{
		printf("You have attacked with the %s. ", get_obj_name(obj_feat_id).c_str());
		return 1;
	}
	else if (obj_feat_id==-1){
		printf("Attacking without a weapon does nothing. ");
		return 4;
	}
	else{
		printf("Attacking with the %s does nothing. ", get_obj_name(obj_feat_id).c_str());
		return 4;
	}
	return 4;
	
}

Feature2::~Feature2() {
	
}
