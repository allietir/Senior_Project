//
// Feature11.h
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#ifndef _Feature11_h_
#define _Feature11_h_
#include "Feature.h"
class Feature11 : public Feature {
public:
	Feature11();
	virtual ~Feature11();
	int give(int room_id, int feat_obj_id);
	int speak();
	int special=666;
};

#endif
