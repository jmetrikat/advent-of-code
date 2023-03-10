#!/usr/bin/env python
# -*- coding: utf-8 -*-

""" --- Advent of Code 2022 - Day 2: Rock Paper Scissors --- """

score = 0

with open("input.txt") as f:
    for line in f:
        if line == "A X\n":
            score = score + 4
        elif line == "A Y\n":
            score = score + 8
        elif line == "A Z\n":
            score = score + 3
        elif line == "B X\n":
            score = score + 1
        elif line == "B Y\n":
            score = score + 5
        elif line == "B Z\n":
            score = score + 9
        elif line == "C X\n":
            score = score + 7
        elif line == "C Y\n":
            score = score + 2
        elif line == "C Z\n":
            score = score + 6

print(score)
