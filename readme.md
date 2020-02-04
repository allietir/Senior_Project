- run "make" to compile
- run "make clean" to clean outputs 

# Engine/DS

## Dependencies
You can refer to the makefile, or, if you prefer, the following graph for an understanding of the dependancies. 

![img1](HM_ds.png)


## Rooms
There are 15 rooms.

> Room DS Visualization Here

### Object Text within Room Descriptions
Object text is added in the Game class via the `add_object_text()` function after the object is set to be in that particular room via `set_has_object()`. The above are done within the `init_rooms()` class, which also sets each individual room within a room array, so that it is easy to refer to via index. The Game class also houses the objects, which are referred to within the Room classes by their index, which is also set within the room class by id. 


## Objects

There are 8 Objects

> Object DS Visualization here

## Features

There are 30 Features

> Feature DS Visualization here


## Player

There is one player.

> Player DS Visualization here


## Game

> Game DS Visualization here
> Explain how Game calls and interacts with Rooms, Verbs, Features, Objects, and the Player

## Verb Functions

> Explain return value and parameters verbs tak

## State Saving

## Tests

# Parser

# Save/Load
