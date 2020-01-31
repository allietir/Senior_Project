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
string Feature3::look(){
	if (get_look_count()==0){
		set_desc(desc1);
	}

	if (get_look_count()==1){
		set_desc(desc2);
		set_look_count(0);
	}
	Feature::look();
	return get_desc();
	
}
string Feature3::pull(){
	
	string pull_event = "The painting seems to groan and suddenly the father's eyes seem to shift directly towards you, but it's dark so you might be seeing things. You decide not to pull the painting again";
	func_togg_count_x(1);
	return pull_event;
}
string Feature3::push(){
	
	string push_event = "";
	func_togg_count_x(2);
	return push_event;
}
Feature3::~Feature3() {
	
}
