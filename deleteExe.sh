#!/bin/bash
# Bash script to delete all .exe files in the current directory

# Get the current directory
directory=$(pwd)

# Find and delete all .exe files in the directory, printing only the file names
find "$directory" -name "*.exe" -type f -exec rm -f {} \; -exec basename {} \;

# find "$directory" searches for files in the current directory and its subdirectories
# -name "*.exe" specifies that we are looking for files with the .exe extension
# -type f specifies that we are only interested in regular files and not folders
# -exec rm -f {} \; executes the rm -f command on each file found i.e deletes the file
# -exec basename {} \; prints only the file names without the full path