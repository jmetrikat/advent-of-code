#!/usr/bin/env python
# -*- coding: utf-8 -*-

""" --- Advent of Code 2022 - Day 9: Rope Bridge --- """

import numpy as np

with open("day-09-input.txt") as f:
    input = f.readlines()

# define amount of knots and store their position in array
NO_KNOTS = 10
knots = []

# all 10 knots starting at (0,0)
for _ in range (NO_KNOTS):
    knots.append((0, 0))

# use a set() as data structure, so that duplicates are ignored
tail_pos_visited = set()
# starting position of last knot has also been visited
tail_pos_visited.add(knots[-1])

for line in input:
    dir, steps = line.split()

    # grid mapping for the directions
    for _ in range(int(steps)):
        match dir:
            case 'R':
                knots[0] = (knots[0][0] + 1, knots[0][1])
            case 'L':
                knots[0] = (knots[0][0] - 1, knots[0][1])
            case 'U':
                knots[0] = (knots[0][0], knots[0][1] + 1)
            case 'D':
                knots[0] = (knots[0][0], knots[0][1] - 1)

        for k in range (NO_KNOTS-1):
            diff_x = knots[k][0] - knots[k+1][0]
            diff_y = knots[k][1] - knots[k+1][1]

            # check if knot #k is touching knot #k+1 ...
            if abs(diff_x) <= 1 and abs(diff_y) <= 1:
                continue

             # ... otherwise adjust the knot #k+1 and add position of last knot (index: knots[-1]) to visited positions
            else:
                knots[k+1] = (knots[k+1][0] + np.sign(diff_x), knots[k+1][1] + np.sign(diff_y))
                tail_pos_visited.add(knots[-1])

print(len(tail_pos_visited))
