//
// Feature30.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Feature30.h"

Feature30::Feature30(){
	set_name("\033[1;31mDemon\033[0m");
	set_desc("There is a terrifying \033[1;31mdemon\033[0m standing before you; the creature's eyes are enormous and red. Terrifying horns spiral out of the creature's head. You cannot make out the creature's body for it appears to be composed of shadows and fire. ");
	set_desc_no_obj(get_desc());
	set_index_id(29);
}
int Feature30::speak(){

	if (get_times_toggled(SPEAK)==0){
		func_togg_count_x(SPEAK);
		printf("The \033[1;31mdemon\033[0m speaks in a thundering tone:\n\"Your friend has a darkness inside them that I will make mine.\"\n You say to the \033[1;31mdemon\033[0m: \n\"We all have both darkness and light within us.\nInstead of claiming them to the darkness, why not step into the light?\"\nThe \033[1;31mdemon\033[0m shudders.\"It is too late for me. The one I loved chose another. I cannot bear to see the light of another soul.\" ");
	}
	else if (get_times_toggled(SPEAK)==1){
		func_togg_count_x(SPEAK);
		printf("\"Who did you love?\" You ask. The \033[1;31mdemon's\033[0m eyes wander away from \033[1;31mAlex\033[0m and stops sucking the life force out of \033[1;31mAlex\033[0m.\n \"It doesn't matter. None of it matters anywmore.\" ");

	}
	else{
		printf("The \033[1;31mdemon\033[0m has nothing else to say. ");
	}
		

	return 4;
}
int Feature30::attack(int obj_feat){
	//triggers open_locket
	if (obj_feat==DIARY){
		printf("You panic and open the \033[1;35mdiary\033[0m, and seeing strange words written, begin to chant a spell:\'naperire vas\naperire vas\naperire vas\nut daemonium in captionem\naperire vas\' Oh my, it looks like this spell relates to your strange locket! ");
		//triggers opening the lock
		return 35;
	}
	if (obj_feat==CHALICE){
		printf("You hold out the \033[1;35mchalice\033[0m and it suddenly shoots out of your hand and levitates in front of you, like it is waiting for a command. What are the right words to say next? ");
		//requires that you read a different spell from the diary before it locks the demon in the locket
		return 36;
	}
	//attacking with the locket is the same as opening it; so we accept the locket attack as locket open.
	if (obj_feat==LOCKET){
		return 35;
	}
	if (obj_feat==DAGGER){
		printf("The \033[1;31mdemon\033[0m snarls and claws the \033[1;35mdagger\033[0m out of your hand with his mighty arm.\nYou're losing blood fast.\nYou aren't going to make it. ");
		return -1;
	}
	else{
		printf("This is not the way to attack the \033[1;31mdemon\033[0m. ");
	}
	return 4;
	
}
int Feature30::give(int event_occured, int obj_feat_id){
	//if this is called, this means that at this point the game was able to see that the chalice has something 
	if ((obj_feat_id==CHALICE)&&(event_occured==1))
	{
		set_togg_count_x(GIVE, 1);
		printf("The \033[1;31mdemon\033[0m looks at the holy water in the chalice.\n.\"Maybe some things are worth the pain.\"\nThe \033[1;31mdemon\033[0m drinks the water and lets out a horrible shriek.\nFirst, white light shines through its eyes, then light begins to flash from its body, forcing you to look away.\nWhen you are no longer blinded by the light, you look for the creature, but it is nowhere to be found. ");	
		return 0;
	}
	else{
		printf("You need to consider a different object to give the \033[1;31mdemon\033[0m; then again, maybe this is the right object, but must be transformed in some way. ");
		return 4;
	}
	return 4;
	

}
Feature30::~Feature30() {
	
}
