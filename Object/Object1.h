//
// Object1.h
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#ifndef _Object1_h_
#define _Object1_h_
#include "Object.h"

class Object1 : public Object{
public:
	Object1();
	virtual ~Object1();
	void read();
	
	int special=666;
	
};

#endif
