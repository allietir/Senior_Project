//
// Feature2.h
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#ifndef _Feature2_h_
#define _Feature2_h_
#include "Feature.h"
#include "../Room/Room1.h"
class Feature2 : public Feature {
public:
	Feature2();
	virtual ~Feature2();
	void look();
	void climb();

	void jump();
	friend class Room1;
private:
 	string desc1;
	string desc2;
	
};

#endif
