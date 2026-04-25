#!/bin/bash

# Q8: Directory Manipulation
echo "Creating OS_Practical directory..."
mkdir -p OS_Practical
cd OS_Practical

echo "Creating file1.txt, file2.txt, file3.txt..."
touch file1.txt file2.txt file3.txt

echo "Copying file1.txt to file1_backup.txt..."
cp file1.txt file1_backup.txt

echo "Creating Backup directory and moving file2.txt into it..."
mkdir -p Backup
mv file2.txt Backup/

echo "Renaming file3.txt to updated_file3.txt..."
mv file3.txt updated_file3.txt

echo "Listing directory contents before removing Backup:"
ls -R

echo "Removing Backup directory and its contents..."
rm -rf Backup

echo "Final directory contents:"
ls
