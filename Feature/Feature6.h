//
// Feature6.h
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#ifndef _Feature6_h_
#define _Feature6_h_
#include "Feature.h"
class Feature6 : public Feature {
public:
	Feature6();
	virtual ~Feature6();
	int read();
	int use(int obj_id);
	int special=666;
};

#endif
