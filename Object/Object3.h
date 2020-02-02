//
// Object3.h
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#ifndef _Object3_h_
#define _Object3_h_
#include "Object.h"
class Object3 : public Object{
public:
	Object3();
	virtual ~Object3();
	void read();
	int special=666;
};

#endif
