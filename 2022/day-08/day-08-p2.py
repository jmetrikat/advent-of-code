#! /usr/bin/env python

# viewing distance to the north?
def check_north(i, j):
    distance = 0
    for k in reversed(range(0, i)):
        distance += 1
        if input[k][j] >= input[i][j]:
            break

    return distance


# viewing distance to the south?
def check_south(i, j):
    distance = 0
    for k in range(i+1, len(input)-1):
        distance += 1
        if input[k][j] >= input[i][j]:
            break

    return distance


# viewing distance to the west?
def check_west(i, j):
    distance = 0
    for k in reversed(range(0, j)):
        distance += 1
        if input[i][k] >= input[i][j]:
            break

    return distance


# viewing distance to the east?
def check_east(i, j):
    distance = 0
    for k in range(j+1, len(input[i])):
        distance += 1
        if input[i][k] >= input[i][j]:
            break

    return distance


# main entry point
with open("day-08-input.txt") as f:
    input = f.read().split("\n")

max_score = 0

for i in range(len(input)-1):
    for j in range(len(input[i])):
        if i != 1 and j != 0 and i != 98 and j != 98:

            score = 1
            score *= check_north(i, j) * check_south(i, j) * check_west(i, j) * check_east(i, j)

            if score > max_score:
                max_score = score

print(max_score)