//
// Feature1.h
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#ifndef _Feature1_h_
#define _Feature1_h_
#include "Object.h"
class Feature1 : public Feature {
public:
	Feature1();
	virtual ~Feature1();
	string read();
	int special=666;
};

#endif