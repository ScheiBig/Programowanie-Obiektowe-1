#!/bin/bash
if [[ "$1" == "" ]];
then
    echo No exercise number specified!;
else
    mkdir "exercise_$1";
    mkdir "exercise_$1/util";
    
    echo "" >> "exercise_$1/main.cpp";
    echo "int main()" >> "exercise_$1/main.cpp";
    echo "{" >> "exercise_$1/main.cpp";
    echo "    " >> "exercise_$1/main.cpp";
    echo "    return 0;" >> "exercise_$1/main.cpp";
    echo "}" >> "exercise_$1/main.cpp";

    echo "" >> ./CMakeLists.txt
    echo "# # Exercise $1" >> ./CMakeLists.txt
    echo "# add_executable(Programowanie_Obiektowe_1" >> ./CMakeLists.txt
    echo "#     exercise_$1/main.cpp" >> ./CMakeLists.txt
    echo "# )" >> ./CMakeLists.txt
fi