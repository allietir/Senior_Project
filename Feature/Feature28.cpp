//
// Feature28.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Feature28.h"

Feature28::Feature28() {
	set_name("Statue");
	set_desc("The statue is marbled, white, and beautiful, the most beautiful statue you have ever seen; it looks like if you blinked, it would come alive. The clothes chisled look like silk; the eyes seem to see somwhere more incredible than you could eve dream of. \n");
	set_index_id(27);
}

int Feature28::use(int obj_feat_id){
	if ((obj_feat_id==DIARY)&&(get_times_toggled(USE)==0)){
		func_togg_count_x(USE);
		printf("You open the diary and locate a spell to make stone come to life\n'When the human speaks spells\nWill stone become flesh\n'");
		set_desc("The statue squirms in place, alive and yet trapped.\n");

	}
	else if ((obj_feat_id==DIARY)&&(get_times_toggled(USE)>=1)){
		printf("You've alreday used the spell");
	}
	else{
		printf("This item can't be used with this statue");
	}
	return 4;
}
int Feature28::speak(){
	if (get_times_toggled(USE)>=1){
		if (get_times_toggled(SPEAK)==0){
			func_togg_count_x(SPEAK);
			printf("Well, this is alright, I suppose. For giving me this experience, let me give you a clue:\nFirst comes the fire\nThen comes the word\nFollows the heart\nRecalls a type of word\nNext draws the blood\nThe something reflects\nSecond last is the key\nAnd at last is the rest\n");
		}
		
		
		else if (get_times_toggled(SPEAK)==1){
				func_togg_count_x(SPEAK);
				printf("Okay, I'll tell you again: \nFirst comes the fire\nThen comes the word\nFollows the heart\nRecalls a type of word\nNext draws the blood\nThe something reflects\nSecond last is the key\nAnd at last is the rest\n");
			}
			else if (get_times_toggled(SPEAK)>=2){
					func_togg_count_x(SPEAK);
					printf("The creature roll it's eyes. 'Fine, I'll spell it out for you. It's the lamp first, then the diary, then your locket, then your music, then your dagger, then your doll, then the key, and finally the chalice. I can't possibly make it clearer than that.'\n");
				}
	}
	
	return 4;
}
Feature28::~Feature28() {
	
}
