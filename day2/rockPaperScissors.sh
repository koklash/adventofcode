#!/bin/bash


maxCal=0
tmpCal=0
low=0
mid=0
high=0

cat ./input.txt | while read line
do
   if [ $line ]
   then
	tmpCal=$(($tmpCal+$line))
   
   elif [ $tmpCal -gt $high ]
   then
   	low=$mid
   	mid=$high
   	high=$tmpCal
   	tmpCal=0
   	
   elif [ $tmpCal -gt $mid ]
   then
   	low=$mid
   	mid=$tmpCal
   	tmpCal=0
   
   elif [ $tmpCal -gt $low ]
   then
   	low=$tmpCal
   	tmpCal=0
   	
   else
	   tmpCal=0
   fi
   
   echo $(($low+$mid+$high))
      
done 



