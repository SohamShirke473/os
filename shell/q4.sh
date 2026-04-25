#!/bin/bash

# Q4: Voting eligibility
read -p "Enter your age: " age

if [ $age -ge 18 ]; then
    echo "You are eligible to vote."
else
    echo "You are not eligible to vote. You need to be 18 or older."
fi
