//
// Feature6.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Feature6.h"

Feature6::Feature6() {
	set_name("\033[1;31mCarpet\033[0m");
	set_desc("The \033[1;31mcarpet\033[0m is long and dark, and there is an image of a house on a hill and a strange purple fire surrounding the hill. There are words on the hill. ");
	set_index_id(5);
}
int Feature6::read(){
	if (get_times_toggled(READ)!=-666){
		string read_response = "Bha taigh ann uaireigin air cnoc\n Gabh a-steach còmhla ri caraid, ma thogras tu\n Bidh call uamhasach a ’tachairt\n B ’fheàrr dhut faighinn a-mach, dèan cabhag\n Ach gus an anam daor a shàbhaladh taobh a-staigh\n Feumaidh tu a bhith a ’sabaid grunn uilebheistean taobh a-staigh ";
			func_togg_count_x(READ);
			printf("%s", read_response.c_str());
	}
	else{
		string read_response = "There once was a house on a hill\nGo inside with a friend, if you will\nThere a terrible loss will take place\nYou had better get out, do have haste\nBut to save the dear soul within\nYou must fight the monsters within ";
		func_togg_count_x(READ);
		printf("%s", read_response.c_str());
	}
	
	return 4;
}
int Feature6::use(int obj_id){
	if (obj_id==CHALICE){
		printf("The \033[1;31mcarpet\033[0m alights with the purple fire and then burns out, revealing new, translated text. ");
		set_togg_count_x(READ, -666);
	}
	return 4;
}
Feature6::~Feature6() {
	
}
