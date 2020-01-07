//
// Game.cpp
// Created by Claudia Rodriguez-Schroeder on 1/2/20.

#include "Game.h"

#include <cstdio>

#include <string>
Game::Game() {
	
}
void Game::initialize_rooms() {
	
	/*room = new Room[15];
	string name_array[]={"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o"};
	printf("ROOM: %p\n", room);
	for (int i = 0; i < 15; i ++){
		Room room_n;
		room[i]=room_n;
		room[i].set_name(name_array[i]);
		printf("%s", room[i].get_name().c_str());
	}*/
	//printf("Rooms We Have: %s, %s\n", room_1.get_name().c_str(), room_2.get_name().c_str());
	r_array[0]=room_1;
	r_array[1]=room_2;
	r_array[2]=room_3;
	r_array[3]=room_4;
	r_array[4]=room_5;
	r_array[5]=room_6;
	r_array[6]=room_7;
	r_array[7]=room_8;
	r_array[8]=room_9;
	r_array[9]=room_10;
	r_array[10]=room_11;
	r_array[11]=room_12;
	r_array[12]=room_13;
	r_array[13]=room_14;
	r_array[14]=room_15;
	
	for (int i = 0; i < 15; i++){
		r_array[i].set_room_entered(0);
		//setting exit;
		//printf("setting exit\n");
		r_array[i].set_exit("exit_"+to_string(i+1)+"\0");
		r_array[i].set_exit_dir("direction x");
		r_array[i].init_exits();
		r_array[i].init_long_short_desc();
		if (i!=14){
			r_array[i].set_next_room(i+1);
		}
		else {
			r_array[i].set_next_room(0);
		}
	}
	
	prompt_1 = "What do you want to do?\n TEMP CONTROLS: to toggle feature 1 and any of the other 10 personal action items with a0-9, feature 2 with a0_9, objects with c0_8\n";
	init_objects();
	init_verbs();

	//update room description based on objects within it
		
	
	
	
}
void Game::get_help(){
	
	for (int i = 0; i < 10; i++){
		printf("%s\n", verb_x[i].c_str());
	}
	for (int i = 0; i < 10; i++){
			printf("%s\n", req_verb[i].c_str());
		}
}
void Game::init_objects()
{
	//init has items for each room
	for (int i = 0; i < 15; i++){
		r_array[i].set_all_has_items(0);
	}
	for (int i = 0; i < 8; i++){
		
		o_array[i].name = "object"+to_string(i);
		o_array[i].description = " object" +to_string(i)+ " description."+to_string(i);
		o_array[i].current_room = 0;	
		o_array[i].index_id = i;
		
		string new_desc = r_array[o_array[i].current_room].get_long_description() + "YOU SEE: " + o_array[i].description + "\n";
		r_array[o_array[i].current_room].set_long_description(new_desc);
		
	}
	//init has items for each room
	for (int i = 0; i < 15; i++){
		r_array[i].set_all_has_items(0);
		for (int j = 0; j < 8; j++){
			if (o_array[j].current_room == i)
			{
				r_array[i].toggle_has_items(j);
			}
		}
	}
	
}
void Game::start(){
	
	printf("Welcome %s\n", player1.name.c_str());
	printf("Current location is %s\n", r_array[player1.current_location].get_name().c_str());
	string sd = r_array[player1.current_location].get_long_description();
	r_array[player1.current_location].set_room_entered(1);
	printf("%s", sd.c_str());
	get_input(prompt_1, 100);

	
	
}
void Game::get_input(string prompt, int input_size){
	
	printf("%s", prompt.c_str());
	char x;
	//printf("%c", x);
	char x_array[input_size];
	memset(x_array, '\0', sizeof(x_array));
	
	int count = 0;
	while ((x!='\n')&&(count <= input_size-2)){
		x = fgetc(stdin);
		if ((x!='\n')&&(count<=input_size-1)){
			x_array[count]=x;
		}
		
		count = count + 1;
		//printf("count:%i", count);
		printf("%c", x);
		
	}
	printf("x: %c", x);
	printf("count: %i", count);
	if (count <=input_size-1){
		x_array[count]='\0';
	}
	printf("\n%s\n", x_array);
	//printf("%i", strlen(x_array));
	
	int match_count = 0;
	int exit_flag = 1;
	string the_exit = r_array[player1.current_location].get_exit();
	for (int i = 0; i < count; i++)
	{
		if (x_array[i]==the_exit[i])
		{
			match_count = match_count + 1;
		}
		else if (exit_flag == 1)
		{
			exit_flag = 0;
		}
		
	}
	match_count = 0;
	int save_flag = 0;
	/*for (int i = 0; i < count; i++)
	{
		if (x_array[i]==save_text[i])
		{
			match_count = match_count + 1;
		}
		else if (save_flag == 0)
		{
			save_flag = 1;
		}
		
	}*/
	if (save_text.compare(x_array)==0){
		printf("RUN SAVE PROTOCOL");
	}
	
//	printf("%s vs %s\n", x_array, the_exit.c_str());
	//CLAUDIA TO RYAN: map this flag to all four exit description states
	if (exit_flag == 1){
		
		printf("Next room is %i\n", r_array[player1.current_location].get_next_room());
		player1.current_location = r_array[player1.current_location].get_next_room();
		
		printf("Now in %s\n", r_array[player1.current_location].get_name().c_str());
		
		if (r_array[player1.current_location].get_room_entered()==0){
			printf("Setting room to just entered\n");
			r_array[player1.current_location].set_room_entered(1);
			printf("%s", r_array[player1.current_location].get_long_description().c_str());
		}
		else{
			printf("This room was entered before\n");
			printf("%s", r_array[player1.current_location].get_short_description().c_str());
		}
		
		
		
	}
	//if input matches any combination of verbs or features, i.e. "verb1 Room1.feature1" run the function feature1.verb1
	//example= to toggle feature 1 and any of the other 10 personal action items with a0-9, beature 2 with a0_9, objects with c0_8
	if (help.compare(x_array)==0){
		printf("VERB LIST:\n");
		get_help();
	}
	if (look.compare(x_array)==0){
		printf("COMPARE value: %i", look.compare(x_array));
		printf("%s", r_array[player1.current_location].get_long_description().c_str());
	}
	if (inventory.compare(x_array)==0){
			printf("COMPARE value: %i", inventory.compare(x_array));
			int item_count = 0;
			for (int i = 0; i < 8; i++){
				//if player has this item...
				if (player1.get_has_items(i)==1)
				{
					printf("ITEM: %s\n", o_array[i].name.c_str());
					item_count++;
				}
			}
			if (item_count == 0){
				printf("%s has no items in inventory", player1.name.c_str());
			}
		}
	//CLAUDIA TO RYAN: 
	//LOOK AT object x: call
	// x.description; (works for objects AND features)
	
	
	//CLAUDIA RYAN: EXAMPEL:verbx feature1 i.e. "touch feature"; 
	//step 1: search x.verb_list for verbx and account for the INDEX i.e. if "touch" is the 3'rd verb index is 2
	//this will toggle the attribute to an ALT attribute
	if (x_array[0]=='a'){
		printf("toggling data");
		Feature x = r_array[player1.current_location].get_feature_1();
		printf("int:  %i end", x_array[1] - '0');
		x.verbx(x_array[1] - '0');
		r_array[player1.current_location].set_feature_1(x);
	}
	//same logic
	if (x_array[0]=='b'){
			printf("toggling data");
			Feature x = r_array[player1.current_location].get_feature_2();
			printf("int:  %i end", x_array[1] - '0');
			x.verbx(x_array[1] - '0');
			r_array[player1.current_location].set_feature_1(x);
		}
	//CLAUDIA TO RYAN: logic here is "TAKE object'. get object name and parse to find index, then apply toggle accordingyl
	if (x_array[0]=='c'){
			printf("toggling object");
			//check if object o_array[x_array[1] - '0'] is within the room you are currently in 
			if (o_array[x_array[1]-'0'].current_room == player1.current_location)
			{
				//if it does have it, the toggle will turn it off
				r_array[player1.current_location].toggle_has_items(x_array[1]-'0');
				o_array[x_array[1]-'0'].current_room = -1;
				//update currnet room of object
				if (r_array[player1.current_location].get_has_items(x_array[1]-'0')==0){
					printf("%s NO LONGER has item %s\n", r_array[player1.current_location].get_name().c_str(), o_array[x_array[1]-'0'].name.c_str());
					
				}
				else {
					printf("ERROR in getting item from room\n");
				}
				//the toggle will turn the items to on so that the player has that item
				player1.toggle_has_items(x_array[1]-'0');
				//dialog to explain what has ocured with the items. 
				if (player1.get_has_items(x_array[1]-'0')==1){
					printf("%s has item %s\n", player1.name.c_str(), o_array[x_array[1]-'0'].name.c_str());
				}
				else{
					printf("ERROR in getting item from room\n");
				}
				
			}
			//check if player has item
			//if player has item, this action untoggles player and PLACES IT IN WHATEVER ROOM THE PLAYER IS IN
			else if (player1.get_has_items(x_array[1]-'0')==1){
				player1.toggle_has_items(x_array[1]-'0');
				if (player1.get_has_items(x_array[1]-'0')==0){
					printf("%s NO LONGER HAS item %s", player1.name.c_str(), o_array[x_array[1]-'0'].name.c_str());
				}
				printf("Value of has-items for room %s: %i", r_array[player1.current_location].get_name().c_str(), r_array[player1.current_location].get_has_items(x_array[1]-'0'));
				r_array[player1.current_location].toggle_has_items(x_array[1]-'0');
				//set player to having the current location of the room
				o_array[x_array[1]-'0'].current_room = player1.current_location;
				if (r_array[player1.current_location].get_has_items(x_array[1]-'0')==1){
					printf("%s NOW has item %s\n", r_array[player1.current_location].get_name().c_str(), o_array[x_array[1]-'0'].name.c_str());
				}
				else {
					printf("ERROR in dropping item into room\n");
				}
				
			}
			
			
		}
		
}
void Game::load(string file_name){
	//CONFIRM WITH USER THAT "loadgame" is really what the user wants to do
	
	printf("LOADING GAME FROM FILE\n");
}
void Game::init_verbs()
{
	//required verbs
	save_text = "savegame\0";
	inventory = "inventory\0";
	take = "take\0";
	look= "look\0";
	help = "help\0";
	load_text = "loadgame\0";
	look_at_x="look at";


	exit_1 = "go <exit_direction>";
	exit_2 = "<exit_direction>";
	exit_3 = "go <exit>";
	exit_4 = "<exit>";
	
	
	req_verb[0]=look;
	req_verb[1]=look_at_x;
	req_verb[2]=take;
	req_verb[3]=help;
	req_verb[4]=inventory;
	req_verb[5]=exit_1;
	req_verb[6]=exit_2;
	req_verb[7]=exit_3;
	req_verb[8]=exit_4;
	req_verb[9]=save_text;
	req_verb[10]=load_text;
	//10 primary actions
	/*verb1="verb1";
	verb2="verb2";
	verb3="verb3";
	verb4="verb4";
	verb5="verb5";
	verb6="verb6";
	verb7="verb7";
	verb8="verb8";
	verb9="verb9";
	verb10="verb10";*/
	verb_x[0]="verb1";
	verb_x[1]="verb2";
	verb_x[2]="verb3";
	verb_x[3]="verb4";
	verb_x[4]="verb5";
	verb_x[5]="verb6";
	verb_x[6]="verb7";
	verb_x[7]="verb8";
	verb_x[8]="verb9";
	verb_x[9]="verb10";
	
	
	
}
void Game::get_next_step(){
	get_input(prompt_1, 100);
	
}
Game::~Game() {

}