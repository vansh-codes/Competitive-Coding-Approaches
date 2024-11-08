#!/bin/bash
# Bash script to undo renaming of files in the current directory by removing the prefix

# Get the current directory
directory=$(pwd)

# Get the list of files with the prefix
files=$(ls -1 | grep '^[0-9]\+_')

for file in $files; do
    # Check if it's a regular file and not the script itself
    if [ -f "$file" ] && [ "$file" != "undoRename.sh" ]; then
        # Remove the prefix (number followed by an underscore)
        new_name=$(echo "$file" | sed 's/^[0-9]\+_//')
        # Rename the file
        mv "$file" "${directory}/${new_name}"
    fi
done
