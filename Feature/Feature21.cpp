//
// Feature21.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Feature21.h"

Feature21::Feature21() {
	set_name("\033[1;31mBookshelf\033[0m");
	set_desc("There is a single \033[1;31mbookshelf\033[0m in the library\nThere are a few books on there, but there is a peculiar quality to them. What makes this \033[1;31mbookshelf\033[0m so strange? There is a \033[1;35mkey\033[0m on the shelf.");
	set_desc_no_obj("There is a single \033[1;31mbookshelf\033[0m in the library\nThere are a few books on there, but there is a peculiar quality to them. What makes this \033[1;31mbookshelf\033[0m so strange?.");
	set_index_id(20);
}
int Feature21::read(){
	

	if ((get_times_toggled(READ)==0)&&(get_times_toggled(SPEAK)==1)){
		//
		func_togg_count_x(READ);
		return 38;
	}
	else if ((get_times_toggled(READ)==1)&&(get_times_toggled(SPEAK)==2)){
		//
		func_togg_count_x(READ);
		return 39;
	}
	else if ((get_times_toggled(READ)==2)&&(get_times_toggled(SPEAK)==3)){
		//
		set_togg_count_x(READ, 0);
		printf("You read the following text: Welcome to the magic of non-verbal spells.\n By reading these words, the closest book by you will now carry the live knowledge within this book. Go ahead, read it again!");
		return 40;
		
	}	
	
	return 4;
}
int Feature21::use(int obj_feat_obj){
	if (get_times_toggled(USE)==0){
		if (obj_feat_obj==DIARY){
				func_togg_count_x(USE);
				printf("You open the helpful diary and see the words arrange themselves on the page.\"Ah, I see you have found the library books.\nSpeak this incantation over the bookshelf to reveal the secrets of the house:\"\nInfra dignitatem ostendere.\n\"It's a fiddely spell, though. You may have to speak the spell and read the books more than once to gain all their secrets\".");
				
			}
	}
	else{
		printf("You've already used the diary with this bookshelf, and revelated its secrets. you can read them again, however.");
	}
	return 4;
	
}
int Feature21::speak(){
	if ((get_times_toggled(SPEAK)==0)&&(get_times_toggled(USE)==1)){
		func_togg_count_x(SPEAK);
		printf("You speak the spell as the diary requested, once, and a book floats out out of the shelf and reveals itself to you.");
	}
	else if ((get_times_toggled(SPEAK)==1)&&(get_times_toggled(USE)==1)){
		func_togg_count_x(SPEAK);
		printf("You speak the spell as the diary requested, a second time, and the same book shimmers briefly, before changing the text.");
	}
	else if ((get_times_toggled(SPEAK)==2)&&(get_times_toggled(USE)==1)){
		func_togg_count_x(SPEAK);
		printf("You speak the spell as the diary requested, a third time, and the same book sparkles before the text changes.  ");
	}
	else if ((get_times_toggled(SPEAK)==3)&&(get_times_toggled(USE)==1)){
		func_togg_count_x(SPEAK);
		set_togg_count_x(SPEAK, 0);
		printf("You speak the spell again, but this causes all the books to fly back onto the shelf. You suppose the bookshelf has given up all the secrets it is willing to. ");
	}

	return 4;

}
	
Feature21::~Feature21() {
	
}
