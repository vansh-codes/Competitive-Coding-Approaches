#!/bin/bash
# Bash script to rename files in the current directory by adding a prefix based on creation time

# Get the current directory
directory=$(pwd)

# Get the list of files sorted by creation time
files=$(ls -1tr --time=creation "$directory")

# Initialize the prefix counter
counter=1

# Iterate over the sorted list and rename each file
# Extract the maximum counter value from existing files
max_counter=$(ls -1 | grep -o '^[0-9]\+_' | grep -o '^[0-9]\+' | sort -nr | head -n 1)
counter=$((max_counter + 1))

for file in $files; do
    # Check if it's a regular file and not the script itself
    if [ -f "$file" ] && [ "$file" != "rename.sh" ] && [ "$file" != "undoRename.sh" ]; then
        # Check if the file already has the correct prefix
        if [[ ! "$file" =~ ^[0-9]+_ ]]; then
            # Rename the file by adding the prefix
            mv "$file" "${directory}/${counter}_$file"
            # Increment the counter
            counter=$((counter + 1))
        fi
    fi
done