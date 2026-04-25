#!/bin/bash

# Q12: Multiplication Table
read -p "Enter a number n: " n

echo "Multiplication Table for $n:"
for i in {1..10}
do
    echo "$n x $i = $((n * i))"
done
