#!/usr/bin/env python
# -*- coding: utf-8 -*-

""" --- Advent of Code 2022 - Day 3: Rucksack Reorganization --- """

import sys

priority = 0
counter = 0
groupOfThree = []


# find the common item and calculate its priority
def compare_items(first_compartment: str, second_compartment: str):
    global priority

    for item_1 in first_compartment:
        for item_2 in second_compartment:

            # common item found
            if item_1 == item_2:
                if item_1.isupper():
                    priority += ord(item_1) - ord('A') + 27
                    return
                else:
                    priority += ord(item_1) - ord('a') + 1
                    return


# solution part 1
def part_1():
    # separate the compartments by splitting the line in half (floor division) and compare their items
    with open("input.txt") as f:
        for line in f:
            first_compartment, second_compartment = line[:len(line)//2], line[len(line)//2:]
            compare_items(first_compartment, second_compartment)

    print(priority)


# find the common item and calculate its priority
def find_common(lines: list):
    global priority

    for item_1 in lines[0]:
        for item_2 in lines[1]:
            for item_3 in lines[2]:

                # common item found
                if item_1 == item_2 and item_2 == item_3:
                    if item_1.isupper():
                        priority += ord(item_1) - ord('A') + 27
                        return
                    else:
                        priority += ord(item_1) - ord('a') + 1
                        return


# solution part 2
def part_2():
    global counter

    # separate the elfs into groups of three and find the common item
    with open("input.txt") as f:
        for line in f:
            counter += 1
            groupOfThree.append(line)

            if counter % 3 == 0:
                find_common(groupOfThree)
                groupOfThree.clear()

    print(priority)


# main entry point
if len(sys.argv) > 1 and sys.argv[1] == "-p1":
    part_1()
elif len(sys.argv) > 1 and sys.argv[1] == "-p2":
    part_2()
else:
    print("Usage: python", sys.argv[0], "[-p1|-p2]")
    sys.exit(1)
