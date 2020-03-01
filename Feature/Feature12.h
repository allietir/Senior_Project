//
// Feature12.h
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#ifndef _Feature12_h_
#define _Feature12_h_
#include "Feature.h"
class Feature12 : public Feature {
public:
	Feature12();
	int use(int obj_feat);
	virtual ~Feature12();
	int special=666;
};

#endif
