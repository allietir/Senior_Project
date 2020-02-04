//
// Feature8.h
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#ifndef _Feature8_h_
#define _Feature8_h_
#include "Feature.h"
#include "../Room/Room4.h"
class Feature8 : public Feature {
public:
	Feature8();
	virtual ~Feature8();
	void read();
	void smell();
	void use();
	
	int special=666;
	friend class Room4;
};

#endif
