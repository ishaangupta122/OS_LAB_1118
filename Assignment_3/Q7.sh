# ------------------------------------------------------------
# Q7) Script to display system information.
# File: Q7.sh
# ------------------------------------------------------------
#!/bin/bash
# Displays OS version, CPU info, memory usage, disk usage, and network details

echo "OS Version:"
uname -a

echo -e "\nCPU Info:"
lscpu | grep "Model name"

echo -e "\nMemory Info:"
free -h

echo -e "\nDisk Usage:"
df -h

echo -e "\nNetwork Details:"
ifconfig