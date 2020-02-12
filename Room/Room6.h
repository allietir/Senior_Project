//
// Room6.h
// Created by Claudia Rodriguez-Schroeder on 1/3/20.

#ifndef _Room6_h_
#define _Room6_h_
#include "Room.h"
#include "../Feature/Feature12.h"
#include "../Feature/Feature11.h"

class Room6: public Room {
public:
	Room6();
	int event_one();
	int event_two();
	virtual ~Room6();	
};

#endif
