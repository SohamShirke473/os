#!/bin/bash

read a b

temp=$a
a=$b
b=$temp

echo "After swap: $a $b"