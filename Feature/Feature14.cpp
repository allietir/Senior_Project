//
// Feature14.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Feature14.h"

Feature14::Feature14() {
	set_name("Dresser");
	set_desc("The dresser mirror shows a terrifying reflection; the woman in the bed behind you is still there, but besides her is a horrifying ghoul; the woman, in white, but her eyes and mouth are black and gaping. She isn't moving, just floating by her body. The dresser has some sheet music on there.");
	set_index_id(13);
}
void Feature14::remove_object_desc(){
	
	set_desc("The dresser mirror shows a terrifying reflection; the woman in the bed behind you is still there, but besides her is a horrifying ghoul; the woman, in white, but her eyes and mouth are black and gaping. She isn't moving, just floating by her body.");

}
Feature14::~Feature14() {
	
}
