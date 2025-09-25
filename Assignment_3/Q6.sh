# ------------------------------------------------------------
# Q6) Script to display file information.
# File: Q6.sh
# ------------------------------------------------------------
#!/bin/bash
# Takes filename as input and shows details (size, permissions, owner, modification time)

echo "Enter filename:"
read fname

if [ -f "$fname" ]; then
    echo "File Size: $(stat -c%s "$fname") bytes"
    echo "Permissions: $(stat -c%A "$fname")"
    echo "Owner: $(stat -c%U "$fname")"
    echo "Modification Time: $(stat -c%y "$fname")"
else
    echo "File does not exist!"
fi