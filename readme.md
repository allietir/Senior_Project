- run "make" to compile
- run "make clean" to clean outputs 
- current expected output:
![img1](https://github.com/claudred/CS_467/blob/master/Screen%20Shot%202020-01-24%20at%206.44.04%20PM.png)
TO DO:
add "event" structure to room class

# Object Text within Room Descriptions
Object text is added in the Game class via the `add_object_text()` function after the object is set to be in that particular room via `set_has_object()`. The above are done within the `init_rooms()` class, which also sets each individual room within a room array, so that it is easy to refer to via index. The Game class also houses the objects, which are referred to within the Room classes by their index, which is also set within the room class by id. 