//
// Object4.h
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#ifndef _Object4_h_
#define _Object4_h_
#include "Object.h"
class Object4 : public Object{
public:
	Object4();
	virtual ~Object4();
	int read();
	int play();
	int special=666;
};

#endif
