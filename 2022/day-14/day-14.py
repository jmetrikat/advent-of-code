#!/usr/bin/env python
# -*- coding: utf-8 -*-

""" --- Advent of Code 2023 - Day 14: Regolith Reservoir --- """

import sys

highest_y_coordinate = 0
heigth = 1000
width = 1000


def get_map() -> list:
    global highest_y_coordinate
    cave_map = [['.' for _ in range(width)] for _ in range(heigth)]

    with open("input.txt") as f:
        rocks = [line.strip().split(' -> ') for line in f.readlines()]

    for rock in rocks:
        points = [tuple(map(int, point.split(','))) for point in rock]

        for i in range(len(points) - 1):
            prev_x, prev_y = points[i]
            x, y = points[i + 1]

            # draw vertical wall
            if x == prev_x:
                # draw wall to the right
                if y > prev_y:
                    for y in range(prev_y, y + 1):
                        cave_map[y][x] = '#'

                # draw wall to the left
                else:
                    for y in range(y, prev_y + 1):
                        cave_map[y][x] = '#'

            # draw horizontal wall
            else:
                # draw wall to the bottom
                if x > prev_x:
                    for x in range(prev_x, x + 1):
                        cave_map[y][x] = '#'

                # draw wall to the top
                else:
                    for x in range(x, prev_x + 1):
                        cave_map[y][x] = '#'

            # update highest y coordinate
            highest_y_coordinate = max(y, prev_y , highest_y_coordinate)

    return cave_map


def pour_sand(cave_map: list) -> int:
    global heigth
    sand = [500, 0]

    while True:
        # sand is falling into the abyss
        if sand[1] == heigth - 1 or cave_map[sand[1]][sand[0]] == 'o':
            return 0

        # sand can move one step down
        if cave_map[sand[1] + 1][sand[0]] == '.':
            sand[1] += 1

        # sand can move one step down and to the left
        elif cave_map[sand[1] + 1][sand[0] - 1] == '.':
            sand[0] -= 1
            sand[1] += 1

        # sand can move one step down and to the right
        elif cave_map[sand[1] + 1][sand[0] + 1] == '.':
            sand[0] += 1
            sand[1] += 1

        # sand can't move anymore
        else:
            cave_map[sand[1]][sand[0]] = 'o'
            return 1


# solution part 1
def part_1():
    cave_map = get_map()

    result = 0
    while pour_sand(cave_map):
        result += 1

    print(result)


# solution part 2
def part_2():
    cave_map = get_map()

    # add infinite horizontal wall at the bottom of the cave
    for i in range(width):
        cave_map[highest_y_coordinate + 2][i] = '#'

    result = 0
    while pour_sand(cave_map):
        result += 1

    print(result)


# main entry point
if len(sys.argv) > 1 and sys.argv[1] == "-p1":
    part_1()
elif len(sys.argv) > 1 and sys.argv[1] == "-p2":
    part_2()
else:
    print("Usage: python", sys.argv[0], "[-p1|-p2]")
    sys.exit(1)
