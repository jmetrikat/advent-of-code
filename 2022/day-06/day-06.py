#!/usr/bin/env python
# -*- coding: utf-8 -*-

""" --- Advent of Code 2022 - Day 6: Tuning Trouble --- """

import sys


# check if all 14 characters are different
def is_marker(i, marker_size, input):
    for j in range(0, marker_size - 1):
        for k in range(1, marker_size):
            if input[i + j] == input[i + k] and (i + j) != (i + k):
                return 0

    return 1


# solution part 1
def part_1():
    # define marker size
    marker_size = 4

    # compare consecutive four characters and print starting position, if marker detected
    with open("input.txt") as f:
        input = f.read()

        for i in range(len(input)):
            if input[i] != input[i + 1] and input[i] != input[i + 2] and input[i] != input[i + 3] and input[i + 1] != input[i + 2] and input[i + 1] != input[i + 3] and input[i + 2] != input[i + 3]:
                print(i + marker_size)
                break


# solution part 2
def part_2():
    # define marker size
    marker_size = 14

    # compare consecutive 14 characters and print starting position, if marker detected
    with open("input.txt") as f:
        input = f.read()

        for i in range((len(input) - marker_size)):
            if is_marker(i, marker_size, input):
                print(i + marker_size)
                break


# main entry point
if len(sys.argv) > 1 and sys.argv[1] == "-p1":
    part_1()
elif len(sys.argv) > 1 and sys.argv[1] == "-p2":
    part_2()
else:
    print("Usage: python", sys.argv[0], "[-p1|-p2]")
    sys.exit(1)
