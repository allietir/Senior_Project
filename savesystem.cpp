#ifdef _WIN64
#include <dirent.h>
#endif

#include <string>
#include <fstream>
#include <ctime>
#include <iostream>

#include "savesystem.h"
#include "Game.h"

using namespace std;

//Saves the game to a file
void save_game(Game& game) { 

/*Placeholder for defining different filepath operations depending on OS.
This is an optional implementation so will be left out but can be considered
to be an extra feature if time permits.*/
/*#ifdef _WIN64
struct dirent file_iterator;

DIR *dir = opendir(filename_path)

while ((file_iterator = readdir(dir)) != NULL) {
	cout << file_iterator->d_name << endl;
}
closedir(dir);
#elif __unix__
#endif*/

	//Use time since epoch to generate a unique ID for savefile name
	//This is later shortened using the substr() method.
	time_t raw_time;
	raw_time = time(NULL);

	/****These lines will only work on linux! Comment out or copy and change when testing on Windows.****/
	//Create directory if it does not already exist.
	const char mkdir_command[32] = "mkdir -p SaveData";
	system(mkdir_command);

	/****The path name will have to be modified depending on testing environment.****/
	string filename_path = "SaveData/" + game.get_player()->get_name() + to_string(raw_time).substr(5);

	ofstream save_file(filename_path);
	if (save_file.is_open())
	{
		//write game data to save_file
		save_file << get_game_data(game);
		save_file.close();
		printf("Game saved successfully.\n");
	}
	else
	{
		printf("Unable to save game.\n");
	}

}

//Retrieves all game data and concatenates it into a single large string
//Function is typed in this manner to increase readability.
string get_game_data(Game& game) {

	string game_data = "";

	string player_name = "";
	string rooms_visited = "";
	string game_events = "";
	string room_events = "";
	string room_objects = "";
	string player_objects = "";

	int current_room = -1;

	//use helper functions to obtain data
	player_name =		game.get_player()->get_name();
	current_room =		game.get_player()->get_current_room();
	rooms_visited =		game.get_all_times_rooms_visited();
	game_events =		game.get_all_game_events_triggered();
	room_events =		game.get_all_room_events_triggered();
	room_objects =		game.get_all_room_objects();
	player_objects =	game.get_all_player_objects();

	//concatenate strings into one large string
	game_data = player_name + "\n"
				+ to_string(current_room) + "\n"
				+ rooms_visited + "\n" 
				+ game_events + "\n"
				+ room_events + "\n"
				+ room_objects + "\n"
				+ player_objects + "\n";

	return game_data;

}

//Loads a game save file through user prompts
//The user must manually type in the name of the save file
void load_game(Game& game) {

	//user input buffer for filename
	string file_name = "";

	/****These lines will only work on linux! Comment out or copy and change when testing on Windows.****/
	//Create directory if it does not already exist.
	const char mkdir_command[32] = "mkdir -p SaveData";
	system(mkdir_command);

	/****These lines will only work on linux! Comment out or copy and change when testing on Windows.****/
	printf("Available save files:\n");
	const char ls_command[32] = "ls SaveData";
	system(ls_command);

	printf("Please type the name of the saved file you wish to load.\n");
	getline(cin, file_name);

	/****The path name will have to be modified depending on testing environment.****/
	//The final game is intended to be run on the school Linux servers, make sure
	//it is changed to this: file_name = "SaveData/" + file_name;
	file_name = "SaveData/" + file_name;

	//user yes/no input buffer
	string prompt = "";

	ifstream save_file(file_name);
	if (save_file.is_open())
	{
		printf("Saved file is ready to load.\nYou will lose all unsaved progress by loading this file.\n");
		printf("Do you want to continue? (yes/no) ");
		getline(cin, prompt);
		if (prompt == "yes" || prompt == "Yes")
		{
			//Load the game data
			set_game_data(game, save_file);
			save_file.close();

			printf("Game loaded successfully.\n");

			printf("\nWelcome back, %s.\n\n", game.get_player()->get_name().c_str());
		}
		else if (prompt == "no" || prompt == "No")
		{
			//should return to "What would you like to do?" prompt
			printf("Returning to game...\n");
			return;
		}
		else
		{
			//should return to "What would you like to do?" prompt
			printf("Input not recognized. Returning to game...\n");
			return;
		}
	}
	else
	{
		//should return to "What would you like to do?" prompt
		printf("Saved file not recognized. Returning to game...\n");
	}

}

//Loads all game data from the file passed to it.
void set_game_data(Game& game, ifstream& save_file) {

	string next_line = "";

	//Initialize int arrays for setters
	int rooms_visited[NUM_ROOMS] = { 0 };
	int game_events[NUM_GAME_EVENTS] = { 0 };
	int room_events[NUM_EVENTS] = { 0 };
	int room_objects[NUM_OBJECTS] = { 0 };
	int player_objects[NUM_OBJECTS] = { 0 };

	//Player name
	getline(save_file, next_line);
	game.get_player()->set_name(next_line);

	//Player current room
	getline(save_file, next_line);
	game.get_player()->set_current_room(stoi(next_line));

	//All times rooms visited
	getline(save_file, next_line);
	printf("rooms_visited: %s\n", next_line.c_str());
	convert_string_to_array(rooms_visited, next_line, NUM_ROOMS);
	game.set_all_times_rooms_visited(rooms_visited);

	//All game events triggered
	getline(save_file, next_line);
	printf("game_events: %s\n", next_line.c_str());
	convert_string_to_array(game_events, next_line, NUM_GAME_EVENTS);
	game.set_all_game_events_triggered(game_events);

	//All room events triggered
	getline(save_file, next_line);
	printf("room_events: %s\n", next_line.c_str());
	convert_string_to_array(room_events, next_line, NUM_EVENTS);
	game.set_all_room_events_triggered(room_events);

	//All room objects
	getline(save_file, next_line);
	printf("room_objects: %s\n", next_line.c_str());
	convert_string_to_array(room_objects, next_line, NUM_OBJECTS);
	game.set_all_room_objects(room_objects);

	//All player objects
	getline(save_file, next_line);
	printf("player_objects: %s\n", next_line.c_str());
	convert_string_to_array(player_objects, next_line, NUM_OBJECTS);
	game.set_all_player_objects(player_objects);

}

//Converts a string to integers and fills them into the passed array.
void convert_string_to_array(int* arr, string str, int num_items) {

	printf("num_items: %i\n", num_items);
	int j = 0;
	char new_num[100]={'\0'};
	str = str + 'x';
	//printf("str_arr %s\n", str_arr);
	
	string new_num_str="";
	
	int num_index = 0;
	
	//string buffer = "";
	printf("A: %s\n", str.c_str());
	for (int i = 0; i <str.length(); i++)
	{
		//printf("==========converting %c======\n", str[i]);
//		if (str[i] == ',' || str[i] == ' ' )
//		{
//			buffer.clear();
//		}
//		else 
//		{
//			buffer = buffer + str[i];
//			
//			if (str[i + 1] == ',' || str[i + 1] == '\0')
////			if (str[i + 1] == ',')
//			{
//				arr[j] = stoi(buffer);
//				j++;
//			}
//		}
		//if you encounter a number
		if ((str[i]!=',')&&(str[i]!=' ')&&(str[i]!='x')){
			new_num[num_index]=str[i];
			
			num_index++;
		}
		if (j<=num_items-1){
			if ((str[i]==',')||(str[i]=='x')){
				//new_num_str = new_num;
				//printf("j is %i: ", j);
				//printf("new_num: %s\n", new_num);
				
				arr[j]=stoi(new_num);
				//printf("arr[j]:: %i\n", arr[j]);
				num_index = 0;
				new_num[0]='\0';
				new_num[1]='\0';
				
				j++;
			}
		}
		
		
		
	}
	printf("B: ");
	for (int i = 0; i < num_items; i++){
		if (i!=num_items-1){
			printf("%i, ", arr[i]);
		}
		else{
			printf("%i\n", arr[i]);

		}
	}


}

/*****This will only work on Linux*****/
//This is a testing function with modified code from the other save load functions.
//It saves the game, loads it, saves it again, then compares the two save files.
bool save_load_test(Game& game) {

	/**1. SAVE CURRENT GAME STATE**/
	printf("=====testing this===\n");
	//Create directory if it does not already exist.
	const char mkdir_command[32] = "mkdir -p SaveData";
	system(mkdir_command);

	//Remove old saves from to keep the directory clean
	const char rm_old_saves[64] = "rm -f SaveData/Anonymous*";
	system(rm_old_saves);

	/****The path name will have to be modified depending on testing environment.****/
	string filename_path_one = "SaveData/" + game.get_player()->get_name() + "1";

	ofstream first_save_file(filename_path_one);
	if (first_save_file.is_open())
	{
		//write game data to save_file
		first_save_file << get_game_data(game);
		first_save_file.close();
	}
	else
	{
		return false;
	}

	/**2. LOAD SAVED FILE**/

	//prompt is yes for testing purposes, that way we do not have to modify the if branches
	string prompt = "yes";

	ifstream load_file(filename_path_one);
	if (load_file.is_open())
	{
		if (prompt == "yes" || prompt == "Yes")
		{
			//Load the game data
			set_game_data(game, load_file);
			load_file.close();
		}
		else
		{
			//should return to "What would you like to do?" prompt
			return false;
		}
	}
	else
	{
		//should return to "What would you like to do?" prompt
	}

	/**3. SAVE THE GAME STATE AGAIN**/

	/****The path name will have to be modified depending on testing environment.****/
	string filename_path_two = "SaveData/" + game.get_player()->get_name() + "2";

	ofstream second_save_file(filename_path_two);
	if (second_save_file.is_open())
	{
		//write game data to save_file
		second_save_file << get_game_data(game);
		second_save_file.close();
	}
	else
	{
		return false;
	}


	/**4. COMPARE BOTH SAVE FILES**/
	
	string diff_string = "diff " + filename_path_one + " " + filename_path_two;
	//must convert the string to const char * for system()
	const char *diff_command = diff_string.c_str();

	int result = system(diff_command);

	if (result != 0)
	{
		return false;
	}
	else
	{
		return true;
	}

}

/*This is the test oracle code used within main.cpp to keep a record of it.*/
/*
int success = 0;
int total = 0;

if (save_load_test(Game& game) == true) 
{
	printf("Savefiles match. save_load_test = SUCCESS\n");
	success++;
}
else
{
	printf("Savefiles do not match. save_load_test = FAIL\n");
}
total++;

printf("save_load_test report: %d out of %d tests passed", success, total);
*/