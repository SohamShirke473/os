#!/bin/bash

# Q6: Employee Records
echo "101 John 50000 Manager" > emp1.txt
echo "102 Jane 60000 Director" >> emp1.txt
echo "103 Bob 45000 Clerk" > emp2.txt
echo "104 Alice 55000 Engineer" >> emp2.txt

echo "a. Joining files into emp_all.txt and displaying contents:"
cat emp1.txt emp2.txt > emp_all.txt
cat emp_all.txt

echo -e "\nb. Counting lines, words, and characters in emp_all.txt:"
wc emp_all.txt
