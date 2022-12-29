#!/usr/bin/env python
# -*- coding: utf-8 -*-

""" --- Advent of Code 2022 - Day 3: Rucksack Reorganization --- """

# find the common item and calculate its priority
def compare(lines: list):
    global priority

    for item_1 in lines[0]:
        for item_2 in lines[1]:
            for item_3 in lines[2]:

                # common item found
                if item_1 == item_2 and item_2 == item_3:
                    if item_1.isupper():
                        priority += ord(item_1)-38
                        return
                    else:
                        priority += ord(item_1)-96
                        return


priority = 0
counter = 0
groupOfThree = []

f = open("day-03-input.txt", "r")

# seperate the elfs into groups of three and find the common item
for line in f:
    counter = counter + 1
    groupOfThree.append(line)

    if counter % 3 == 0:
        compare(groupOfThree)
        groupOfThree.clear()

print(priority)
