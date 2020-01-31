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

	int get_current_room();
	void set_current_room(int s_current_room);
	
	int get_works_with_room(int room_num);
	void set_works_with_room(int room_num, int val);
	
	int get_works_with_feature(int feature_num);
	void set_works_with_feature(int feature_num, int val);
	
private:

	int works_with_room[NUM_ROOMS];//1 if works with room i.e. maybe there are some rooms it doesn't work with 
	int works_with_feature[TOTAL_FIXED];//1 if works with feature i.e. maybe it works with a feature
};

#endif