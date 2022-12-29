#!/usr/bin/env python
# -*- coding: utf-8 -*-

""" --- Advent of Code 2022 - Day 8: Treetop Tree House --- """

# tree visible to the north?
def check_north(i, j):
    for k in range(0, i):
        if input[k][j] >= input[i][j]:
            return 0

    return 1


# tree visible to the south?
def check_south(i, j):
    for k in range(i+1, len(input)-1):
        if input[k][j] >= input[i][j]:
            return 0

    return 1


# tree visible to the west?
def check_west(i, j):
    for k in range(0, j):
        if input[i][k] >= input[i][j]:
            return 0

    return 1


# tree visible to the east?
def check_east(i, j):
    for k in range(j+1, len(input[i])):
        if input[i][k] >= input[i][j]:
            return 0

    return 1


# main entry point
with open("day-08-input.txt") as f:
    input = f.read().split("\n")

visible_cnt = 0

for i in range(len(input)-1):
    for j in range(len(input[i])):

        if (check_north(i, j) or check_south(i, j) or  check_west(i, j) or check_east(i, j)):
            visible_cnt += 1

print(visible_cnt)
