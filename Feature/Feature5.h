//
// Feature5.h
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#ifndef _Feature5_h_
#define _Feature5_h_
#include "Feature.h"
class Feature5 : public Feature {
public:
	Feature5();
	virtual ~Feature5();
	string read();
	int special=666;
};

#endif
