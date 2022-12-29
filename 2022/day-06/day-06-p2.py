#!/usr/bin/env python
# -*- coding: utf-8 -*-

""" --- Advent of Code 2022 - Day 6: Tuning Trouble --- """

input = []

def all_different(i):
    for j in range(0, 13):
        for k in range(1, 14):
            if input[i+j] == input[i+k] and i+j != i+k:
                return 0
    return 1


# read message into list
with open("day-06-input.txt") as f:
    input = f.read()

for i in range((len(input)-14)):
    if all_different(i):
        print("Starting position:", i+14)
        break
