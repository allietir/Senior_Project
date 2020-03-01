//
// Object.h
// Created by Claudia Rodriguez-Schroeder on 1/5/20.

#ifndef _Object_h_
#define _Object_h_
#include <string>
#include "../Feature/Feature.h"

using namespace std;

class Object : public Feature {
public:
	Object();
	virtual ~Object();
};

#endif