#!/bin/dash

# 1st arg is Leetcode Number, 2nd arg is Question Name

if [ "$#" -ne 2 ]
then
    echo "Incorrect command line arguments"
    exit 1
fi

# Create folder and corresponding C++ file
# mkdir "$1" && touch "$1"/"$2".cpp

# Append add_executable line to CMakeLists.txt
echo "add_executable($2 $1/$2.cpp)" >> CMakeLists.txt
