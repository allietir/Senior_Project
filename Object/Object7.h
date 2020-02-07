//
// Object7.h
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#ifndef _Object7_h_
#define _Object7_h_
#include "Object.h"
class Object7 : public Object{
public:
	Object7();
	virtual ~Object7();
	int read();
	int special=666;
};

#endif
