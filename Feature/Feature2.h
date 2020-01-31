//
// Feature2.h
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#ifndef _Feature2_h_
#define _Feature2_h_
#include "Feature.h"

class Feature2 : public Feature {
public:
	Feature2();
	virtual ~Feature2();
	string look();
private:
 	string desc1;
	string desc2;
};

#endif
