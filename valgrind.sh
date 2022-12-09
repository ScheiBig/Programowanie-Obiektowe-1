#!/bin/bash
if [[ $2 = "quiet" ]]
then
    valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-origins=yes -s -q $1
else 
    valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-origins=yes -s $1
fi