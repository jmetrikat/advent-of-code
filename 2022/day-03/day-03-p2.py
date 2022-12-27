#!/usr/bin/env python
# -*- coding: utf-8 -*-

""" --- Advent of Code 2022 - Day 3: Rucksack Reorganization ---  """

def compare(lines: list):
    global priority
    for x in lines[0]:
        for y in lines[1]:
            for z in lines[2]:
                if x == y and y == z:
                    if x.isupper():
                        priority += ord(x)-38
                        return
                    else:
                        priority += ord(x)-96
                        return


priority = 0
counter = 0
f = open("day-03-input.txt", "r")
groupOfThree = []

for line in f:
    counter = counter + 1
    groupOfThree.append(line)
    if counter % 3 == 0:
        compare(groupOfThree)
        groupOfThree.clear()

print(priority)
