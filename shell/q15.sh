#!/bin/bash

# Q15: Sum of n numbers
read -p "How many numbers do you want to sum? " n

sum=0
for ((i=1; i<=n; i++))
do
    read -p "Enter number $i: " val
    sum=$((sum + val))
done

echo "Total sum of $n numbers is $sum"
