//
// Feature4.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Feature4.h"

Feature4::Feature4() {
	set_name("Musicbox");
	set_desc("At the entranceway of the foyer there is table. On top of the table is a little music box. It looks clamped shut with some sticks subtance. Do you have anything you can use to open it? Perhaps something hot to melt, or something sharp to break.");
	set_index_id(3);
}
int Feature4::speak(){
	if (get_times_toggled(PLAY)>=1)
	{
		string speak_response = "You lower your face down to the music box and you whisper your name. The ballerina stops ans seems to sink into the music box. On the little platform appears a tiny miniature of yourself. \n";
		func_togg_count_x(SPEAK);
		printf("%s\n", speak_response.c_str());
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
	string play_response = "The music box plays an eerie tune and the ballarina twirls. The music gets stranger and stranger until it starts to sound like a message. The message seems to say 'Tell me your name, tell me your name, tell me your name\n";
		func_togg_count_x(PLAY);
		printf("%s", play_response.c_str());

	}
	else{
		Feature::play();
		
	}
	return 4;
}			

int Feature4::open(int room_id, int feat_obj_id){
	
	string open_response = "The music box is opened to reveal a little ballarina. It has a switch that says 'play' ";
	func_togg_count_x(OPEN);
	printf("%s\n", open_response.c_str());
	return 4;
	
}



Feature4::~Feature4() {
	
}
