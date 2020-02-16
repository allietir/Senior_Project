//
// Feature25.h
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#ifndef _Feature25_h_
#define _Feature25_h_
#include "Feature.h"
class Feature25 : public Feature {
public:
	Feature25();
	virtual ~Feature25();
	int use(int object_id);
	int special=666;
};

#endif
