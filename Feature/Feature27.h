//
// Feature27.h
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#ifndef _Feature27_h_
#define _Feature27_h_
#include "Feature.h"
class Feature27 : public Feature {
public:
	Feature27();
	virtual ~Feature27();
	int use(int obj_id);
	int special=666;
};

#endif
