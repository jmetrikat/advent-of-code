#!/usr/bin/env python
# -*- coding: utf-8 -*-

""" --- Advent of Code 2022 - Day 1: Calorie Counting --- """

maximum = 0
summe = 0

with open('day-01-input.txt') as f:
    for line in f.readlines():
        if line == "\n":
            if summe >= maximum:
                maximum = summe
            summe = 0
        else:
            summe = summe + int(line)
print(maximum)
