//
// Feature5.h
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#ifndef _Feature5_h_
#define _Feature5_h_
#include "Feature.h"
class Feature5 : public Feature {
public:
	Feature5();
	virtual ~Feature5();
	int read();
	int speak();//6
	int use(int obj_id);//7
	int open(int room_id, int obj_feat_id);//5
	void set_time(int time);
	string get_time_str();
	int look();
	int get_time();
	int climb();
	int special=666;
	int current_time=0;
};

#endif
