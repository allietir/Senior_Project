// savesystem.h
// functions used savesystem

#ifndef _savesystem_h_
#define _savesystem_h_

#include <string>

#include "Game.h"

void save_game(Game& game);
void load_game(Game& game);

string get_game_data(Game& game);
void set_game_data(Game& game, ifstream& save_file);

void convert_string_to_array(int* arr, string str, int num_items);

bool save_load_test(Game& game);

bool save_load_test(Game& game);

#endif