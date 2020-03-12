#include <iostream>
#include <cstring>
#include "Game.h"
//#include "globals.h"
#include "parser.h"
#include "savesystem.h"
#include "wordwrap.h"

using namespace std;
void convert_string_to_array(int* arr, string str);
int main(int argc, char *argv[]) {
		
		Game run_game;
		int saveflag=0;
		int loadflag=0;
		//using https://stackoverflow.com/questions/19485536/redirect-output-of-an-function-printing-to-console-to-string/19499003
		char buffer[2024];
		memset(buffer, '\0', 2024);
		FILE *fp;
		fp = fmemopen(buffer, 2024, "w");
		if ( !fp ) { std::printf("error"); 
		
		return 0; }

		auto old = stdout;
		stdout = fp;

		run_game.start();
		
		fclose(fp);
		stdout = old; //reset
		
	
		printf("%s\n",word_wrap(buffer, MAX_WIDTH).c_str());
		//test doll
		//run_game.get_player()->set_current_room(NURSERY);
		//run_game.get_player()->set_has_objects(LAMP, 1);
		//run_game.get_player()->set_move_count(11);
		
		
		//test chalice
		//run_game.get_player()->set_current_room(BASEMENT);
		//run_game.get_player()->set_has_objects(CHALICE, 1);
		//run_game.get_player()->set_move_count(11);
		
		//test child
		run_game.get_player()->set_current_room(NURSERY);
		run_game.get_player()->set_has_objects(LAMP, 1);
		run_game.get_player()->set_has_objects(DOLL, 1);
		//run_game.get_player()->set_move_count(11);
		
		char userInput[100] = {'\0'}; 
		int x=0;
		int y_flag = 0;
		while (x==0) {
			
			if (y_flag == 0){
				printf("\nWhat would you like to do?\n");
			}		
			cin.getline(userInput, 100);
			fflush(stdout);
			fflush(stdin);
			//cin.ignore(2, '\n');
			
			//printf("got %s", userInput);
			if (userInput[0]=='\0'){
				//cout << "Nothing was entered\n";
				printf("nothing was entered: press enter and type in a valid command");
				y_flag = 1;
				cin.clear();
				cin.ignore(1000000000000, '\n');
				memset(userInput, '\0', 100);
			}
			else{
				y_flag = 0;
				
				//using https://stackoverflow.com/questions/19485536/redirect-output-of-an-function-printing-to-console-to-string/19499003
				char buffer[2024]={'\0'};
				FILE *fp = fmemopen(buffer, 2024, "w");
				if ( !fp ) { std::printf("the error"); return 0; }
				//printf("STDOUT: %i", stdout);
				FILE *old = stdout;
				stdout = fp;
				fflush(stdout);
				
				int res = inputParsing(run_game, userInput);
				if (run_game.get_player()->get_loading()==1){
					loadflag = 1;
				}
				if (run_game.get_player()->get_saving()==1){
					saveflag = 1;
				}
				fflush(stdout);
				fclose(fp);
				stdout = old; //reset
				
				string strbuff = buffer; 
				
				printf("%s\n",word_wrap(strbuff.c_str(), 80).c_str());
				if (run_game.get_player()->get_player_alive()==0){
					//fflush(stdout);
					save_game(run_game);
					fflush(stdout);
					
					load_game(run_game);
					fflush(stdout);
				//	fflush(stdin);
				
					save_game(run_game);
					fflush(stdout);
					y_flag = 0;
				//	cin.clear();
				//	cin.ignore(1000000000000, '\n');
					memset(userInput, '\0', 100);
					
				}
				else if (run_game.get_player()->get_player_alive()==2){
					printf("Exiting game\n");
					return 0;
				}
				if (loadflag==1){
					run_game.get_player()->set_loading(0);
					loadflag=0;
					load_game(run_game);
					fflush(stdout);
					y_flag = 0;
					memset(userInput, '\0', 100);
				}
				if (saveflag==1){
					run_game.get_player()->set_saving(0);
					saveflag=0;
					save_game(run_game);
					fflush(stdout);
					y_flag = 0;
					memset(userInput, '\0', 100);
				}
				

				//printf(word_wrap(strbuff, 80));
				
			}
 
		}



}	
	