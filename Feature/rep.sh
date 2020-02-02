#!/bin/bash

counter=3;
feature="Feature";

while [ $counter -lt 31 ]
do
	#sed -i "" 's/string read()/void read()/g' $feature$counter.h
	#sed -i "" "s/string Feature$counter::read()/void Feature$counter::read()/g" $feature$counter.cpp
	sed -i "" 's/printf("%s\\n", read_response.c_str()";/printf("%s\\n", read_response.c_str())/g' $feature$counter.cpp
	((counter++))
done
