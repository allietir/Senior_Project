//
// Feature18.h
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#ifndef _Feature18_h_
#define _Feature18_h_
#include "Feature.h"
class Feature18 : public Feature {
public:
	Feature18();
	virtual ~Feature18();
	int use(int obj_id);
	int smell();
	int eat();
	int special=666;
};

#endif
