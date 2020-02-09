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
	int read();
	int smell();
//	int use(int obj_id);
//	int eat();
//	int play();
//	int open(int room_id, int obj_feat_id);
//	int speak();
//	int give(int room_id, int obj_feat_id);
	int climb();
	int attack(int obj_feat_id);
private:
 	string desc1;
	string desc2;
	
};

#endif
