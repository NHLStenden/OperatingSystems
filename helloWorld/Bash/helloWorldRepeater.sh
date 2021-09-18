#!/bin/bash

while getopts ":n:" option; do 
  case "${option}" in 
    n)  nrOfRepeats=$OPTARG
  esac
  
done

# variable OPTIND is the position of the rest of the arguments
# so shift the already processed arguments away so $* points to the rest
shift $((OPTIND-1))

message="Hello World!" 

if [ "$#" -ge 1 ]; then
    message=$* 
fi


for ((i=0; i<=nrOfRepeats; i++)); do
   echo $message
done


