//
// Object.h
// Created by Claudia Rodriguez-Schroeder on 1/5/20.

#ifndef _Object_h_
#define _Object_h_
#include <string>

using namespace std;

class Object {
public:
	Object();
	virtual ~Object();
//private
	string name;
	string description;
	int current_room;//if is -1 that means it is with the PLAYER
	int works_with_room[15];//1 if works with room
	int feature[2];//1 if works with feature
	
	
};

#endif