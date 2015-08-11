#!/bin/bash

echo "Let us download a yeast genome and perform some analyses on it."

# get data from SGD if file doesn't already exists
FILE=../data/sc.gff
if [ -f $FILE ]; 
then
    echo "File is already downloaded. Let us continue."
else
    curl \
    http://downloads.yeastgenome.org/curation/chromosomal_feature/saccharomyces_cerevisiae.gff \
    -o ../data/sc.gff
    echo "Done downloading yeast genome for Saccharomyces cerevisiae."
fi
echo "We now have the genome we want to study.\n"

# find out how many lines this file has
read -p "Let us find how many lines are in this file. \
(Press enter to continue) " NULL
wc -l ../data/sc.gff

# let us look at the beginning of the file
read -p "Let's look at just the beginning of the file to see what it looks \
like. (Press enter to continue) " NULL
head ../data/sc.gff
