#!/bin/bash

# Q18: Sum of 1st n odd numbers
echo "Enter a number n: "
read n

sum=0
count=0
num=1

while [ $count -lt $n ]
do
    sum=$((sum + num))
    num=$((num + 2))
    count=$((count + 1))
done

echo "Sum of the first $n odd numbers is $sum"
