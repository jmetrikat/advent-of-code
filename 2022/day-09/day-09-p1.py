#!/usr/bin/env python
# -*- coding: utf-8 -*-

""" --- Advent of Code 2022 - Day 9: Rope Bridge --- """

import numpy as np

with open("day-09-input.txt") as f:
    # represent the position of head and tail as a tuple
    head = (0, 0)
    tail = (0, 0)

    # use a set as data structure, so that duplicates are ignored
    tail_pos_visited = set()
    # mark the starting position as visited
    tail_pos_visited.add(tail)

    for line in f.readlines():
        dir, steps = line.split()

        # grid mapping for the directions
        for _ in range(int(steps)):
            match dir:
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
