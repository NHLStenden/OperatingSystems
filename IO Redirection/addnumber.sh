#!/bin/bash
# This script adds linenumbers to each line of a file (prefix)
#  Examples:
#  user@host:~/programs$ addnumber  -f mysourcefile -n 10
#  user@host:~/programs$ addnumber < mysourcefile -n 33
#  user@host:~/programs$ addnumber < mysourcefile
#  
#  

usestdin=Y
filename=/dev/stdin
declare -i linenumber

linenumber=1

while getopts f:n:? name
do
     case $name in
     n)      linenumber=$OPTARG;;
     f)      usestdin=N
             filename="$OPTARG";;
     ?)     printf "Usage: %s: [-f filename] [-n start number] args\n"  $0
            exit 2;;
     esac
done

while IFS= read -r line
do
  printf "%04d:%s\n" $linenumber "$line"
  linenumber=$linenumber+1
done < "$filename"
