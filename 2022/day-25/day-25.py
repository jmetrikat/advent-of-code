#!/usr/bin/env python
# -*- coding: utf-8 -*-

""" --- Advent of Code 2023 - Day 25: Full of Hot Air --- """

import os
import sys

base = 5


# convert snafu to base10
def snafu_to_base10(snafu: str) -> int:
    base10_sum = 0

    for i, digit in enumerate(reversed(snafu)):
        match digit:
            case '-':
                base10_sum += base**i * -1
            case '=':
                base10_sum += base**i * -2
            case _:
                base10_sum += base**i * int(digit)

    return base10_sum


# convert base10 to base5
def base10_to_base5(base10: int) -> str:
    base5 = ""

    while base10 > 0:
        base5 += str(base10 % base)
        base10 //= base

    return base5


# adjust base5 to snafu
def base5_to_snafu(base5: str) -> str:
    snafu = ""
    carry = 0

    for digit in base5:
        if int(digit) + carry <= 2:
            snafu += str(int(digit) + carry)
            carry = 0
        else:
            match int(digit) + carry - base:
                case -1:
                    snafu += '-'
                case -2:
                    snafu += '='
                case _:
                    snafu += str(int(digit) + carry - base)

            carry = 1

    return snafu


# solution part 1
def part_1():
    base10_res = 0

    # read input file without newline and convert snafu to base10
    with open("input.txt", "r") as f:
        for line in [line.rstrip() for line in f.readlines()]:
            base10_res += snafu_to_base10(line)

    # convert base10 to base5 and then to snafu
    snafu_res = base5_to_snafu(base10_to_base5(base10_res))

    # print snafu backwards
    print(snafu_res[::-1])


# solution part 2
def part_2():
    print(":)")


# main entry point
os.chdir(os.path.dirname(os.path.abspath(__file__)))

if len(sys.argv) > 1 and sys.argv[1] == "-p1":
    part_1()
elif len(sys.argv) > 1 and sys.argv[1] == "-p2":
    part_2()
else:
    print("Usage: python", sys.argv[0], "[-p1|-p2]")
    sys.exit(1)
