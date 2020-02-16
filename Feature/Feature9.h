//
// Feature9.h
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#ifndef _Feature9_h_
#define _Feature9_h_
#include "Feature.h"
class Feature9 : public Feature {
public:
	Feature9();
	virtual ~Feature9();
	int use(int obj_id);
	int play();
	int special=666;
};

#endif
