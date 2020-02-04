//
// Feature10.h
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#ifndef _Feature10_h_
#define _Feature10_h_
#include "Feature.h"
class Feature10 : public Feature {
public:
	Feature10();
	virtual ~Feature10();
	int read();
	int special=666;
};

#endif
