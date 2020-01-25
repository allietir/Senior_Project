//
// Knife.h
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#ifndef _Knife_h_
#define _Knife_h_
#include "Object.h"
class Knife : public Object{
public:
	Knife();
	virtual ~Knife();
	string read();
	int special=666;
};

#endif