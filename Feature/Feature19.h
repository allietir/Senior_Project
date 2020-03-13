//
// Feature19.h
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#ifndef _Feature19_h_
#define _Feature19_h_
#include "Feature.h"
class Feature19 : public Feature {
public:
	Feature19();
	virtual ~Feature19();
	int open(int room_id, int feat_obj_id);
	int use(int obj_feat_obj);
	int special=666;
};

#endif
