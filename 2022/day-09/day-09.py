#!/usr/bin/env python
# -*- coding: utf-8 -*-

""" --- Advent of Code 2022 - Day 9: Rope Bridge --- """

import numpy as np
import sys


# solution part 1
def part_1():
    with open("input.txt") as f:
        # represent the position of head and tail as a tuple
        head = (0, 0)
        tail = (0, 0)

        # use a set as data structure, so that duplicates are ignored
        tail_pos_visited = set()
        # mark the starting position as visited
        tail_pos_visited.add(tail)

        for line in f.readlines():
            direction, steps = line.split()

            # grid mapping of directions
            for _ in range(int(steps)):
                match direction:
                    case 'R':
                        head = (head[0] + 1, head[1])
                    case 'L':
                        head = (head[0] - 1, head[1])
                    case 'U':
                        head = (head[0], head[1] + 1)
                    case 'D':
                        head = (head[0], head[1] - 1)

                diff_x = head[0] - tail[0]
                diff_y = head[1] - tail[1]

                # check if tail is touching head ...
                if abs(diff_x) <= 1 and abs(diff_y) <= 1:
                    continue

                # ... otherwise adjust the tail
                else:
                    tail = (tail[0] + np.sign(diff_x), tail[1] + np.sign(diff_y))
                    tail_pos_visited.add(tail)

    print(len(tail_pos_visited))


# solution part 2
def part_2():
    with open("input.txt") as f:
        # define amount of knots and store their position in array
        no_knots = 10
        knots = []

        # all 10 knots starting at (0,0)
        for _ in range(no_knots):
            knots.append((0, 0))

        # use a set as data structure, so that duplicates are ignored
        tail_pos_visited = set()
        # mark the starting position as visited
        tail_pos_visited.add(knots[-1])

        for line in f.readlines():
            direction, steps = line.split()

            # grid mapping for the directions
            for _ in range(int(steps)):
                match direction:
                    case 'R':
                        knots[0] = (knots[0][0] + 1, knots[0][1])
                    case 'L':
                        knots[0] = (knots[0][0] - 1, knots[0][1])
                    case 'U':
                        knots[0] = (knots[0][0], knots[0][1] + 1)
                    case 'D':
                        knots[0] = (knots[0][0], knots[0][1] - 1)

                for k in range(no_knots-1):
                    diff_x = knots[k][0] - knots[k + 1][0]
                    diff_y = knots[k][1] - knots[k + 1][1]

                    # check if knot #k is touching knot #k+1 ...
                    if abs(diff_x) <= 1 and abs(diff_y) <= 1:
                        continue

                    # ... otherwise adjust knot #k+1 and add position of last knot (index: knots[-1]) to visited positions
                    else:
                        knots[k + 1] = (knots[k + 1][0] + np.sign(diff_x), knots[k + 1][1] + np.sign(diff_y))
                        tail_pos_visited.add(knots[-1])

    print(len(tail_pos_visited))


# main entry point
if len(sys.argv) > 1 and sys.argv[1] == "-p1":
    part_1()
elif len(sys.argv) > 1 and sys.argv[1] == "-p2":
    part_2()
else:
    print("Usage: python", sys.argv[0], "[-p1|-p2]")
    sys.exit(1)
