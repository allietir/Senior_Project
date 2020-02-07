//
// Feature16.h
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#ifndef _Feature16_h_
#define _Feature16_h_
#include "Feature.h"
class Feature16 : public Feature {
public:
	Feature16();
	virtual ~Feature16();
	int read();
	int special=666;
};

#endif
