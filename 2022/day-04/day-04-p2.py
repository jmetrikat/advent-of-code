#!/usr/bin/env python
# -*- coding: utf-8 -*-

""" --- Advent of Code 2022 - Day 4: Camp Cleanup --- """

import re

result = 0
with open("day-04-input.txt", "r") as f:
    pairs = f.read().split("\n")

for line in pairs:
    if line != '':
        l1, l2, r1, r2 = [int(x) for x in re.split('[,-]', line)]
        elf1 = set(range(l1, l2+1))
        elf2 = set(range(r1, r2+1))

        if elf2.intersection(elf1):
            result += 1

print(result)
