//
// Feature4.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Feature4.h"

Feature4::Feature4() {
	set_name("Music box");
	set_desc("At the entranceway of the foyer there is table. On top of the table is a little music box.");
	set_index_id(3);
}
void Feature4::pull(){
	if (get_times_toggled(4)>=1)
	{
		string pull_response = "Yanking on the music box spring causes the box to collapse completely. But it looks like the dust revelaed something gleaming from below the box remains";
		func_togg_count_x(1);
		printf("%s\n", pull_response.c_str());
	}
	else
	{
		Feature::pull();
	}
}
void Feature4::push(){
	if (get_times_toggled(1)>=1)
	{
		string push_response = "Pushing aside the box remains you see a golden pentagram revelaed etched in the table. Somehow, it wasn't there before. ";
		func_togg_count_x(2);
		printf("%s\n", push_response.c_str());
	}
	else
	{
		printf("The music box is nailed down. \n");
		Feature::pull();
	}
}
void Feature4::play(){
if (get_times_toggled(5)>=1)
{
	string play_response = "The music box plays an eerie tune and the ballarina twirls. The music gets stranger and stranger until a spring breaks loose and causes the ballarina to shoot out like a jack in the box. She dangles from the spring. What will happen if you pull the music box spring?";
		func_togg_count_x(4);
		printf("%s", play_response.c_str());

	}
	else{
		Feature::play();
		
	}
	
}			

void Feature4::open(int room_id, int feat_obj_id){
	
	string open_response = "The music box is opened to reveal a little ballarina. It has a switch that says 'play' ";
	func_togg_count_x(5);
	printf("%s\n", open_response.c_str());

	
}



Feature4::~Feature4() {
	
}
