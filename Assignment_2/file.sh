# ------------------------------------------------------------
# LAB Assignment 2 – Operating Systems (UCS-303)
# ------------------------------------------------------------

# Q1) Introduction of Internal and External Commands
# - Internal commands: Built into the shell, no separate binary.
#   Example: cd, echo, pwd, set
# - External commands: Stored as executables in /bin, /usr/bin, etc.
#   Example: ls, cat, grep, cp

# ------------------------------------------------------------

# Q2) Pipelining (Feeding output of one command to another)
# command1 | command2
# Example:
#   ls -l | grep ".txt"
# Output of ls -l is passed as input to grep.

# ------------------------------------------------------------


# Q3) expr, locate command
# a) expr - evaluates expressions
#   expr 5 + 3
#   expr 10 \* 2
#
# b) locate - quickly find files by name
#   locate filename.txt

# ------------------------------------------------------------

# Q4) echo command
# echo "Hello World"
# echo $USER
# echo "Today is $(date)"

# ------------------------------------------------------------

# Q5) Using . and ..
# .         current directory
# ..        parent directory
# cd ..     # go one directory up
# cd .      # stay in current directory

# ------------------------------------------------------------

# Q6) Ways for signing off from Linux
# logout      -> end terminal session
# exit        -> exit shell
# Ctrl+D      -> shortcut for exit
# shutdown -h now   -> shutdown system
# reboot      -> restart system

# ------------------------------------------------------------

# Q7) ping, man, help command
# ping <host>   -> check network connectivity
# man <command> -> manual page of command
# help <cmd>    -> help for shell built-in commands

# ------------------------------------------------------------

# Q8) Combining Commands
# ;   -> run sequentially (ignores errors)
# &&  -> run next only if previous succeeds
# ||  -> run next only if previous fails
# Example:
#   mkdir test && cd test

# ------------------------------------------------------------

# Q9) File Permissions and chmod
# File permissions: r (read), w (write), x (execute)
# chmod [permissions] filename
# Examples:
#   chmod 755 file.sh   -> rwx for owner, r-x for group, r-x for others
#   chmod u+x file.sh   -> give execute to user
#   chmod g-w file.sh   -> remove write from group

# ------------------------------------------------------------

# Q10) vi editor basics
# vi filename     -> open file
# Modes:
#   i   -> insert mode
#   Esc -> command mode
# Save & Exit:
#   :wq   -> save and quit
#   :q!   -> quit without saving

# Example paragraph in vi:
# "Operating Systems manage hardware and software resources.
# They provide services for efficient execution of programs.
# Linux is a popular open-source operating system."

# ------------------------------------------------------------
# Self Study
# ------------------------------------------------------------

# Q1) grep, sort, ps command
# grep "pattern" file   -> search for a pattern
# sort file.txt         -> sort lines alphabetically
# ps aux                -> show running processes

# ------------------------------------------------------------

# Q2) Basics of Shell Programming
# - A shell script is a text file containing Unix commands.
# - Steps:
#   nano script.sh
#   chmod +x script.sh
#   ./script.sh

# Variables:
# name="Ishaan"
# echo $name
# read age
# echo "Age = $age"

# Arithmetic with expr:
# expr 5 + 3
# sum=`expr $a + $b`

# ------------------------------------------------------------
# Operators in Shell
# -gt   greater than
# -lt   less than
# -ge   greater/equal
# -le   less/equal
# -eq   equal
# -ne   not equal
# -a    logical AND
# -o    logical OR
# !     logical NOT

# ------------------------------------------------------------
# Control Instructions in Shell
# Sequence, Selection, Repetition, Case

# If-Else:
# if [ $a -gt $b ]
# then
#   echo "a > b"
# else
#   echo "b >= a"
# fi

# For Loop:
# for i in 1 2 3
# do
#   echo $i
# done

# While Loop:
# while [ $a -lt 5 ]
# do
#   echo $a
#   a=`expr $a + 1`
# done

# Until Loop:
# until [ $a -gt 5 ]
# do
#   echo $a
#   a=`expr $a + 1`
# done

# Case:
# case $choice in
#   1) echo "One";;
#   2) echo "Two";;
#   *) echo "Invalid";;
# esac

# ------------------------------------------------------------
# Steps to write and execute a script
# ------------------------------------------------------------
# 1) Open terminal, go to directory
# 2) Create a file: nano script.sh
# 3) Write script inside
# 4) Make it executable: chmod +x script.sh
# 5) Run it: ./script.sh
# ------------------------------------------------------------
