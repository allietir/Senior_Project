//
// Room4.h
// Created by Claudia Rodriguez-Schroeder on 1/3/20.

#ifndef _Room4_h_
#define _Room4_h_
#include "Room.h"
#include "../Feature/Feature8.h"
#include "../Feature/Feature7.h"

class Room4: public Room {
public:
	Room4();
	int event_one();
	int event_two();
	int event_three();
	virtual ~Room4();	
};

#endif
