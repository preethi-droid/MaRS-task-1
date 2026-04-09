#!/bin/bash

# This is to generate random battery percentage (0–100)
battery=$((RANDOM % 101))
echo "Battery Level: $battery%"

# Checking battery percentage and giving instructions to be followed then
if [ $battery -lt 20 ]; then
    echo "Battery low! Return to base!"
    exit 1
fi

# Checking the internet connectivity using ping, also used chatgpt extensively to get the code and understand it better
ping -c 1 google.com > /dev/null 2>&1

if [ $? -ne 0 ]; then
    echo "Communication failure!"
    exit 1
fi

# If everything is fine, the previous exit wouldn't be executed and the following line would be executed
echo "All systems operational!"
