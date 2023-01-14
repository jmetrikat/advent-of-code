#!/usr/bin/env python
# -*- coding: utf-8 -*-

""" --- Advent of Code 2022 - Day 1: Calorie Counting --- """

calorie_sum = 0
blocks = []

with open('day-01-input.txt') as f:
    for line in f.readlines():
        if line == "\n":
            blocks.append(calorie_sum)
            calorie_sum = 0
        else:
            calorie_sum += int(line)

blocks.sort()
print(sum(blocks[-3:]))
