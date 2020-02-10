//
// Feature4.h
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#ifndef _Feature4_h_
#define _Feature4_h_
#include "Feature.h"
class Feature4 : public Feature {
public:
	Feature4();
	virtual ~Feature4();
	int open(int room_id, int feat_obj_id);
	int play();
	int speak();
	int special=666;
};

#endif
