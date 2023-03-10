#!/usr/bin/env python
# -*- coding: utf-8 -*-

""" --- Advent of Code 2022 - Day 10: Cathode-Ray Tube --- """


# increment the cycle counter and print a pixel
def tick():
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


with open("input.txt") as f:
    # store number of cycles, value in register x and final score
    no_cycles = 0
    x = 1

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
