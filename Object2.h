//
// Object2.h
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#ifndef _Object2_h_
#define _Object2_h_
#include "Object.h"
class Object2 : public Object{
public:
	Object2();
	virtual ~Object2();
	string read();
	int special=666;
};

#endif
