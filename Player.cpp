//
// Player.cpp
// Created by Claudia Rodriguez-Schroeder on 1/2/20.

#include "Player.h"
#include <string>
#include <cstdio>

Player::Player() {
	name = "Player1";
	current_room = 0;
	for (int i=0; i < NUM_OBJECTS; i++){
		has_objects[i]=0;
	}
	player_alive = 1;
	can_take = 1;
}
string Player::get_name(){
	return name;
}
void Player::set_name(string s_name)
{
	name = s_name;
}
int Player::get_has_objects(int item_index){
	return has_objects[item_index];
}
void Player::set_has_objects(int item_index, int val){
	has_objects[item_index]=val;
}
int Player::get_current_room(){
	return current_room;
}
void Player::set_current_room(int s_current_room){
	current_room = s_current_room;
}

int Player::get_move_count(){
	return move_count;
}
void Player::set_move_count(int s_move_count){
	move_count = s_move_count;
}
int Player::get_player_alive(){
	return player_alive;
}
void Player::set_player_alive(int val){
	player_alive = val;
} 
int Player::get_can_take(){
	return can_take;
}
void Player::set_can_take(int s_can_take){
	can_take = s_can_take;
}

int Player::get_saving(){
	return player_saving;
}
void Player::set_saving(int x){
	player_saving = x;
}
int Player::get_loading(){
	return player_loading;
}
void Player::set_loading(int x){
	player_loading = x;
}
	
Player::~Player() {
	
}