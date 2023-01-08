#!/usr/bin/env python
# -*- coding: utf-8 -*-

""" --- Advent of Code 2022 - Day 6: Tuning Trouble --- """


# check if all 14 characters are different
def is_marker(i, MARKER_SIZE):
    for j in range(0, MARKER_SIZE - 1):
        for k in range(1, MARKER_SIZE):
            if input[i + j] == input[i + k] and (i + j) != (i + k):
                return 0

    return 1

# define marker size
MARKER_SIZE = 14
input = []

# compare consecutive 14 characters and print starting position, if marker detected
with open("day-06-input.txt") as f:
    input = f.read()

    for i in range((len(input) - MARKER_SIZE)):
        if is_marker(i, MARKER_SIZE):
            print(i + MARKER_SIZE)
            break
