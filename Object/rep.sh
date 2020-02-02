#!/bin/bash

counter=0;
Object="Object";

while [ $counter -lt 31 ]
do
	#sed -i "" 's/string read()/void read()/g' $Object$counter.h
	#sed -i "" "s/string Object$counter::read()/void Object$counter::read()/g" $Object$counter.cpp
	sed -i "" 's/printf("%s\\n", read_response.c_str()";/printf("%s\\n", read_response.c_str())/g' $Object$counter.cpp
	((counter++))
done
