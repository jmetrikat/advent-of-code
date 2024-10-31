# 🎄 Advent of Code

![Advent of Code](https://img.shields.io/badge/Advent_of_Code-54c637?style=flat-square&logo=adventofcode)
![C Badge](https://img.shields.io/badge/C-grey?style=flat-square&logo=c&logoColor=white)
![CMake Badge](https://img.shields.io/badge/CMake-grey?style=flat-square&logo=cmake)
![Go Badge](https://img.shields.io/badge/Go-grey?style=flat-square&logo=go&logoColor=white)
![Python Badge](https://img.shields.io/badge/Python-grey?style=flat-square&logo=python&logoColor=white)

My Advent of Code solutions, written in C, Go and Python.

🗓️ [2023: Progress Tracker](./2023/README.md) \
🗓️ [2022: Progress Tracker](./2022/README.md)


## Usage
### 2022
#### Python
1. Navigate to the directory of the specific day, e.g. `cd 2022/day-01`.
2. Run the Python code:
    ```shell
    python3 day-01.py -p1 # Part 1
    python3 day-01.py -p2 # Part 2
    ```

#### C
1. Navigate to the directory of the specific day, e.g. `cd 2022/day-01`.
2. Compile the C code:
   ```shell
   gcc -o day-01 day-01.c
    ```
3. Run the executable:
    ```shell
    ./day-01 -p1 input.txt # Part 1
    ./day-01 -p2 input.txt # Part 2
    ```

### 2023
#### Go
1. Navigate to the directory of the specific day, e.g. `cd 2023/day-01`.
2. Run the Go code:
    ```shell
    go run day-01.go -p1 # Part 1
    go run day-01.go -p2 # Part 2
    ```

## Test
### 2023

1. Navigate to the directory of the specific day, e.g. `cd 2023/day-01`.
2. Run the test:
    ```shell
    go test
    ```
3. Check the output - it should look like:
   ```sh
   PASS
   ok  	main/day-01	0.166s
    ```
