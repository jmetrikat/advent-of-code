#!/usr/bin/env python
# -*- coding: utf-8 -*-

""" --- Advent of Code 2022 - Day 10: Cathode-Ray Tube --- """


# increment the cycle counter and update the score for given cycles
def tick():
    global no_cycles, x, score
    if no_cycles == 20 or no_cycles == 60 or no_cycles == 100 or no_cycles == 140 or no_cycles == 180 or no_cycles == 220:
        score += no_cycles * x
    no_cycles += 1
    return


with open("input.txt") as f:
    # store number of cycles, value in register x and final score
    no_cycles = 1
    x = 1
    score = 0

    # noop takes 1 cycle, addx takes 2 cycles
    for line in f.readlines():
        if line == "noop\n":
            tick()
        elif line[0:4] == "addx":
            tick()
            tick()
            instruction, value = line.split()
            x += int(value)
        else:
            print("Unknown instruction:", line)
            exit(1)

print(score)
