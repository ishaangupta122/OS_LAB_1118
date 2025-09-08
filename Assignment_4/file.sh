# ------------------------------------------------------------
# LAB Assignment 4 – Operating Systems (UCS-303)
# ------------------------------------------------------------
# Instructions:
# - The instructor is required to discuss the concept of system calls.
# - Students are required to implement the following system calls related 
#   to process and file management.

# ------------------------------------------------------------
# Q1) Write a program to implement fork() system call
# ------------------------------------------------------------
# fork() is used to create a new process.
# - Returns:
#   0  → to the child process
#   >0 → process ID of child (to parent)
#   <0 → error

# Example (C Program): file1.c

# ------------------------------------------------------------
# Q2) Write a program to implement wait() and exit() system calls
# ------------------------------------------------------------
# wait() makes parent wait until child terminates.
# exit() terminates a process with a status code.

# Example (C Program): file2.c


# ------------------------------------------------------------
# Q3) Write a program to implement execv() system call
# ------------------------------------------------------------
# execv() replaces the current process with a new program.
# Syntax: int execv(const char *path, char *const argv[]);

# Example (C Program): 
# File 1 - file3a.c
# File 2 - file3b.c

# ------------------------------------------------------------
# Q4) Write a program to implement open(), read(), write(), close() system calls
# ------------------------------------------------------------
# open()  → opens a file
# read()  → reads data from a file
# write() → writes data into a file
# close() → closes a file

# Example (C Program): file4.c & test.txt
