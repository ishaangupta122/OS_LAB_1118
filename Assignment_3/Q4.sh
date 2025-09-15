# ------------------------------------------------------------
# Q4) Write a shell program to check VOWEL or CONSONANT.
# File: Q4.sh
# ------------------------------------------------------------
#!/bin/bash
# Checks whether entered character is vowel or consonant using switch-case

echo "Enter a character:"
read ch

case $ch in 
    [aeiouAEIOU]) echo "Vowel";;
    [bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ]) echo "Consonant";;
    *) echo "Not an alphabet";;
esac