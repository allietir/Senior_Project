//
// Room10.h
// Created by Claudia Rodriguez-Schroeder on 1/3/20.

#ifndef _Room10_h_
#define _Room10_h_
#include "Room.h"
#include "../Feature/Feature20.h"
#include "../Feature/Feature19.h"

class Room10: public Room {
public:
	Room10();
	int event_one();
	int event_two();
	virtual ~Room10();	
};

#endif
