#!/bin/bash

# Q7: Customer Records
echo "C01 Mike NewYork 1000" > cust1.txt
echo "C02 Sara London 1500" >> cust1.txt
echo "C03 Tom Paris 800" > cust2.txt
echo "C04 Anna Tokyo 2000" >> cust2.txt

echo "a. Joining files into cust_all.txt and displaying contents:"
cat cust1.txt cust2.txt > cust_all.txt
cat cust_all.txt

echo -e "\nb. Counting contents of cust_all.txt:"
wc cust_all.txt
