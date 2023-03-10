#!/usr/bin/env python
# -*- coding: utf-8 -*-

""" --- Advent of Code 2022 - Day 1: Calorie Counting --- """

import sys


# solution part 1
def part_1():
    maximum = 0
    calorie_sum = 0

    with open('input.txt') as f:
        for line in f.readlines():
            if line == "\n":
                if calorie_sum >= maximum:
                    maximum = calorie_sum
                calorie_sum = 0
            else:
                calorie_sum += int(line)

    print(maximum)


# solution part 2
def part_2():
    calorie_sum = 0
    blocks = []

    with open('input.txt') as f:
        for line in f.readlines():
            if line == "\n":
                blocks.append(calorie_sum)
                calorie_sum = 0
            else:
                calorie_sum += int(line)

    blocks.sort()
    print(sum(blocks[-3:]))


# main entry point
if len(sys.argv) > 1 and sys.argv[1] == "-p1":
    part_1()
elif len(sys.argv) > 1 and sys.argv[1] == "-p2":
    part_2()
else:
    print("Usage: python", sys.argv[0], "[-p1|-p2]")
    sys.exit(1)
