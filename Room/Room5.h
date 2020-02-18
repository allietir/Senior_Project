//
// Room5.h
// Created by Claudia Rodriguez-Schroeder on 1/3/20.

#ifndef _Room5_h_
#define _Room5_h_
#include "Room.h"
#include "../Feature/Feature10.h"
#include "../Feature/Feature9.h"

class Room5: public Room {
public:
	Room5();
	int event_one();
	int event_two();
	int event_three();
	virtual ~Room5();	
};

#endif
