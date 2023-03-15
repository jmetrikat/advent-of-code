#!/usr/bin/env python
# -*- coding: utf-8 -*-

""" --- Advent of Code 2022 - Day 8: Treetop Tree House --- """

import sys


# check if tree is visible to north
def visible_to_north(i: int, j: int, input: list) -> int:
    for k in range(0, i):
        if input[k][j] >= input[i][j]:
            return 0

    return 1


# check if tree is visible to south
def visible_to_south(i: int, j: int, input: list) -> int:
    for k in range(i+1, len(input)-1):
        if input[k][j] >= input[i][j]:
            return 0

    return 1


# check if tree is visible to west
def visible_to_west(i: int, j: int, input: list) -> int:
    for k in range(0, j):
        if input[i][k] >= input[i][j]:
            return 0

    return 1


# check if tree is visible to east
def visible_to_east(i: int, j: int, input: list) -> int:
    for k in range(j+1, len(input[i])):
        if input[i][k] >= input[i][j]:
            return 0

    return 1


# viewing distance to the north?
def distance_to_north(i: int, j: int, input: list) -> int:
    distance = 0
    for k in reversed(range(0, i)):
        distance += 1
        if input[k][j] >= input[i][j]:
            break

    return distance


# viewing distance to the south?
def distance_to_south(i: int, j: int, input: list) -> int:
    distance = 0
    for k in range(i + 1, len(input) - 1):
        distance += 1
        if input[k][j] >= input[i][j]:
            break

    return distance


# viewing distance to the west?
def distance_to_west(i: int, j: int, input: list) -> int:
    distance = 0
    for k in reversed(range(0, j)):
        distance += 1
        if input[i][k] >= input[i][j]:
            break

    return distance


# viewing distance to the east?
def distance_to_east(i: int, j: int, input: list) -> int:
    distance = 0
    for k in range(j + 1, len(input[i])):
        distance += 1
        if input[i][k] >= input[i][j]:
            break

    return distance


# solution part 1
def part_1():
    with open("input.txt") as f:
        visible_cnt = 0
        input = f.read().split("\n")

        # check if tree is visible to any direction
        for i in range(len(input) - 1):
            for j in range(len(input[i])):

                # increase counter if tree is visible
                if visible_to_north(i, j, input) or visible_to_south(i, j, input) or visible_to_west(i, j, input) or visible_to_east(i, j, input):
                    visible_cnt += 1

    print(visible_cnt)


# solution part 2
def part_2():
    with open("input.txt") as f:
        max_score = 0
        input = f.read().split("\n")

        # calculate score for each tree
        for i in range(len(input) - 1):
            for j in range(len(input[i])):
                if i != 1 and j != 0 and i != 98 and j != 98:
                    score = distance_to_north(i, j, input) * distance_to_south(i, j, input) * distance_to_west(i, j, input) * distance_to_east(i, j, input)

                    # update max score
                    if score > max_score:
                        max_score = score

    print(max_score)


# main entry point
if len(sys.argv) > 1 and sys.argv[1] == "-p1":
    part_1()
elif len(sys.argv) > 1 and sys.argv[1] == "-p2":
    part_2()
else:
    print("Usage: python", sys.argv[0], "[-p1|-p2]")
    sys.exit(1)
