#define MAX_FIXED 3
#define NUM_VERBS 10
#define NUM_OBJECTS 8
#define NUM_ROOMS 15
#define TOTAL_FIXED 45
#define MAX_EXITS 4
#define MAX_DESCS 5
#define NUM_VERB_FUNCS 10
#define FRIEND_NAME "ALEX"

#define ROOM1 "Front Garden"
#define ROOM2 "Entranceway"//exit north->upstarishallway:3 south->front garden:1 east->dining room:4 west->parlour:5
#define ROOM3 "Upstairs Hallway"//exit north->childs bedroom:6  east->gues bedroom:7 west->master bedroom:8
#define ROOM4 "Dining Room" //exit east->kitchen:13 west->entranceway:2
#define ROOM5 "Parlor"//exit east->entranceway:1 west->library11 //piano uses sheet music
#define ROOM6 "Nursury"//exit south->upstrais hallway:3  west->bathroom:9
#define ROOM7 "Guest Bedroom"//exit west->upstairs hallway:3 
#define ROOM8 "Master Bedroom"//exit east->upstairs hallway:3 north->bathroom:9 west->attic:10
#define ROOM9 "Bathroom"//exit south->master bedroom:8 east->child room:6 exit 
#define ROOM10 "Attic"//exit south->library:11 east->master bedroom:8
#define ROOM11 "Library"//exit north->attic:10 east->parlor/lounge:5 west->conservatory:12
#define ROOM12 "Conservatory"//exit south->front garden:1 (SECRET) east->library:11
#define ROOM13 "Kitchen"//exit north->basement:14 west->dining room:4
#define ROOM14 "Basement"//exit north->crypt:15 south->kicthe:13
#define ROOM15 "Crypt"//exit south->basement:14

#define VERB1 "read"
#define VERB2 "open"
#define VERB3 "use"
#define VERB4 "eat"
#define VERB5 "drink"
#define VERB6 "fill"
#define VERB7 "play"
#define VERB8 "speak"
#define VERB9 "climb"
#define VERB10 "hit"