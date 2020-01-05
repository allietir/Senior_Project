//
// Feature.h
// Created by Claudia Rodriguez-Schroeder on 1/2/20.

#ifndef _Feature_h_
#define _Feature_h_
#include <string>
#include <cstdio>
//#include "Game.h"

using namespace std;
class Feature {
public:
	Feature();
	
	void verbx(int verb_x);
	//void init_attributes(string a, string b, string c, string d, string e, string f, string g, string h, string i, string j);
	void init_attributes(string atts[10], string alts[10]);
	//void init_verbs(string a, string b, string c, string d, string e, string f, string g, string h, string i, string j);
	void init_verbs(string verbs[10]);
	
	virtual ~Feature();
//private:
	string name;
	string description;
	int attr_toggle[10];//0 for default, 1 for alt;
	string attributes[10];
	string attributes_alt[10];
	string verb_list[10];

	bool feature_examined;
};

#endif