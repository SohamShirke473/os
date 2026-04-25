#!/bin/bash

# Q2: Armstrong Number (3-digit)
read -p "Enter a 3-digit number: " num

if [[ ! $num =~ ^[0-9]{3}$ ]]; then
    echo "Error: Please enter a 3-digit number."
    exit 1
fi

temp=$num
sum=0

while [ $temp -gt 0 ]
do
    digit=$((temp % 10))
    sum=$((sum + digit * digit * digit))
    temp=$((temp / 10))
done

if [ $sum -eq $num ]; then
    echo "$num is an Armstrong number."
else
    echo "$num is not an Armstrong number."
fi
