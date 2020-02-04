//
// Feature3.h
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#ifndef _Feature3_h_
#define _Feature3_h_
#include "../Feature/Feature.h"
class Feature3 : public Feature {
public:
	Feature3();
	virtual ~Feature3();
	int smell();
	int use();
	int special=666;
private:
	string desc1;
	string desc2;
};

#endif
