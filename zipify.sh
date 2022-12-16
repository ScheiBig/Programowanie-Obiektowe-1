#!/bin/bash
for i in */; 
do 
    if [[ "${i%/}" == *"exercise"* ]];
    then
        echo executing zip -r "${i%/}__241204.zip" "$i";
        if [[ "$1" == "run" ]];
        then
            zip -r "${i%/}__241204.zip" "$i";
        fi
    fi
done