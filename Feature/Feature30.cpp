//
// Feature30.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Feature30.h"

Feature30::Feature30(){
	set_name("Demon");
	set_desc("There is a terrifying demon standing before you; the creatures eyes are huge, too big for a human face, and so red. Huge horns spiral out of the creatures head. The creatures seems both impossibly terrifying shadow and hot, horrible fire.\n");
	set_desc_no_obj(get_desc());
	set_index_id(29);
}
int Feature30::speak(){

	func_togg_count_x(SPEAK);
	printf("The demon speaks in a thundering tone:\n'Your friend has a darkness inside them and so they will be mine.'\n You say to the demon: \n'We all have both dark and light within us.'\n'Instead of bringing them to the dark, why can't you step into the light?'\nThe demon shudders.'It is too late for me. The one I loved chose another. I cannot bear to see the light of day.'\n");
	

	return 4;
}
int Feature30::attack(int obj_feat){
	//triggers open_locket
	if (obj_feat==DIARY){
		printf("You panic and open the diary, and seeing strange words written, begin to chant a spell:\naperire vas\naperire vas\naperire vas\nut daemonium in captionem\naperire vas\n");
		//triggers opening the lock
		return 35;
	}
	if (obj_feat==CHALICE){
		printf("You hold out the chalice and suddenly it yanks out of your hands without your control, like it is waiting for a cue. What are the right words to say next?\n");
		//requires that you read a different spell from the diary before it locks the demon in the locket
		return 36;
	}
	//attacking with the locket is the same as opening it; so we accept the locket attack as locket open.
	if (obj_feat==LOCKET){
		return 35;
	}
	if (obj_feat==DAGGER){
		printf("The demon snarles and claws the dagger out of your hand with his mighty hooved arm.\nYou're losing blood fast.\nYou aren't going to make it.\n");
		return -1;
	}
	return 4;
	
}
int Feature30::give(int event_occured, int obj_feat_id){
	//if this is called, this means that at this point the game was able to see that the chalice has something 
	if (obj_feat_id==CHALICE)
	{
		printf("The demon looks at the holy water in the chalice.\n.'Maybe some things are worth the pain of transformation'\nThe demon drinks the water and lets out a horrible shriek.\nThere are flashes of light throughout the room and you are forced to look away.\nWhen you are no longer blinded by the light, you look for a remnent of the creature, but the demon is utterly gone.\n");	
	}
	return 0;

}
Feature30::~Feature30() {
	
}
