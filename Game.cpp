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
	printf("Rooms We Have: %s, %s", room_1.get_name().c_str(), room_2.get_name().c_str());
	r_array[0]=room_1;
	r_array[1]=room_2;
	prompt_1 = "What do you want to do?\n TEMP CONTROLS: to toggle feature 1 and any of the other 10 personal action items with a0-9, feature 2 with a0_9, objects with c0_8\n";
	init_objects();
	//update room description based on objects within it
		
	
	
	
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
	printf("Current location is %i", player1.current_location);
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
	printf("\n%s", x_array);
	//printf("%i", strlen(x_array));
	
	int match_count = 0;
	int flag = 0;
	string the_exit = r_array[player1.current_location].get_exit();
	for (int i = 0; i < count; i++)
	{
		if (x_array[i]==the_exit[i])
		{
			match_count = match_count + 1;
		}
		else if (flag == 0)
		{
			flag = 1;
		}
	}
	printf("%s vs %s\n", x_array, the_exit.c_str());
	if (flag == 0){
		
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
	if (x_array[0]=='a'){
		printf("toggling data");
		Feature x = r_array[player1.current_location].get_feature_1();
		printf("int:  %i end", x_array[1] - '0');
		x.verbx(x_array[1] - '0');
		r_array[player1.current_location].set_feature_1(x);
	}
	if (x_array[0]=='b'){
			printf("toggling data");
			Feature x = r_array[player1.current_location].get_feature_2();
			printf("int:  %i end", x_array[1] - '0');
			x.verbx(x_array[1] - '0');
			r_array[player1.current_location].set_feature_1(x);
		}
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
void Game::init_verbs()
{
	//required verbs
	look="look";
	look_at_x="look at";
	exit_1="exit_1";
	exit_2="exit_2";
	exit_3="exit_3";
	exit_4="exit_4";
	take="take";
	help="help";
	inventory="inventory";
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