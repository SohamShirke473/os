#!/bin/bash

# Q1: File operations
echo "Creating input files..."
printf "Alice\nCharlie\nEve\nBob\nDavid\n" > f1.txt
printf "Frank\nGrace\nHeidi\nIvan\nJudy\n" > f2.txt

echo "a. Concatenating two files:"
cat f1.txt f2.txt

echo -e "\nb. Arranging in ascending order:"
cat f1.txt f2.txt | sort

echo -e "\nc. Arranging in descending order:"
cat f1.txt f2.txt | sort -r

echo -e "\nd. Removing contents of the files..."
> f1.txt
> f2.txt
echo "Files cleared."
