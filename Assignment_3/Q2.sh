# ------------------------------------------------------------
# Q2) Write a shell program to compare two strings.
# File: Q2.sh
# ------------------------------------------------------------
#!/bin/bash
# Compares two strings entered by user

echo "Enter first string:"
read str1
echo "Enter second string:"
read str2

if [ "$str1" = "$str2" ]; then
    echo "Strings are equal"
else
    echo "Strings are not equal"
fi

