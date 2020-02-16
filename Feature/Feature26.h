//
// Feature26.h
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#ifndef _Feature26_h_
#define _Feature26_h_
#include "Feature.h"
class Feature26 : public Feature {
public:
	Feature26();
	virtual ~Feature26();
	int open(int room_id, int object_id);
	int special=666;
};

#endif
