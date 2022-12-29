#!/usr/bin/env python
# -*- coding: utf-8 -*-

""" --- Advent of Code 2022 - Day 1: Calorie Counting --- """

blocks = []

with open('day-01-input.txt') as f:
    summe = 0
    for line in f.readlines():
        if line == "\n":
            blocks.append(summe)
            summe = 0
        else:
            summe = summe + int(line)

blocks.sort()
print(sum(blocks[-3:]))
