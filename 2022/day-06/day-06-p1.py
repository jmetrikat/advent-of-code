#!/usr/bin/env python
# -*- coding: utf-8 -*-

""" --- Advent of Code 2022 - Day 6: Tuning Trouble --- """

# define marker size
MARKER_SIZE = 4

# compare consecutive four characters and print starting position, if marker detected
with open("input.txt") as f:
    input = f.read()

    for i in range(len(input)):
        if input[i] != input[i + 1] and input[i] != input[i + 2] and input[i] != input[i + 3] and input[i + 1] != input[i + 2] and input[i + 1] != input[i + 3] and input[i + 2] != input[i + 3]:
            print(i + MARKER_SIZE)
            break
