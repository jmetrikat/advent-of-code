#!/usr/bin/env python
# -*- coding: utf-8 -*-

""" --- Advent of Code 2022 - Day 3: Rucksack Reorganization --- """


# find the common item and calculate its priority
def compare(first_compartment: str, second_compartment: str):
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


priority = 0

# separate the compartments by splitting the line in half (floor division) and compare their items
with open("input.txt") as f:
    for line in f:
        first_compartment, second_compartment = line[:len(line)//2], line[len(line)//2:]
        compare(first_compartment, second_compartment)

print(priority)
