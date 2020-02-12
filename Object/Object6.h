//
// Object6.h
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#ifndef _Object6_h_
#define _Object6_h_
#include "Object.h"
class Object6 : public Object{
public:
	Object6();
	virtual ~Object6();
	int give(int room_id, int feat_obj_id);
	int special=666;
};

#endif
