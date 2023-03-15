#!/usr/bin/env python
# -*- coding: utf-8 -*-

""" --- Advent of Code 2022 - Day 10: Cathode-Ray Tube --- """

import sys

# store number of cycles, value in register x and final score
no_cycles = 0
x = 1
score = 0


# increment the cycle counter and update the score for given cycles
def tick() -> None:
    global no_cycles, x, score
    if no_cycles == 20 or no_cycles == 60 or no_cycles == 100 or no_cycles == 140 or no_cycles == 180 or no_cycles == 220:
        score += no_cycles * x
    no_cycles += 1
    return


# increment the cycle counter and print a pixel
def tick_and_print() -> None:
    global no_cycles, x
    printer_pos = no_cycles % 40

    # if the x value (+1/-1) is in range of the printer, a # is printed
    if printer_pos == x - 1 or printer_pos == x or printer_pos == x + 1:
        print('#', end="")
    else:
        print('.', end="")

    # start a new line every 40 cycles
    no_cycles += 1
    if no_cycles % 40 == 0:
        print("")

    return


# solution part 1
def part_1():
    global no_cycles, x, score

    with open("input.txt") as f:
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


# solution part 2
def part_2():
    global no_cycles, x

    with open("input.txt") as f:
        # noop takes 1 cycle, addx takes 2 cycles
        for line in f.readlines():
            if line == "noop\n":
                tick_and_print()
            elif line[0:4] == "addx":
                tick_and_print()
                tick_and_print()
                instruction, value = line.split()
                x += int(value)
            else:
                print("Unknown instruction:", line)
                exit(1)


# main entry point
if len(sys.argv) > 1 and sys.argv[1] == "-p1":
    part_1()
elif len(sys.argv) > 1 and sys.argv[1] == "-p2":
    part_2()
else:
    print("Usage: python", sys.argv[0], "[-p1|-p2]")
    sys.exit(1)
