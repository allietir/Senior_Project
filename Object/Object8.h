//
// Object8.h
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#ifndef _Object8_h_
#define _Object8_h_
#include "Object.h"
class Object8 : public Object{
public:
	Object8();
	virtual ~Object8();
	int read();
	int special=666;
};

#endif
