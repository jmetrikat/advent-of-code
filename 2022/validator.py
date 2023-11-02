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
    "day-15": ("5367037", "11914583249288"),
    "day-16": ("", ""),
    "day-17": ("3127", "1514285714288"),
    "day-18": ("3326", "1996"),
    "day-19": ("", ""),
    "day-20": ("11123", "4248669215955"),
    "day-21": ("93813115694560", "3910938071092"),
    "day-22": ("3590", "86382"),
    "day-23": ("4109", "1055"),
    "day-24": ("247", "728"),
    "day-25": ("20=2-02-0---02=22=21", ":)"),
}


# run part 1 and part 2 of each day in Python
def run_python_solution(day: str, part: int) -> str:
    try:
        os.chdir(f"{repo_path}/2022/{day}")
        output = subprocess.check_output(["/opt/homebrew/bin/python3.11", f"{repo_path}/2022/{day}/day-{day[-2:]}.py", f"-p{part}"], stderr=subprocess.STDOUT, timeout=timeout_in_seconds)
        return output.strip().decode("utf-8")
    except subprocess.TimeoutExpired as e:
        return f" Part {part} timed out after {timeout_in_seconds} seconds."
    except subprocess.CalledProcessError as e:
        return e.output.decode("utf-8")


# run part 1 and part 2 of each day in C
def run_c_solution(day: str, part: int) -> str:
    try:
        output = subprocess.check_output([f"{repo_path}/2022/{day}/day-{day[-2:]}", f"-p{part}", f"{repo_path}/2022/{day}/input.txt"], stderr=subprocess.STDOUT, timeout=timeout_in_seconds)
        return output.strip().decode("utf-8")
    except subprocess.TimeoutExpired as e:
        return f" Part {part} timed out after {timeout_in_seconds} seconds."
    except subprocess.CalledProcessError as e:
        return e.output.decode("utf-8")


# validate part 1 and part 2 of each day
def validate_part(expected_output: str, actual_output: str, part: int) -> (bool, str):
    if actual_output == expected_output:
        return True, f" Part {part} is correct!"
    elif "timed out" in actual_output:
        return False, f" Part {part} timed out after {timeout_in_seconds} seconds."
    elif "can't open file" in actual_output:
        return False, f" Part {part}: File not found."
    else:
        return False, f" Part {part} output: expected '{expected_output}', got '{actual_output}'"


# validate each day
def validate_solution(day: str, choice: str) -> int:
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

    part1_is_correct, message_1 = validate_part(expected_output[0], output_part_1, 1)
    part2_is_correct, message_2 = validate_part(expected_output[1], output_part_2, 2)

    print(f"Day-{day[-2:]} is {'correct.' if part1_is_correct and part2_is_correct else 'incorrect:'}")
    if not (part1_is_correct and part2_is_correct):
        print(message_1)
        print(message_2)

    return 0 if part1_is_correct and part2_is_correct else 1


# main entry point: ask user to choose between C and Python
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
