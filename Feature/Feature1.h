//
// Feature1.h
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#ifndef _Feature1_h_
#define _Feature1_h_
#include "Feature.h"
class Feature1 : public Feature {
public:
	Feature1();
	virtual ~Feature1();
	int read();
	void remove_object_desc();
	string get_desc1();
	void set_desc1(string x);
	string get_desc1_no_obj();
	void set_desc1_no_obj(string x);
	int special=666;
private:
	string desc1;
	string desc1_no_obj;
};

#endif
