#!/bin/bash

counter=1;
feature="Object";

while [ $counter -lt 9 ]
do
	sed -i ""  "s/int Feature$counter::read/int $feature$counter::read/g" $feature$counter.cpp
	#sed -i ""  's/printf("%s\\n", read_response.c_str());/printf("%s\\n", read_response.c_str());\'$'\n\t''return 0;/g' $feature$counter.cpp
	#sed -i ""  's/void read()/int read()/g' $feature$counter.h

((counter++))
done

