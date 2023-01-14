#!/usr/bin/env python
# -*- coding: utf-8 -*-

""" --- Advent of Code 2022 - Day 8: Treetop Tree House --- """


# check if tree is visible to north
def check_north(i, j):
    for k in range(0, i):
        if input[k][j] >= input[i][j]:
            return 0

    return 1


# check if tree is visible to south
def check_south(i, j):
    for k in range(i+1, len(input)-1):
        if input[k][j] >= input[i][j]:
            return 0

    return 1


# check if tree is visible to west
def check_west(i, j):
    for k in range(0, j):
        if input[i][k] >= input[i][j]:
            return 0

    return 1


# check if tree is visible to east
def check_east(i, j):
    for k in range(j+1, len(input[i])):
        if input[i][k] >= input[i][j]:
            return 0

    return 1


# main entry point
with open("day-08-input.txt") as f:
    visible_cnt = 0
    input = f.read().split("\n")

    # check if tree is visible to any direction
    for i in range(len(input) - 1):
        for j in range(len(input[i])):

            # increase counter, if tree is visible
            if check_north(i, j) or check_south(i, j) or  check_west(i, j) or check_east(i, j):
                visible_cnt += 1

print(visible_cnt)
