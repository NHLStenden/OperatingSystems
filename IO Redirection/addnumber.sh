#!/bin/bash
# This script adds linenumbers to each line of a file (prefix)
#  Examples:
#  user@host:~/programs$ addnumber  -f mysourcefile -n 10
#  user@host:~/programs$ addnumber < mysourcefile -n 33
#  user@host:~/programs$ addnumber < mysourcefile
#  
#  

# Set Default values:
# Input comes from Standard In (channel 0)
# Declare an integer variable (linenumber) and init it to value 1 
#
filename=/dev/stdin
declare -i linenumber

linenumber=1

# Cycle throught options provided on command line to override default values
while getopts f:n:? name
do
     case $name in
     n)     linenumber=$OPTARG;;
     f)     filename="$OPTARG";;
     ?)     printf "Usage: %s: [-f filename] [-n start number] args\n"  `basename $0`
            exit 2;;
     esac
done

while IFS= read -r line
do
  printf "%04d:%s\n" $linenumber "$line"
  linenumber=$linenumber+1
done < "$filename"
