//
// Feature14.h
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#ifndef _Feature14_h_
#define _Feature14_h_
#include "Feature.h"
class Feature14 : public Feature {
public:
	Feature14();
	virtual ~Feature14();
	int attack(int obj);
	int special=666;
};

#endif
