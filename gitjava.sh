#!/bin/dash

if [ "$#" -ne 1 ]; then
    echo "Incorrect command line arguments"
    exit 1
fi

# Automating git stuff
git add .
git commit -m "Solution for $1 in Java"
git push
