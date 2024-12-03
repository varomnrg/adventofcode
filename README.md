# Advent of Code

This repository contains my solutions for the Advent of Code 2024 challenges. Each day has two parts, and each part has corresponding C source files and input files.

## Directory Structure

```
2024
├── day1_part1.c
├── day1_part1.txt
├── day1_part2.c
├── day1_part2.txt
└── output
```

-   Each day has two parts: `day1_part1.c` (C source file) and `day1_part1.txt` (input file).
-   The `output` file is generated after compiling the C source file.

## How to Use the Script

To compile and run the C files, use the `run.sh` script.

### Steps to Use

1. **Make sure you have GCC installed** on your system to compile C programs.

2. **Make the script executable** (if you haven't already):

    ```bash
    chmod +x run.sh
    ```

3. **Run the script with the year, day, and part as arguments**:

    ```bash
    ./run.sh <year> <day> <part>
    ```

    For example, to run the solution for Day 1, Part 1 of the 2024 challenge:

    ```bash
    ./run.sh 2024 1 1
    ```

    This command will:

    - Compile the C file for the given year, day, and part (e.g., `2024/day1_part1.c`).
    - Run the compiled program using the corresponding input file (e.g., `2024/day1_part1.txt`).

### Example Usage

To run Day 1, Part 2 of the 2024 challenge:

```bash
./run.sh 2024 1 2
```

This will compile `2024/day1_part2.c` and run it with `2024/day1_part2.txt` as input.
