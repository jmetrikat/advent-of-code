#!/usr/bin/env python
# -*- coding: utf-8 -*-

""" --- Advent of Code 2022 - Day 6: Tuning Trouble --- """


# check if all 14 characters are different
def is_marker(i, marker_size, input):
    for j in range(0, marker_size - 1):
        for k in range(1, marker_size):
            if input[i + j] == input[i + k] and (i + j) != (i + k):
                return 0

    return 1


# define marker size
marker_size = 14

# compare consecutive 14 characters and print starting position, if marker detected
with open("input.txt") as f:
    input = f.read()

    for i in range((len(input) - marker_size)):
        if is_marker(i, marker_size, input):
            print(i + marker_size)
            break
