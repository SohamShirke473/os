#!/bin/bash

# Q3: Fibonacci series
read -p "Enter the number of terms: " n

a=0
b=1
count=0

echo "Fibonacci Series:"
while [ $count -lt $n ]
do
    echo -n "$a "
    fn=$((a + b))
    a=$b
    b=$fn
    count=$((count + 1))
done
echo ""
