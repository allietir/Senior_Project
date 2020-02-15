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
#define NUM_REQ_VERBS 12
#define NUM_GAME_EVENTS 4

#define RUN_FUNC_VERBS 13

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
#define LOOK 10
#define TAKE 11
#define DROP 12


#define FEAT1 Gravestone
#define FEAT2 Tree
#define FEAT3 Portrait
#define FEAT4 Musicbox
#define FEAT5 Mirror
#define FEAT6 Carpet
#define FEAT7 Faceless
#define FEAT8 Table
#define FEAT9 Piano
#define FEAT10 Trapdoor
#define FEAT11 Child
#define FEAT12 Dollhouse
#define FEAT13 Mother
#define FEAT14 Dresser
#define FEAT15 Vampire
#define FEAT16 Blood
#define FEAT17 Mirror
#define FEAT18 Sink
#define FEAT19 Chest
#define FEAT20 Pirate
#define FEAT21 Bookshelf
#define FEAT22 Fireplace
#define FEAT23 Fountain
#define FEAT24 Guardian
#define FEAT25 Stove
#define FEAT26 Cupboard
#define FEAT27 Pedestal
#define FEAT28 Statue
#define FEAT29 Alex
#define FEAT30 Demon



#define STR_FEAT1 "Gravestone"
#define STR_FEAT2 "Tree"
#define STR_FEAT3 "Portrait"
#define STR_FEAT4 "Musicbox"
#define STR_FEAT5 "Mirror"
#define STR_FEAT6 "Carpet"
#define STR_FEAT7 "Faceless"
#define STR_FEAT8 "Table"
#define STR_FEAT9 "Piano"
#define STR_FEAT10 "Trapdoor"
#define STR_FEAT11 "Child"
#define STR_FEAT12 "Dollhouse"
#define STR_FEAT13 "Mother"
#define STR_FEAT14 "Dresser"
#define STR_FEAT15 "Vampire"
#define STR_FEAT16 "Blood"
#define STR_FEAT17 "Mirror"
#define STR_FEAT18 "Sink"
#define STR_FEAT19 "Chest"
#define STR_FEAT20 "Pirate"
#define STR_FEAT21 "Bookshelf"
#define STR_FEAT22 "Fireplace"
#define STR_FEAT23 "Fountain"
#define STR_FEAT24 "Guardian"
#define STR_FEAT25 "Stove"
#define STR_FEAT26 "Cupboard"
#define STR_FEAT27 "Pedestal"
#define STR_FEAT28 "Statue"
#define STR_FEAT29 "Alex"
#define STR_FEAT30 "Demon"




#define RVERB1 look

#define RVERB2 take
#define RVERB3 drop
#define RVERB4 go <exit_name>
#define RVERB5 <exit_name>
#define RVERB6 go <exit_direction>
#define RVERB7 <exir_direction>
#define RVERB8 help
#define RVERB9 inventory
#define RVERB10 savegame
#define RVERB11 loadgame
#define RVERB12 look_at

#define STR_RVERB1 "look"
#define STR_RVERB2 "take"
#define STR_RVERB3 "drop"
#define STR_RVERB4 "go <exit_name>"
#define STR_RVERB5 "<exit_name>"
#define STR_RVERB6 "go <exit_direction>"
#define STR_RVERB7 "<exir_direction>"
#define STR_RVERB8 "help"
#define STR_RVERB9 "inventory"
#define STR_RVERB10 "savegame"
#define STR_RVERB11 "loadgame"
#define STR_RVERB12 "look at"







#define STR_OBJ1 "lamp"
#define STR_OBJ2 "diary"
#define STR_OBJ3 "locket"
#define STR_OBJ4 "music"
#define STR_OBJ5 "dagger"
#define STR_OBJ6 "doll"
#define STR_OBJ7 "key"
#define STR_OBJ8 "chalice"

#define LAMP 0
#define DIARY 1
#define LOCKET 2
#define MUSIC 3
#define DAGGER 4
#define DOLL 5
#define KEY 6
#define CHALICE 7


#define FRONT 0
#define ENTRANCEWAY 1
#define UPSTAIRS 2
#define DINING 3
#define PARLOR 4
#define NURSURY 5
#define GUEST 6
#define MASTER 7
#define BATHROOM 8
#define ATTIC 9
#define LIBRARY 10
#define CONSERVATORY 11
#define KITCHEN 12
#define BASEMENT 13
#define CRYPT 14


#define GRAVESTONE 0
#define TREE 1
#define PORTRAIT 2
#define MUSICBOX 3
#define MIRROR 4
#define CARPET 5
#define FACELESS 6
#define TABLE 7
#define PIANO 8
#define TRAPDOOR 9
#define CHILD 10
#define DOLLHOUSE 11
#define MOTHER 12
#define DRESSER 13
#define VAMPIRE 14
#define BLOOD 15
#define MIRROR_2 16
#define SINK 17
#define CHEST 18
#define PIRATE 19
#define BOOKSHELF 20
#define FIREPLACE 21
#define FOUNTAIN 22
#define GUARDIAN 23
#define STOVE 24
#define CUPBOARD 25
#define PEDESTAL 26
#define STATUE 27
#define ALEX 28
#define DEMON 29