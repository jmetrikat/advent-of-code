#!/usr/bin/env python
# -*- coding: utf-8 -*-

""" --- Advent of Code 2022 - Day 1: Calorie Counting --- """

maximum = 0
calorie_sum = 0

with open('day-01-input.txt') as f:
    for line in f.readlines():
        if line == "\n":
            if calorie_sum >= maximum:
                maximum = calorie_sum
            calorie_sum = 0
        else:
            calorie_sum += int(line)
print(maximum)
