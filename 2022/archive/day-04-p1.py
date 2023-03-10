#!/usr/bin/env python
# -*- coding: utf-8 -*-

""" --- Advent of Code 2022 - Day 4: Camp Cleanup --- """

import re

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
