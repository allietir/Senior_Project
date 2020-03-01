//
// Feature21.h
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#ifndef _Feature21_h_
#define _Feature21_h_
#include "Feature.h"
class Feature21 : public Feature {
public:
	Feature21();
	virtual ~Feature21();
	int read();
	int use(int obj_feat_obj);
	int speak();
	int special=666;
};

#endif
