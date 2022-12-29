#!/usr/bin/env python
# -*- coding: utf-8 -*-

""" --- Advent of Code 2022 - Day 6: Tuning Trouble --- """

input = []

# read message into list
with open("day-06-input.txt") as f:
    input = f.read()

# compare consecutive four characters and print starting position, if marker detected
for i in range(len(input)):
    if input[i] != input[i+1] and input[i] != input[i+2] and input[i] != input[i+3] and input[i+1] != input[i+2] and input[i+1] != input[i+3] and input[i+2] != input[i+3]:
        print("Starting position:", i+4)
        break
