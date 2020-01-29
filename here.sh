#!/bin/bash

counter=30
fc="Feature"
echo $fc
echo $counter

total=$fc$counter
echo $total 
while [ $counter -gt 2  ]
do

total=$fc$counter
echo $total 

newtotal="s/Feature1/$total/g"
echo $newtotal
cpp_total=$total.cpp
h_total=$total.h
sed -i "" $newtotal $cpp_total
sed -i "" $newtotal $h_total

((counter--))

done
echo All done



