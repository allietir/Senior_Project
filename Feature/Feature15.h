//
// Feature15.h
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#ifndef _Feature15_h_
#define _Feature15_h_
#include "Feature.h"
class Feature15 : public Feature {
public:
	Feature15();
	virtual ~Feature15();
	int read();
	int special=666;
};

#endif
