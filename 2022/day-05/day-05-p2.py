#! /usr/bin/env python
import re


# initalize the programm and return stacks as array and procedures as lines
def init():
    with open("day-05-input.txt", "r") as f:
        crates, procedures = f.read().split("\n\n")
        stacks = create_stacks(crates)
        return stacks, procedures.split("\n")


# transform the given string stacks into 2d array stacks
def create_stacks(crates):
    # print(crates)
    *crates, num_stacks = crates.split("\n")
    num_stacks = len(num_stacks.split())

    # creates an empty 2d array of lenght 9
    stacks = [[] for _ in range(num_stacks)]

    # put crates into 2d array at stackIdx from bottom to top
    crates.reverse()
    for line in crates:
        for stackIdx, i in enumerate(range(1, len(crates[0]), 4)):
            if line[i].strip():
                stacks[stackIdx].append(line[i])
    return stacks


# for every instruction find the 3 important numbers: #, from, to
def parse_intructions(instruction):
    crates_to_move, to_stack, from_stack = map(
        int, re.findall(r"[0-9]*[0-9]+", instruction))
    return crates_to_move, to_stack-1, from_stack-1


# main entry point
stacks, procedures = init()
for procedure in procedures:
    if procedure.strip():
        crates_to_move, from_stack, to_stack = parse_intructions(procedure)
        # print(f"{crates_to_move=} {from_stack=} {to_stack=}")

        stacks[to_stack].extend(stacks[from_stack][-crates_to_move:])
        stacks[from_stack] = stacks[from_stack][:-crates_to_move]


# get the last element of each list in a list of lists
[print(stack[-1]) for stack in stacks]
