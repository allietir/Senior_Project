//
// Feature7.h
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#ifndef _Feature7_h_
#define _Feature7_h_
#include "Feature.h"
class Feature7 : public Feature {
public:
	Feature7();
	virtual ~Feature7();
	string read();
	int special=666;
};

#endif
