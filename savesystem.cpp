#include <string>
#include <fstream>
#include <ctime>
#include <iostream>


#include "savesystem.h"
#include "Game.h"

using namespace std;

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

void save_game(Game& game) {

	time_t raw_time;
	raw_time = time(NULL);

	/****The path name will have to be modified depending on testing environment.****/
	string filename_path = "SaveData/" + game.get_player()->get_name() + to_string(raw_time);

	ofstream save_file(filename_path);
	if (save_file.is_open())
	{
		save_file << get_game_data(game);
		save_file.close();
		printf("Game saved successfully.\n");
	}
	else
	{
		printf("Unable to save game.\n");
	}

}

void load_game(Game& game) {

	string file_name = "";

	/****These lines will only work on linux! Comment out or copy and change when testing on Windows.****/
	printf("Available save files:\n");
	const char command[32] = "ls SaveData";
	system(command);

	printf("Please type the name of the saved file you wish to load.\n");
	getline(cin, file_name);

	/****The path name will have to be modified depending on testing environment.****/
	//The final game is intended to be run on the school Linux servers, make sure
	//it is changed to this: file_name = "SaveData" + file_name;
	file_name = "SaveData" + file_name;

	string prompt = "";

	ifstream save_file(file_name);
	if (save_file.is_open())
	{
		printf("Saved file is ready to load.\nYou will lose all unsaved progress by loading this file.\n");
		printf("Do you want to continue? (yes/no) ");
		getline(cin, prompt);
		if (prompt == "yes" || prompt == "Yes")
		{
			set_game_data(game, save_file);
			save_file.close();

			printf("Game loaded successfully.\n");

			printf("\nWelcome back, %s.\n\n", game.get_player()->get_name().c_str());
		}
		else if (prompt == "no" || prompt == "No")
		{
			printf("Returning to game...\n");
			return;
		}
		else
		{
			printf("Input not recognized. Returning to game...\n");
			return;
		}
	}
	else
	{
		printf("Saved file not recognized. Returning to game...\n");
	}
}

void convert_string_to_array(int* arr, string str) {

	int i;
	int j = 0;
	
	string buffer = "";

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ',' || str[i] == ' ')
		{
			buffer.clear();
		}
		else 
		{
			buffer = buffer + str[i];
			
			if (str[i + 1] == ',' || str[i + 1] == '\0')
			{
				arr[j] = stoi(buffer);
				j++;
			}
		}
	}

}

void set_game_data(Game& game, ifstream& save_file) {

	string next_line = "";

	int rooms_visited[NUM_ROOMS] = { 0 };
	int game_events[NUM_GAME_EVENTS] = { 0 };
	int room_events[NUM_EVENTS] = { 0 };
	int room_objects[NUM_OBJECTS] = { 0 };
	int player_objects[NUM_OBJECTS] = { 0 };

	getline(save_file, next_line);
	game.get_player()->set_name(next_line);

	getline(save_file, next_line);
	game.get_player()->set_current_room(stoi(next_line));

	getline(save_file, next_line);
	convert_string_to_array(rooms_visited, next_line);
	game.set_all_times_rooms_visited(rooms_visited);

	getline(save_file, next_line);
	convert_string_to_array(game_events, next_line);
	game.set_all_game_events_triggered(game_events);

	getline(save_file, next_line);
	cout << next_line << endl;
	convert_string_to_array(room_events, next_line);
	game.set_all_room_events_triggered(room_events);

	getline(save_file, next_line);
	convert_string_to_array(room_objects, next_line);
	game.set_all_room_objects(room_objects);

	getline(save_file, next_line);
	convert_string_to_array(player_objects, next_line);
	game.set_all_player_objects(player_objects);

}