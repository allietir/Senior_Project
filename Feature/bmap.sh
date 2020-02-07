#!/bin/bash

counter=0;
feature="Feature";

feat_names=(Gravestone
Tree
Portrait
Musicbox
Mirror
Carpet
Faceless
Table
Piano
Trapdoor
Child
Dollhouse
Mother
Dresser
Vampire
Blood
Mirror
Sink
Chest
Pirate
Bookshelf
Fireplace
Fountain
Guardian
Stove
Cupboard
Pedestal
Statue
Alex
Demon);
counter2=1;



while [ $counter -lt 31 ]
do
	
	rep=${feat_names[$counter]};
	echo "$rep";
	sed -i "" 's/set_name("\('.*'\)")/set_name('\""$rep"\"')/g' $feature$counter2.cpp
	((counter++))
	((counter2++))
done


