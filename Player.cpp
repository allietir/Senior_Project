//
// Player.cpp
// Created by Claudia Rodriguez-Schroeder on 1/2/20.

#include "Player.h"
#include <string>
#include <cstdio>

Player::Player() {
	name = "Claudia";
	current_location = 0;
	for (int i=0; i < 8; i++){
		has_items[i]=0;
	}
}
void Player::move(int room_id){
	current_location = room_id;
	
}
void Player::toggle_has_items(int is_has_item){
	if (has_items[is_has_item]==0){
		has_items[is_has_item]=1;
	}
	else {
		has_items[is_has_item]=0;
	}
}

int Player::get_has_items(int is_has_item){
	return has_items[is_has_item];
}
Player::~Player() {
	
}