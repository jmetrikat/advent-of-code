#!/usr/bin/env python
# -*- coding: utf-8 -*-

""" --- Advent of Code 2022 - Day 4: Camp Cleanup --- """

import re
import sys


# solution part 1
def part_1():
    with open("input.txt", "r") as f:
        result = 0

        for line in f.read().split("\n"):
            if line != '':
                l1, l2, r1, r2 = [int(x) for x in re.split('[,-]', line)]
                elf1 = set(range(l1, l2+1))
                elf2 = set(range(r1, r2+1))

                if elf1.issubset(elf2) or elf2.issubset(elf1):
                    result += 1

    print(result)


# solution part 2
def part_2():
    with open("input.txt", "r") as f:
        result = 0

        for line in f.read().split("\n"):
            if line != '':
                l1, l2, r1, r2 = [int(x) for x in re.split('[,-]', line)]
                elf1 = set(range(l1, l2+1))
                elf2 = set(range(r1, r2+1))

                if elf2.intersection(elf1):
                    result += 1

    print(result)


# main entry point
if len(sys.argv) > 1 and sys.argv[1] == "-p1":
    part_1()
elif len(sys.argv) > 1 and sys.argv[1] == "-p2":
    part_2()
else:
    print("Usage: python", sys.argv[0], "[-p1|-p2]")
    sys.exit(1)
