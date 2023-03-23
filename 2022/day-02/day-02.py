#!/usr/bin/env python
# -*- coding: utf-8 -*-

""" --- Advent of Code 2022 - Day 2: Rock Paper Scissors --- """

import os
import sys


# solution part 1
def part_1():
    score = 0

    with open("input.txt") as f:
        for line in f:
            if line == "A X\n":
                score = score + 4
            elif line == "A Y\n":
                score = score + 8
            elif line == "A Z\n":
                score = score + 3
            elif line == "B X\n":
                score = score + 1
            elif line == "B Y\n":
                score = score + 5
            elif line == "B Z\n":
                score = score + 9
            elif line == "C X\n":
                score = score + 7
            elif line == "C Y\n":
                score = score + 2
            elif line == "C Z\n":
                score = score + 6

    print(score)


# solution part 2
def part_2():
    score = 0

    with open("input.txt") as f:
        for line in f:
            if line == "A X\n":
                score = score + 3
            elif line == "A Y\n":
                score = score + 4
            elif line == "A Z\n":
                score = score + 8
            elif line == "B X\n":
                score = score + 1
            elif line == "B Y\n":
                score = score + 5
            elif line == "B Z\n":
                score = score + 9
            elif line == "C X\n":
                score = score + 2
            elif line == "C Y\n":
                score = score + 6
            elif line == "C Z\n":
                score = score + 7

    print(score)


# main entry point
os.chdir(os.path.dirname(os.path.abspath(__file__)))

if len(sys.argv) > 1 and sys.argv[1] == "-p1":
    part_1()
elif len(sys.argv) > 1 and sys.argv[1] == "-p2":
    part_2()
else:
    print("Usage: python", sys.argv[0], "[-p1|-p2]")
    sys.exit(1)
