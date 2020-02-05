#define MAX_FIXED 2
#define NUM_STR_VERBS 10
#define NUM_OBJECTS 8
#define NUM_ROOMS 15
#define TOTAL_FIXED 30
#define MAX_EXITS 4
#define MAX_DESCS 5
#define NUM_VERB_FUNCS 10
#define FRIEND_NAME "ALEX"
#define MAX_EVENTS 3
#define NUM_EVENTS 45

#define ROOM1 Front Garden
#define ROOM2 Entranceway//exit north->upstarishallway:3 south->front garden:1 east->dining room:4 west->parlour:5
#define ROOM3 Upstairs Hallway//exit north->childs bedroom:6  east->gues bedroom:7 west->master bedroom:8
#define ROOM4 Dining Room //exit east->kitchen:13 west->entranceway:2
#define ROOM5 Parlor//exit east->entranceway:1 west->library11 //piano uses sheet music
//features: dollhouse: requires doll
#define ROOM6 Nursury//exit south->upstrais hallway:3  west->bathroom:9
#define ROOM7 Guest Bedroom//exit west->upstairs hallway:3 
#define ROOM8 Master Bedroom//exit east->upstairs hallway:3 north->bathroom:9 west->attic:10
#define ROOM9 Bathroom//exit south->master bedroom:8 east->child room:6 exit 
#define ROOM10 Attic//exit south->library:11 east->master bedroom:8
#define ROOM11 Library//exit north->attic:10 east->parlor/lounge:5 west->conservatory:12
#define ROOM12 Conservatory//exit south->front garden:1 (SECRET) east->library:11
#define ROOM13 Kitchen//exit north->basement:14 west->dining room:4
#define ROOM14 Basement//exit north->crypt:15 south->kicthe:13
#define ROOM15 Crypt//exit south->basement:14

#define STR_ROOM1 "Front Garden"
#define STR_ROOM2 "Entranceway"//exit north->upstarishallway:3 south->front garden:1 east->dining room:4 west->parlour:5
#define STR_ROOM3 "Upstairs Hallway"//exit north->childs bedroom:6  east->gues bedroom:7 west->master bedroom:8
#define STR_ROOM4 "Dining Room" //exit east->kitchen:13 west->entranceway:2
#define STR_ROOM5 "Parlor"//exit east->entranceway:1 west->library11 //piano uses sheet music
//features: dollhouse: requires doll
#define STR_ROOM6 "Nursury"//exit south->upstrais hallway:3  west->bathroom:9
#define STR_ROOM7 "Guest Bedroom"//exit west->upstairs hallway:3 
#define STR_ROOM8 "Master Bedroom"//exit east->upstairs hallway:3 north->bathroom:9 west->attic:10
#define STR_ROOM9 "Bathroom"//exit south->master bedroom:8 east->child room:6 exit 
#define STR_ROOM10 "Attic"//exit south->library:11 east->master bedroom:8
#define STR_ROOM11 "Library"//exit north->attic:10 east->parlor/lounge:5 west->conservatory:12
#define STR_ROOM12 "Conservatory"//exit south->front garden:1 (SECRET) east->library:11
#define STR_ROOM13 "Kitchen"//exit north->basement:14 west->dining room:4
#define STR_ROOM14 "Basement"//exit north->crypt:15 south->kicthe:13
#define STR_ROOM15 "Crypt"//exit south->basement:14

#define STR_VERB1 "read"
#define STR_VERB2 "smell"
#define STR_VERB3 "use"
#define STR_VERB4 "eat"
#define STR_VERB5 "play"
#define STR_VERB6 "open"
#define STR_VERB7 "speak"
#define STR_VERB8 "give"
#define STR_VERB9 "climb"
#define STR_VERB10 "attack"

#define VERB1 read
#define VERB2 smell
#define VERB3 use
#define VERB4 eat
#define VERB5 play
#define VERB6 open
#define VERB7 speak
#define VERB8 give
#define VERB9 climb
#define VERB10 attack

#define READ 0
#define SMELL 1
#define USE 2
#define EAT 3
#define PLAY 4
#define OPEN 5
#define SPEAK 6
#define GIVE 7
#define CLIMB 8
#define ATTACK 9