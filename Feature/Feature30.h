//
// Feature30.h
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#ifndef _Feature30_h_
#define _Feature30_h_
#include "Feature.h"
class Feature30 : public Feature {
public:
	Feature30();
	virtual ~Feature30();
	int speak();
	int attack(int obj_feat);
	int give(int event_occured, int obj_feat_id);
	int special=666;
};

#endif
