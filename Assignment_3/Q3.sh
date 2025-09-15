# ------------------------------------------------------------
# Q3) Write a shell program to generate Fibonacci series.
# File: Q3.sh
# ------------------------------------------------------------
#!/bin/bash
# Generates Fibonacci series up to n terms

echo "Enter the number of terms:"
read n

a=0
b=1

echo "Fibonacci Series:"
for (( i=0; i<n; i++ ))
do
    echo -n "$a "
    fn=$((a + b))
    a=$b
    b=$fn
done
echo