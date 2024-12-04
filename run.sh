#!/bin/bash

# Check if all arguments (year, day, part) are provided
if [ "$#" -ne 3 ]; then
    echo "Usage: $0 <year> <day> <part>"
    exit 1
fi

YEAR=$1
DAY=$2
PART=$3

echo "Running solution ${YEAR} Day ${DAY} Part ${PART}"

# Define the input file path
INPUT_FILE="./${YEAR}/day${DAY}_part${PART}.txt"

# Check if the input file exists, and create it if it doesn't
if [ ! -f "$INPUT_FILE" ]; then
    echo "Input file ${INPUT_FILE} does not exist. Creating it..."
    mkdir -p "./${YEAR}" 
    touch "$INPUT_FILE" 
    echo "# Add your input data here" > "$INPUT_FILE"
    echo "Created ${INPUT_FILE}."
fi

# Compile the C file
C_FILE="./${YEAR}/day${DAY}_part${PART}.c"
if [ ! -f "$C_FILE" ]; then
    echo "C file ${C_FILE} does not exist. Exiting."
    exit 1
fi

gcc -o output "$C_FILE"

# Run the compiled program with the input file
if [ -x "./output" ]; then
    ./output < "$INPUT_FILE"
else
    echo "Compilation failed or output file is not executable."
    exit 1
fi
