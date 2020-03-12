//
// Feature21.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Feature21.h"

Feature21::Feature21() {
	set_name("\033[1;31mBookshelf\033[0m");
	set_desc("There is a single \033[1;31mbookshelf\033[0m in the \033[0;36mlibrary\033[0m.\nThere are a few books on there, but there is a peculiar quality to them. What makes this \033[1;31mbookshelf\033[0m so strange? There is a \033[1;35mkey\033[0m on the shelf. ");
	set_desc_no_obj("There is a single \033[1;31mbookshelf\033[0m in the \033[0;36mlibrary\033[0m.\nThere are a few books on there, but there is a peculiar quality to them. What makes this \033[1;31mbookshelf\033[0m so strange? ");
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
		printf("You read the following text: Welcome to the magic of non-verbal spells.\n By reading these words, the closest book to you will now carry the live knowledge within this book. Go ahead, read it again! ");
		return 40;
		
	}	
	else{
		printf("The book case has an emblem that says the follwing: 'First, use the diary with me. Then, speak the spell to me. Finally, read the new secrets upon me'");
	}
	
	return 4;
}
int Feature21::use(int obj_feat_obj){
	if (get_times_toggled(USE)==0){
		if (obj_feat_obj==DIARY){
				func_togg_count_x(USE);
				printf("You open the helpful \033[1;35mdiary\033[0m and see the words arrange themselves on the page.\n\t\"Ah, I see you have found the library books.\nSpeak this incantation over the bookshelf to reveal the secrets of the house:\n\t\'Infra dignitatem ostendere.\'\n\tIt's a fiddly spell, though. You may have to speak the spell and read the books more than once to gain all their secrets\". ");
				
			}
			else if (obj_feat_obj==-1){
				printf("Maybe you should try using an object with the bookshelf. ");
			}
			else{
				printf("Hmm, perhaps another object would be better to use with the bookshelf. ");
				
			}
	}
	else{
		printf("You've already used the \033[1;35mdiary\033[0m with this bookshelf, and revealed its secrets. You can read them again if you wish. ");
	}
	return 4;
	
}
int Feature21::speak(){
	if ((get_times_toggled(SPEAK)==0)&&(get_times_toggled(USE)==1)){
		func_togg_count_x(SPEAK);
		printf("You speak the spell as the \033[1;35mdiary\033[0m requested, once, and a book floats out out of the shelf and reveals itself to you. ");
	}
	else if ((get_times_toggled(SPEAK)==1)&&(get_times_toggled(USE)==1)){
		func_togg_count_x(SPEAK);
		printf("You speak the spell as the \033[1;35mdiary\033[0m requested, a second time, and the same book shimmers briefly, before changing the text. ");
	}
	else if ((get_times_toggled(SPEAK)==2)&&(get_times_toggled(USE)==1)){
		func_togg_count_x(SPEAK);
		printf("You speak the spell as the \033[1;35mdiary\033[0m requested, a third time, and the same book sparkles before the text changes. ");
	}
	else if ((get_times_toggled(SPEAK)==3)&&(get_times_toggled(USE)==1)){
		func_togg_count_x(SPEAK);
		set_togg_count_x(SPEAK, 0);
		printf("You speak the spell again, but this causes all the books to fly back onto the shelf. You suppose the bookshelf has given up all the secrets it is willing to give. ");
	}
	else{
		printf("I want to listen, but I need the right words. Perhaps there is some object you can use with me to reveal my secrets.");
	}

	return 4;

}
	
Feature21::~Feature21() {
	
}
