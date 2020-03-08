//
// Feature22.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Feature22.h"

Feature22::Feature22() {
	set_name("\033[1;31mFireplace\033[0m");
	set_desc("There is a large \033[1;31mfireplace\033[0m in the library, but it doesn't appear to be lit. There's writing on the \033[1;31mfireplace\033[0m mantel.");
	set_index_id(21);
}
int Feature22::read(){
	func_togg_count_x(READ);
	printf("Fire transforms\nFire moves");
	return 4;
}
int Feature22::use(int obj_feat){
	if ((obj_feat==-1)&&(get_times_toggled(USE)==0)){
		func_togg_count_x(USE);
		printf("The \033[1;31mfireplace\033[0m turns on");
		set_desc("There is a large \033[1;31mfireplace\033[1;31m in the library, and there's a fire crackling within. There's writing on the \033[1;31mfireplace\033[0m mantel.");
		
	}
	else if ((obj_feat==-1)&&(get_times_toggled(USE)>=1)){
		set_togg_count_x(USE, 0);
		printf("The \033[1;31mfireplace\033[0m turns off.");
		set_desc("There is a large \033[1;31mfireplace\033[0m in the library, but it doesn't appear to be lit. There's writing on the \033[1;31mfireplace\033[0m mantel.");
	}
	//if fire is on and you want to speak 
	else if ((obj_feat==DIARY)&&(get_times_toggled(USE)==1)){
		func_togg_count_x(USE);
		printf("The fire shudders and crackles, and briefly turns purple; the \033[1;35mdiary\033[0m grows hot it in your hand, so hot you almost drop it.\n Then it flies open and reveals a spell to your eyes.\n You read it: 'Item ut in vicem dicere vessle fert ignis'");
		set_desc("The fire flickers and crackles; it is waiting for the next step. ");
			
	}
	else if ((obj_feat==CHALICE)&&(get_times_toggled(USE)==-666)){
		return 4;
	}
	return 4;
}
int Feature22::speak(){
	if (get_times_toggled(USE)==0){
		printf("You can say what you like to the fire, but it won't do anything interesting.\nPerhaps if you use some source of knowledge with it, you'll know something more.");
	}	
	else if (get_times_toggled(USE)>=2){
		printf("The fire almost leaps out of the fireplace before sparkling and turning purple; it emits a strange, grey blue smoke for a moment.");
		set_togg_count_x(USE, -666);
		set_desc("The fire emits a purple glow and throws occasional sparkles and blue smoke.");
	}
	return 4;
}

Feature22::~Feature22() {
	
}
