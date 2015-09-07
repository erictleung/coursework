#!/bin/bash

echo "Let us download a yeast genome and perform some analyses on it."

# get data from SGD if file doesn't already exists
FILE=../data/sc.gff
if [ -f $FILE ]; 
then
    echo "File is already downloaded. Let us continue."
else
    curl http://downloads.yeastgenome.org/curation/chromosomal_feature/saccharomyces_cerevisiae.gff -o $FILE
    echo "Done downloading yeast genome for Saccharomyces cerevisiae."
fi
echo "We now have the genome we want to study.\n"

# find out how many lines this file has
echo "Let us find how many lines are in this file."
read -p "(Press enter to continue)" NULL
echo "> wc -l ../data/sc.gff"
wc -l ../data/sc.gff
echo ""

# let us look at the beginning of the file
echo "Let's look at just the beginning of the file to see what it looks like."
read -p "(Press enter to continue)" NULL
echo "> head ../data/sc.gff"
head ../data/sc.gff
echo ""

# search for some simple patterns
echo "Let's find the simple pattern of 'YAL060W' in our file."
read -p "(Press enter to continue)" NULL
echo "> grep YAL060W ../data/sc.gff"
grep YAL060W ../data/sc.gff
echo ""

# how many lines match the word gene using piping/chaining commands
echo "Let's see how many times the word 'gene' appears in the file."
read -p "(Press enter to continue)" NULL
echo "> grep gene ../data/sc.gff | wc -l"
grep gene ../data/sc.gff | wc -l
