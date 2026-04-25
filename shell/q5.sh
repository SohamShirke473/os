#!/bin/bash

# Q5: System Status
echo "1. Top 10 processes in descending order (by %CPU):"
ps -eo pid,ppid,cmd,%cpu,%mem --sort=-%cpu | head -n 11

echo -e "\n2. Process with the highest memory usage:"
ps -eo pid,ppid,cmd,%mem --sort=-%mem | head -n 2

echo -e "\n3. Current user and login name:"
echo "Current user: $(whoami)"
echo "Login name: $USER"

echo -e "\n4. Displaying first 11 lines of /etc/passwd:"
head -n 11 /etc/passwd
