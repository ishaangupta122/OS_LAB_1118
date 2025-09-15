# ------------------------------------------------------------
# Q1) Write a shell program to add two numbers.
# File: Q1.sh
# ------------------------------------------------------------
#!/bin/bash
# This script reads two numbers from user and prints their sum

echo "Enter first number:"
read a
echo "Enter second number:"
read b
sum=$((a + b))
echo "Sum = $sum"
