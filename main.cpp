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

		string name_input;
		string intro_one = "You and your best friend Alex were hanging out like you always do. You've been through the best of timesand the worst of times together. Today, you were exploring and happened upon an old, abandoned house. Let's go check it out, Alex says eagerly as they wiggle through the broken gate. You get that feeling that this is a terrible idea but decide to shrug it off and follow Alex through the gate... ";
		string intro_two = "You finally reach the front of the house and get a better look at it. Whoa... that's hella creepy, says Alex. \n\nPress <Enter> to start the game. ";
		printf("\n%s\n\n", word_wrap(intro_one, MAX_WIDTH).c_str());
	
		printf("First, what is your name? ");
		getline(cin, name_input);

		printf("\n%s", word_wrap(intro_two, MAX_WIDTH).c_str());
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		//house art taken from https://ascii.co.uk/art/house
		const string ascii_art = R"(
                                      ^V^
                                    
                           )     ^V^  
                *-*       (             ^V^
 ^V^      _______|________%%__                              
         |%%%%%%%%%%%%%%%%%%%%%|            \   /  
    _____|%%%/^\%%%/^\%%%/^\%%%|_____     '-\| -'/-,
   /%/^\%|%%%|-|%%%|-|%%%|-|%%%|%/^\%\  -\| \ ./ |-.      
  /%%|-|%|%%%%%%%%%%%%%%%%%%%%%|%|-|��\ '.-\| /.-'   
 /%%%%%%%%| __  __ ___ __  __ |%%%%%%%%\     \\//         
  |_|-|-|_||__||__|.|.|__||__||_|-|-|_|       ||
  IIIIIIII|       |_|_|       |IIIIIIII       || 
  ~^    ^"@@@@@@@@|   |@@@@@@@@"^    ^~    ^^/ `\^^
                  |   |
                                     _._
WELCOME TO OUR HAUNTED HOUSE GAME!  /   \\
                                    |RIP||
                                  \\|,,,||//)";

    	printf("%s\n\n", ascii_art.c_str());
		
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

		run_game.start(name_input);
		
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
//		run_game.get_player()->set_current_room(NURSERY);
//		run_game.get_player()->set_has_objects(LAMP, 1);
//		run_game.get_player()->set_has_objects(DOLL, 1);
		//run_game.get_player()->set_move_count(11);
		
		//test library
//		run_game.get_player()->set_current_room(LIBRARY);
//		run_game.get_player()->set_has_objects(LAMP, 1);
//		run_game.get_player()->set_has_objects(DIARY, 1);
//		run_game.get_player()->set_has_objects(CHALICE, 1);
		

		
		//test bathroom
//		run_game.get_player()->set_current_room(BATHROOM);
//		run_game.get_player()->set_has_objects(CHALICE, 1);
//		run_game.get_player()->set_has_objects(DAGGER, 1);
//		run_game.get_player()->set_has_objects(MUSIC, 1);
//		run_game.get_player()->set_has_objects(LAMP, 1);
		
		//test upstairs hallway
		
//		run_game.get_player()->set_current_room(UPSTAIRS);
//		run_game.get_player()->set_has_objects(CHALICE, 1);
//		run_game.get_player()->set_has_objects(DAGGER, 1);
//		run_game.get_player()->set_has_objects(MUSIC, 1);
//		run_game.get_player()->set_has_objects(LAMP, 1);
//		run_game.get_player()->set_move_count(12);
		
		//run_game.get_player()->set_current_room(PARLOR);
//		run_game.get_player()->set_current_room(GUEST);
//			run_game.get_player()->set_has_objects(CHALICE, 1);
//			run_game.get_player()->set_has_objects(DAGGER, 1);
			//run_game.get_player()->set_has_objects(MUSIC, 1);
//			run_game.get_player()->set_has_objects(LAMP, 1);
			
			
			
		//test crypt
		run_game.get_player()->set_current_room(CRYPT);
		run_game.get_player()->set_has_objects(LAMP, 1);
		run_game.get_player()->set_has_objects(DIARY, 1);
		run_game.get_player()->set_has_objects(CHALICE, 1);
		run_game.get_player()->set_has_objects(LOCKET, 1);
		run_game.set_room_events_triggered(34, 1);	
		
		//run_game.get_player()->set_move_count(13);
		char userInput[100] = {'\0'}; 
		int x=0;
		int y_flag = 0;
		int just_loaded = 0;
		while (x==0) {
			
			if (just_loaded==1){
				just_loaded = 0;
				string x = run_game.get_room_x(run_game.get_player()->get_current_room())->get_long_description();
				printf("%s", word_wrap(x, MAX_WIDTH).c_str());
				
				
			}
			
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
				
				inputParsing(run_game, userInput);
				
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
					just_loaded = 1;
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
					just_loaded = 1;
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
	