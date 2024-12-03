#!/bin/bash

# Check if both day and part are provided
if [ "$#" -ne 3 ]; then
    echo "Usage: $0 <year> <day> <part>"
    exit 1
fi

YEAR=$1
DAY=$2
PART=$3

echo "Running solution ${YEAR} day ${DAY} part ${PART}"

# Compile the C file
gcc -o output ./${YEAR}/day${DAY}_part${PART}.c

# Run the output with the corresponding input file
./output < ./${YEAR}/day${DAY}_part${PART}.txt
