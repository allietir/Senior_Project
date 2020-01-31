//
// Feature8.h
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#ifndef _Feature8_h_
#define _Feature8_h_
#include "Feature.h"
class Feature8 : public Feature {
public:
	Feature8();
	virtual ~Feature8();
	string read();
	int special=666;
};

#endif
