#!/usr/bin/env python
# -*- coding: utf-8 -*-

""" --- Advent of Code 2022 - Validator --- """

import os
import subprocess

repo_path = "/Users/jmetrikat/Code/jmetrikat/advent-of-code"
timeout_in_seconds = 10
EXPECTED_OUTPUTS = {
    "day-01": ("66487", "197301"),
    "day-02": ("15523", "15702"),
    "day-03": ("8493", "2552"),
    "day-04": ("464", "770"),
    "day-05": ("TWSGQHNHL", "JNRSCDWPP"),
    "day-06": ("1766", "2383"),
    "day-07": ("1348005", "12785886"),
    "day-08": ("1543", "595080"),
    "day-09": ("5619", "2376"),
    "day-10": ("14060", "###...##..###..#..#.####.#..#.####...##.\n#..#.#..#.#..#.#.#..#....#.#..#.......#.\n#..#.#..#.#..#.##...###..##...###.....#.\n###..####.###..#.#..#....#.#..#.......#.\n#....#..#.#....#.#..#....#.#..#....#..#.\n#....#..#.#....#..#.#....#..#.####..##.."),
    "day-11": ("", ""),
    "day-12": ("330", "321"),
    "day-13": ("6420", "22000"),
    "day-14": ("1072", "24659"),
    "day-15": ("", ""),
    "day-16": ("", ""),
    "day-17": ("3127", "1514285714288"),
    "day-18": ("", ""),
    "day-19": ("", ""),
    "day-20": ("", ""),
    "day-21": ("", ""),
    "day-22": ("", ""),
    "day-23": ("", ""),
    "day-24": ("", ""),
    "day-25": ("20=2-02-0---02=22=21", ":)"),
}


# run part 1 and part 2 of each day
def run_python_solution(day, part):
    try:
        os.chdir(f"{repo_path}/2022/{day}")
        output = subprocess.check_output(["/opt/homebrew/bin/python3.11", f"{repo_path}/2022/{day}/day-{day[-2:]}.py", f"-p{part}"], stderr=subprocess.STDOUT, timeout=timeout_in_seconds)
        return output.strip().decode("utf-8")
    except subprocess.TimeoutExpired:
        return f" Part {part} timed out after {timeout_in_seconds} seconds."
    except subprocess.CalledProcessError as e:
        print(f"Error running {day} part {part}:")
        print(e.output.decode("utf-8"))
        return None


# run part 1 and part 2 of each day using C
def run_c_solution(day, part):
    try:
        output = subprocess.check_output([f"{repo_path}/2022/{day}/day-{day[-2:]}", f"-p{part}", f"{repo_path}/2022/{day}/input.txt"], stderr=subprocess.STDOUT, timeout=timeout_in_seconds)
        return output.strip().decode("utf-8")
    except subprocess.TimeoutExpired:
        return f" Part {part} timed out after {timeout_in_seconds} seconds."
    except subprocess.CalledProcessError as e:
        print(f"Error running {day} part {part}:")
        print(e.output.decode("utf-8"))
        return None


# validate each day
def validate_solution(day, choice):
    expected_output = EXPECTED_OUTPUTS[day]
    if expected_output == ("", ""):
        print(f"Day-{day[-2:]} is still missing.")
        return

    if choice == "1":
        output_part_1 = run_c_solution(day, 1)
        output_part_2 = run_c_solution(day, 2)
    elif choice == "2":
        output_part_1 = run_python_solution(day, 1)
        output_part_2 = run_python_solution(day, 2)

    if output_part_1 == expected_output[0] and output_part_2 == expected_output[1]:
        print(f"Day-{day[-2:]} is correct!")
        return 0

    else:
        print(f"Day-{day[-2:]} is incorrect:")

        if output_part_1 == expected_output[0]:
            print(f" Part 1 is correct!")
        elif "timed out" in output_part_1:
            print(output_part_1)
        elif output_part_1 != expected_output[0]:
            print(f" Part 1 output: expected '{expected_output[0]}', got '{output_part_1}'")

        if output_part_2 == expected_output[1]:
            print(f" Part 2 is correct!")
        elif "timed out" in output_part_2:
            print(output_part_2)
        elif output_part_2 != expected_output[1]:
            print(f" Part 2 output: expected '{expected_output[1]}', got '{output_part_2}'")

        return 1


# main entry point
# ask user to choose between c and python
print("Choose a language:")
print(" 1) C")
print(" 2) Python")
choice = input("Your choice: ")

# run c solutions
if choice == "1":
    correct = 0
    lang = "C"

    os.chdir(f"{repo_path}/2022")
    subprocess.run(["make", "clean"], check=True)
    subprocess.run(["make", "all"], check=True, stderr=subprocess.DEVNULL)

    for i in range(1, 26):
        day = f"day-{i:02}"
        if validate_solution(day, "2") == 0:
            correct += 1

    os.chdir(f"{repo_path}/2022")
    subprocess.run(["make", "clean"], check=True)
    print('\033[1m' + f"{correct}/25 days correct in {lang}." + '\033[0m')

# run python solutions
elif choice == "2":
    correct = 0
    lang = "Python"

    for i in range(1, 26):
        day = f"day-{i:02}"
        if validate_solution(day, "2") == 0:
            correct += 1

    print('\033[1m' + f"{correct}/25 days correct in {lang}." + '\033[0m')

else:
    print("Invalid choice")
    exit(1)
