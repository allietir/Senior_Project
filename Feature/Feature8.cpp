//
// Feature8.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Feature8.h"

Feature8::Feature8() {
	set_name("Table");
	set_desc("An elaborate banquate appears before you; the table is laden with a centerpiece of fruit, and several delicious smelling dishes. There are about 10 places set. However, when you try to step forward to further look at the setting, everything fades away like a mirage. It looks like there is a single book placed at the edge of the table.");
	set_index_id(7);
}
int Feature8::read(){
	printf("There is nothing to read on the table, not even the expression on the creatures face. Because he is faceless.\n");		
	return 0;
}
int Feature8::smell(){
	if (get_times_toggled(2)==0){
		printf("You try to smell the food and almost faint from how delicious it smells. You clutch the talbe for support. It seems to upset some of the items on the table slightly, and you catch a glint of a ring on the center of the table. You consider taking the ring and giving it to the creauture, but that seems foolish. If you smell the table again, you may be able to get the ring to jostle to the the front of the monster.\n");	
			func_togg_count_x(1);
	}
	else if (get_times_toggled(2)==1){
		printf("You take another whiff again, and this seems to justle the ring towards the monster. The monster clutches at the ring. You wait in terror.\n");	
	}
	return 2;//return event # being triggered		
}
int Feature8::use(){
	if (get_times_toggled(1)==1){
		printf("The ring jostles back to its original position. Oops.\n");
		set_togg_count_x(1, 0);
		func_togg_count_x(2);
	}
	return 4;
}

Feature8::~Feature8() {
	
}
