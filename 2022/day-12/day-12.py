#!/usr/bin/env python
# -*- coding: utf-8 -*-

""" --- Advent of Code 2022 - Day 12: Hill Climbing Algorithm --- """

import sys


def get_shortest_path(start: tuple, end: tuple, map: list) -> int:
    rows = len(map)
    cols = len(map[0])
    no_nodes = rows * cols

    # use dijkstra's algorithm
    distance = [0 for _ in range(no_nodes)]
    visited = [0 for _ in range(no_nodes)]
    cost = [[0 for _ in range(no_nodes)] for _ in range(no_nodes)]

    # initialize cost matrix
    for src in range(no_nodes):
        for dest in range(no_nodes):
            if src == dest:
                # cost to get from node to itself is 0
                cost[src][dest] = 0
            else:
                # cost to get to any other node is infinity
                cost[src][dest] = no_nodes

                src_x = src % cols
                src_y = src // cols
                dest_x = dest % cols
                dest_y = dest // cols

                # cost to get to adjacent and by elevation reachable nodes is 1
                if (abs(src_x - dest_x) == 1 and src_y == dest_y) or (abs(src_y - dest_y) == 1 and src_x == dest_x):
                    if map[src_y][src_x] - map[dest_y][dest_x] <= 1:
                        cost[src][dest] = 1

    # initialize distance and visited
    for node in range(no_nodes):
        distance[node] = cost[end[0] + end[1] * cols][node]
        visited[node] = 0

    visited[end[0] + end[1] * cols] = 1

    # find shortest path
    for _ in range(no_nodes):
        min_distance = no_nodes
        next_node_idx = 0

        # find node with minimum distance
        for node in range(no_nodes):
            if (visited[node] == 0) and distance[node] < min_distance:
                min_distance = distance[node]
                next_node_idx = node

        # mark node as visited
        visited[next_node_idx] = 1

        # update distance of all adjacent nodes
        for node in range(no_nodes):
            if (visited[node] == 0) and min_distance + cost[next_node_idx][node] < distance[node]:
                distance[node] = min_distance + cost[next_node_idx][node]

    # part 1: return distance from start to end
    if start[0] != -1:
        return distance[start[0] + start[1] * cols]

    # part 2: return distance of starting point with shortest path to end
    else:
        fewest_steps = no_nodes
        for start_x in range(rows):
            for start_y in range(cols):
                if map[start_x][start_y] == ord('a'):
                    fewest_steps = min(fewest_steps, distance[start_y + start_x * cols])

        return fewest_steps


# solution part 1
def part_1():
    with open("input.txt") as f:
        input = f.read().splitlines()

    map = [[0 for _ in range(len(input[0]))] for _ in range(len(input))]

    # get start and end points
    for row in range(len(input)):
        for col in range(len(input[0])):
            map[row][col] = ord(input[row][col])

            if input[row][col] == "S":
                start = (col, row)
                map[row][col] = ord('a')
            if input[row][col] == "E":
                end = (col, row)
                map[row][col] = ord('z')

    print(get_shortest_path(start, end, map))


# solution part 2
def part_2():
    with open("input.txt") as f:
        input = f.read().splitlines()

    map = [[0 for _ in range(len(input[0]))] for _ in range(len(input))]

    # get start and end points
    for row in range(len(input)):
        for col in range(len(input[0])):
            map[row][col] = ord(input[row][col])

            if input[row][col] == "S":
                start = (-1, -1)
                map[row][col] = ord('a')
            if input[row][col] == "E":
                end = (col, row)
                map[row][col] = ord('z')

    # find starting point with shortest path
    print(get_shortest_path(start, end, map))


# main entry point
if len(sys.argv) > 1 and sys.argv[1] == "-p1":
    part_1()
elif len(sys.argv) > 1 and sys.argv[1] == "-p2":
    part_2()
else:
    print("Usage: python", sys.argv[0], "[-p1|-p2]")
    sys.exit(1)
