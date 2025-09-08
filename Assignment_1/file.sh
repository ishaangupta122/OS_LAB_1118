# ------------------------------------------------------------
# LAB Assignment – Operating Systems (UCS-303)
# ------------------------------------------------------------

# Q1) Introduction to the Operating System with Key Functions
# - OS is system software that manages computer hardware and software resources.
# - Key functions:
#   Process management
#   Memory management
#   File system management
#   Device management
#   Security and protection
#   User interface (CLI/GUI)

# ------------------------------------------------------------

# Q2) Introduction to Unix/Linux Architecture
# - User
# - Shell (command interpreter)
# - Kernel (core of OS)
# - Hardware
# Layers:
#   User -> Shell -> Kernel -> Hardware
# Kernel handles low-level tasks like memory, CPU, and devices.
# Shell acts as a bridge between user and kernel.

# ------------------------------------------------------------

# Q3) Concept of Shell
# - A shell is a command-line interpreter.
# - It takes commands from the user and passes them to the kernel.
# - Supports command execution, scripting, I/O redirection, and automation.

# ------------------------------------------------------------

# Q4) Types of Shell
# sh   (Bourne Shell)
# bash (Bourne Again Shell)
# csh  (C Shell)
# ksh  (Korn Shell)
# zsh  (Z Shell)
# Most Linux systems use bash as default.

# ------------------------------------------------------------

# Q5) Command Structure
# Format:
#   command [options] [arguments]
# Example:
#   ls -l /home
#   (command=ls, option=-l, argument=/home)

# ------------------------------------------------------------
# Q6) Basic Linux Commands
# ------------------------------------------------------------

# (Super User Do) - sudo [cmd]
# -i    open root shell
# -s    run shell with root privileges
# -k    reset cached credentials

# (List) - ls [options] [path]
# -l    long listing format
# -a    show hidden files
# -R    recursive listing
# -h    human-readable sizes
# -t    sort by modification time

# (Print Working Directory) - pwd [options]
# -L    logical path (default, shows symlinks)
# -P    physical path (resolves symlinks)

# (Make Directory) - mkdir [options] dir_name
# -p    create parent directories if not exist
# -v    verbose output

# (Remove Directory) - rmdir [options] dir_name
# -p    remove parent directories if empty
# -v    verbose output

# (Remove) - rm [options] file_or_directory
# -f    force delete without confirmation
# -r    recursive (delete folders with content)
# -v    verbose

# (Change Directory) - cd [path]
# cd      -> go to home directory
# cd ..   -> move up one level
# cd -    -> switch to previous directory

# (Copy) - cp [options] source destination
# -r    copy directories recursively
# -i    prompt before overwrite
# -u    copy only if source is newer
# -v    verbose output

# (Word Count) - wc [options] file
# -l    count lines
# -w    count words
# -c    count bytes
# -m    count characters

# (Move/Rename) - mv [options] source destination
# -i    prompt before overwrite
# -f    force move without prompt
# -n    no overwrite
# -v    verbose

# (Compare) - cmp [options] file1 file2
# -l    print differing bytes
# -s    silent (return only exit status)

# (Change Password) - passwd [options] [username]
# -d    delete password
# -e    expire password immediately
# -l    lock account
# -u    unlock account

# (Who) - who [options]
# -a    show all details
# -q    show only usernames and count
# -u    show idle time

# (Unix Name) - uname [options]
# -s    kernel name
# -n    node/hostname
# -r    kernel release
# -v    kernel version
# -m    machine hardware
# -a    all details

# ------------------------------------------------------------
# Q7) Install, Update, Upgrade and Remove Packages (apt-get)
# ------------------------------------------------------------

# (Install a Package) - sudo apt-get install <pkg>
# (Update Package List) - sudo apt-get update
# (Upgrade Installed Packages) - sudo apt-get upgrade
# (Remove a Package) - sudo apt-get remove <pkg>

# ------------------------------------------------------------
# Q8) > and >> Operators in Linux
# ------------------------------------------------------------

# (Output Redirection – Overwrite) - command > filename
# (Output Redirection – Append) - command >> filename

# ------------------------------------------------------------
# Q9) Concatenate - cat [options] [file]
# ------------------------------------------------------------

# -n    show line numbers
# -s    remove repeated blank lines
# -E    show $ at end of each line
# -T    show TAB characters as ^I
# -v    show non-printing characters

# ------------------------------------------------------------
# Q10) Compressing and Archiving Files (zip, tar)
# ------------------------------------------------------------

# (zip Command) - zip [options] archive_name.zip file1 file2 ...
# -r    recursively include all files in directories
# -u    update existing files in zip archive
# -d    delete files from zip archive
# -9    maximum compression

# (tar Command) - tar [options] archive_name.tar file1 file2 ...
# -c    create archive
# -x    extract archive
# -t    list contents
# -v    verbose (show progress)
# -f    specify filename of archive
# -z    compress using gzip (.tar.gz)
# -j    compress using bzip2 (.tar.bz2)
# ------------------------------------------------------------
