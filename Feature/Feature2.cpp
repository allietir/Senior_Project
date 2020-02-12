//
// Feature2.cpp
// Created by Claudia Rodriguez-Schroeder on 1/25/20.

#include "Feature2.h"

Feature2::Feature2() {
	set_name("Tree");
	desc1 = "A large, gnarled looking black tree without a single leaf. It seems to be as tall as the second floor.The branches seem to poke almost directly into the open window of the second story.\n";
	set_desc(desc1);//
	set_desc_no_obj(desc1);
	set_index_id(1);
	set_attack_obj_id(4);
	
}

int Feature2::climb(){
	if (get_times_toggled(CLIMB)==0){
		printf("You climb up the tree and the branch extends int the second story window is open. The room is so dark but it looks like a master bedroom. If you climb a little more you would be able to get into the room.\n");
		func_togg_count_x(8);
		return -2;//indicate to Game that you are not able to do other things.
	}
	else if (get_times_toggled(CLIMB)==1){
		printf("You climb accross the rest of the branch and get into the room.\n");
		set_togg_count_x(CLIMB, 0);
		return 17;
	}
	return 5;
}

int Feature2::read(){
	if (get_times_toggled(READ)==0){
		printf("This tree is not yet a book, so you cannot read it. \n");
		func_togg_count_x(READ);
		return 4;
	}
	else
	{
		printf("I know you want to read this, but you can't. It's a tree. Books are made from trees, and you can read those. Perhaps you'll find a book soon.\n");
		func_togg_count_x(READ);
		return 4;
	} 
}
int Feature2::smell(){
	
	printf("The tree smells earthy; it looks cold and gnarled, but it smells alive, like sap and new life\n");
	func_togg_count_x(SMELL);
	return 4;
	
}
int Feature2::attack(int obj_feat_id){
	printf("obj_feat_id: %i", obj_feat_id);
	if (obj_feat_id==get_attack_obj_id())
	{
		printf("You have attacked with the %s.", get_obj_name(obj_feat_id).c_str());
		return 1;
	}
	else{
		printf("Attcking with the %s does nothing. \n", get_obj_name(obj_feat_id).c_str());
		return 4;
	}
	return 4;
	
}
int eat();
int play();
int open(int room_id, int obj_feat_id);
int speak();
int give(int room_id, int obj_feat_id);
Feature2::~Feature2() {
	
}
