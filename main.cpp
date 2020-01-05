#include <iostream>
#include "Game.h"
using namespace std;
int main(int argc, char *argv[]) {
	printf("CHECK FOR SAVE FILE\n");
	//if save file exists, load 
	Game x;
	x.load("saved.txt");
	x.initialize_rooms();
	
	x.start();
	
	//drive game
	int still_playing = 1;
	while (still_playing == 1){
		x.get_next_step();
		
	}
	

	
}