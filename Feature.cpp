//
// Feature.cpp
// Created by Claudia Rodriguez-Schroeder on 1/2/20.

#include "Feature.h"
#include <string>
#include <cstdio>

using namespace std;
Feature::Feature() {
	name = "no name";
	description = "no description";
	attributes[0] = "attribute1";
	attributes[1] = "attribute2";
	attributes[2] = "attribute3";
	attributes[3] = "attribute4";
	attributes[4] = "attribute5";
	attributes[5] = "attribute6";
	attributes[6] = "attribute7";
	attributes[7] = "attribute8";
	attributes[8] = "attribute9";
	attributes[9] = "attribute10";
	
	attributes_alt[0] = "attributes_alt1";
	attributes_alt[1] = "attribute_alt2";
	attributes_alt[2] = "attribute_alt3";
	attributes_alt[3] = "attribute_alt4";
	attributes_alt[4] = "attribute_alt5";
	attributes_alt[5] = "attribute_alt6";
	attributes_alt[6] = "attribute_alt7";
	attributes_alt[7] = "attribute_alt8";
	attributes_alt[8] = "attribute_alt9";
	attributes_alt[9] = "attribute_alt10";
	
	for (int i = 0; i < 10; i++){
		attr_toggle[i]=0;
	}
}
void Feature::init_attributes(string atts[10], string alts[10]){
	for (int i = 0; i < 10; i++){
		attributes[i]=atts[i];
		attributes_alt[i]=alts[i];
		attr_toggle[i]=0;
	}
}

void Feature::init_verbs(string verbs[10]){
	for (int i = 0; i < 10; i++){
		verb_list[i]=verbs[i];
	}
}
void Feature::verbx(int verb){
	//the "ith" verb toggles the attribute change i.e. 
	printf("verb %i: first: %i", verb, attr_toggle[verb]);

	if (attr_toggle[verb]==0)
	{
		printf("switched on");
		attr_toggle[verb]=1;
		printf("%i", attr_toggle[verb]);
	}
	else if (attr_toggle[verb]==1){
		printf("switched off");
		attr_toggle[verb]=0;
	}
	if (attr_toggle[verb]==1){
		printf("%s is %s\n", name.c_str(), attributes_alt[verb].c_str());
	}
	else{
		printf("%s is %s\n", name.c_str(), attributes[verb].c_str());
	}
}

Feature::~Feature() {
	
}