//
// Feature3.h
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#ifndef _Feature3_h_
#define _Feature3_h_
#include "Object.h"
class Feature3 : public Feature {
public:
	Feature3();
	virtual ~Feature3();
	string read();
	int special=666;
};

#endif
