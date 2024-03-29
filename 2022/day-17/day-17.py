#!/usr/bin/env python
# -*- coding: utf-8 -*-

""" --- Advent of Code 2023 - Day 17: Pyroclastic Flow --- """

import os
import sys

locations = set()


# get the initial coordinates of the five different rock types
def generate_rock(rock_type, y) -> tuple:
    match rock_type:
        case 0:
            return ((2, y), (3, y), (4, y), (5, y))                     # flat
        case 1:
            return ((2, y+1), (3, y), (3, y+1), (3, y+2), (4, y+1))     # cross
        case 2:
            return ((2, y), (3, y), (4, y), (4, y+1), (4, y+2))         # inverted L
        case 3:
            return ((2, y), (2, y+1), (2, y+2), (2, y+3))               # vertical
        case 4:
            return ((2, y), (2, y+1), (3, y), (3, y+1))                 # square

    raise ValueError("Invalid rock type '" + str(rock_type) + "'")


# check if rock can be moved into given direction
def moveable(rock: tuple, dir: str) -> bool:
    global locations

    if dir == "<":
        for x, y in rock:
            if (x - 1, y) in locations:
                return False
    elif dir == ">":
        for x, y in rock:
            if (x + 1, y) in locations:
                return False
    else:
        raise ValueError("Invalid direction '" + dir + "'")

    return True


# move rock according to jet direction
def move(rock: tuple, dir: str) -> tuple:
    # move left if rock is still in bounds
    if dir == "<" and rock[0][0] > 0:
        return tuple((x - 1, y) for x, y in rock)

    # move right if rock is still in bounds
    elif dir == ">" and rock[-1][0] < 6:
        return tuple((x + 1, y) for x, y in rock)

    # return original rock if no movement is possible
    elif dir == "<" or dir == ">":
        return rock

    raise ValueError("Invalid direction '" + dir + "'")


# check if rock can be dropped one step
def dropable(rock: tuple) -> bool:
    global locations

    # check if rock is at the bottom
    for x, y in rock:
        if (x, y - 1) in locations:
            return False

    return True


# drop rock one step
def drop(rock: tuple) -> tuple:
    return tuple((x, y - 1) for x, y in rock)


# drop rocks until max_iterations is reached
def drop_rocks(directions: str, max_iterations: int) -> int:
    rock_counter = 0
    max_y = 0

    # generate first rock
    rock = generate_rock(rock_counter % 5, max_y + 4)

    while True:
        for dir in directions:
            if moveable(rock, dir):
                rock = move(rock, dir)

            if dropable(rock):
                rock = drop(rock)
            else:
                # add location of settled rock to locations
                locations.update((x, y) for x, y in rock)

                # adjust max_y to give next rock enough space
                max_y = max(max_y, max(y for _, y in rock))

                # check if max_iterations is reached, otherwise generate next rock
                if (rock_counter + 1) == max_iterations:
                    return max_y
                else:
                    rock_counter += 1
                    rock = generate_rock(rock_counter % 5, max_y + 4)


# solution part 1
def part_1():
    with open("input.txt", "r") as f:
        directions = f.read().strip()

    # add floor to set
    locations.update((x, 0) for x in range(8))

    print(drop_rocks(directions, 2022))


# solution part 2
def part_2():
    with open("input.txt", "r") as f:
        directions = f.read().strip()

    # add floor to set
    locations.update((x, 0) for x in range(8))

    print(drop_rocks(directions, 1_000_000_000_000))


# main entry point
os.chdir(os.path.dirname(os.path.abspath(__file__)))

if len(sys.argv) > 1 and sys.argv[1] == "-p1":
    part_1()
elif len(sys.argv) > 1 and sys.argv[1] == "-p2":
    part_2()
else:
    print("Usage: python", sys.argv[0], "[-p1|-p2]")
    sys.exit(1)
