#!/usr/bin/env python
# -*- coding: utf-8 -*-

""" --- Advent of Code 2022 - Day 12: Hill Climbing Algorithm --- """


def get_steps(start, end):
    pass


# main entry point
with open("day-12-input.txt") as f:
    input = f.read().splitlines()

# get start and end points
for i in range(len(input)):
    for j in range(len(input[i])):
        if input[i][j] == "S":
            start = (i, j)
        if input[i][j] == "E":
            end = (i, j)

print(start, end)
