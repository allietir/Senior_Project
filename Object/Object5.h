//
// Object5.h
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#ifndef _Object5_h_
#define _Object5_h_
#include "Object.h"
class Object5 : public Object{
public:
	Object5();
	virtual ~Object5();
	int read();
	int use(int room);
	int special=666;
};

#endif
