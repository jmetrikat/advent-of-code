#!/usr/bin/env python
# -*- coding: utf-8 -*-

""" --- Advent of Code 2022 - Day 1: Calorie Counting --- """

summe = 0
blocks = []

with open('day-01-input.txt') as f:
    for line in f.readlines():
        if line == "\n":
            blocks.append(summe)
            summe = 0
        else:
            summe = summe + int(line)

blocks.sort()
print(sum(blocks[-3:]))
