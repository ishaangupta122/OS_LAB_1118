# ------------------------------------------------------------
# Q5) Write a shell program to count words and lines in a file.
# File: Q5.sh
# ------------------------------------------------------------
#!/bin/bash
# Displays total number of words and lines in a given file

echo "Enter filename:"
read fname

if [ -f "$fname" ]; then
    lines=$(wc -l < "$fname")
    words=$(wc -w < "$fname")
    echo "Total Lines: $lines"
    echo "Total Words: $words"
else
    echo "File does not exist!"
fi