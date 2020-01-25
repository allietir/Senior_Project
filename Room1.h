//
// Room1.h
// Created by Claudia Rodriguez-Schroeder on 1/3/20.

#ifndef _Room1_h_
#define _Room1_h_
#include "Room.h"
#include "Gravestone.h"//feature 1
#include "globals.h"

class Room1: public Room {
public:
	Room1();
	virtual ~Room1();	
private:
	Gravestone feature_1;
	
};

#endif