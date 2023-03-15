#!/usr/bin/env python
# -*- coding: utf-8 -*-

""" --- Advent of Code 2022 - Day 5: Supply Stacks --- """

import re
import sys


# initialize the program and return stacks as array and procedures as lines
def init() -> tuple:
    with open("input.txt", "r") as f:
        crates, procedures = f.read().split("\n\n")
        stacks = create_stacks(crates)
        return stacks, procedures.split("\n")


# transform the given string stacks into 2d array stacks
def create_stacks(crates: str) -> list:
    *crates, num_stacks = crates.split("\n")
    num_stacks = len(num_stacks.split())

    # creates an empty 2d array of length 9
    stacks = [[] for _ in range(num_stacks)]

    # put crates into 2d array at stackIdx from bottom to top
    crates.reverse()
    for line in crates:
        for stackIdx, i in enumerate(range(1, len(crates[0]), 4)):
            if line[i].strip():
                stacks[stackIdx].append(line[i])

    return stacks


# for every instruction find the 3 important numbers: #, from, to
def parse_instructions(instruction: str) -> tuple:
    crates_to_move, to_stack, from_stack = map(int, re.findall(r"[0-9]*[0-9]+", instruction))
    return crates_to_move, to_stack-1, from_stack-1


# solution part 1
def part_1():
    stacks, procedures = init()
    for procedure in procedures:
        if procedure.strip():
            crates_to_move, from_stack, to_stack = parse_instructions(procedure)

            # move one crate at a time
            for _ in range(crates_to_move):
                stacks[to_stack].append(stacks[from_stack].pop())

    # print the last element of each list in a list of lists
    [print(stack[-1], end="") for stack in stacks]
    print()


# solution part 2
def part_2():
    stacks, procedures = init()
    for procedure in procedures:
        if procedure.strip():
            crates_to_move, from_stack, to_stack = parse_instructions(procedure)

            # move crates at once
            stacks[to_stack].extend(stacks[from_stack][-crates_to_move:])
            stacks[from_stack] = stacks[from_stack][:-crates_to_move]

    # print the last element of each list in a list of lists
    [print(stack[-1], end="") for stack in stacks]
    print()


# main entry point
if len(sys.argv) > 1 and sys.argv[1] == "-p1":
    part_1()
elif len(sys.argv) > 1 and sys.argv[1] == "-p2":
    part_2()
else:
    print("Usage: python", sys.argv[0], "[-p1|-p2]")
    sys.exit(1)
