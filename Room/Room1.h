//
// Room1.h
// Created by Claudia Rodriguez-Schroeder on 1/3/20.

#ifndef _Room1_h_
#define _Room1_h_
#include "Room.h"
#include "../Feature/Feature2.h"
#include "../Feature/Feature1.h"//feature 1

class Room1: public Room {
public:
	Room1();
	int event_one();
	int event_two();
	int event_three();
	virtual ~Room1();	
	
};

#endif
