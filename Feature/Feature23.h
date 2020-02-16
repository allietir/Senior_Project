//
// Feature23.h
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#ifndef _Feature23_h_
#define _Feature23_h_
#include "Feature.h"
class Feature23 : public Feature {
public:
	Feature23();
	virtual ~Feature23();
	int use(int id);
	int eat();
	int special=666;
};

#endif
