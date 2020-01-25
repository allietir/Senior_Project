//
// Gravestone.h
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#ifndef _Gravestone_h_
#define _Gravestone_h_
#include "Object.h"
class Gravestone : public Feature {
public:
	Gravestone();
	virtual ~Gravestone();
	string read();
	int special=666;
};

#endif