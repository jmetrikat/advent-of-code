#!/usr/bin/env python
# -*- coding: utf-8 -*-

""" --- Advent of Code 2023 - Day 13: Distress Signal --- """

import os
import sys


# compare two integers
def compare(a: int, b: int) -> int:
    # numbers are in order
    if a < b:
        return 1

    # numbers are not in order
    elif a > b:
        return -1

    # numbers are equal
    else:
        return 0


# determine if two pairs are in order
def compare_pairs(a: list, b: list) -> int:
    # int and int
    if isinstance(a, int) and isinstance(b, int):
        return compare(a, b)

    # list[...] and list[...]
    elif isinstance(a, list) and isinstance(b, list):
        # check items in lists one by one
        for left, right in zip(a, b):
            res = compare_pairs(left, right)

            # items are not equal; result was found
            if res != 0:
                return res

        # items are equal, so have to check if b is longer
        return compare(len(a), len(b))

    # int and list[...]
    elif isinstance(a, int) and isinstance(b, list):
        return compare_pairs([a], b)

    # list[...] and int
    elif isinstance(a, list) and isinstance(b, int):
        return compare_pairs(a, [b])


# solution part 1
def part_1():
    sum_of_indices = 0

    # put pairs into list: [[a1, b1], [a2, b2], ...]
    with open("input.txt", "r") as f:
        lines = [line.strip() for line in f.readlines()]
        pairs = [[eval(p) for p in pair.split('\n')] for pair in '\n'.join(lines).split('\n\n')]

    # compare pairs and add index to sum if pair is in order
    for idx, pair in enumerate(pairs):
        if compare_pairs(pair[0], pair[1]) == 1:
            sum_of_indices += idx + 1

    print(sum_of_indices)


# solution part 2
def part_2():
    # index starts at 1 and div packet 1 is in front of div packet 2
    divider_packet_1_index = 1
    divider_packet_2_index = 2

    with open("input.txt", "r") as file:
        lines = [line.strip() for line in file.readlines()]
        pairs = [[eval(pair) for pair in pairs_string.split('\n')] for pairs_string in '\n'.join(lines).split('\n\n')]

    # find position of divider packets
    for pair in pairs:
        for packet in pair:
            if compare_pairs(packet, [[2]]) == 1:
                divider_packet_1_index += 1
            if compare_pairs(packet, [[6]]) == 1:
                divider_packet_2_index += 1

    decoder_key = divider_packet_1_index * divider_packet_2_index
    print(decoder_key)


# main entry point
os.chdir(os.path.dirname(os.path.abspath(__file__)))

if len(sys.argv) > 1 and sys.argv[1] == "-p1":
    part_1()
elif len(sys.argv) > 1 and sys.argv[1] == "-p2":
    part_2()
else:
    print("Usage: python", sys.argv[0], "[-p1|-p2]")
    sys.exit(1)
