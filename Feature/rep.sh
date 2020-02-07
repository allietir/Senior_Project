#!/bin/bash

counter=1;
feature="Feature";

while [ $counter -lt 31 ]
do
	#sed -i "" "s/void $feature$counter::read/int Feature$counter::read/g" $feature$counter.cpp
	#sed -i "" 's/printf("%s\\n", read_response.c_str());/printf("%s\\n", read_response.c_str());\'$'\n\t''return 0;/g' $feature$counter.cpp
	sed -i "" 's/void read()/int read()/g' $feature$counter.h

((counter++))
done

