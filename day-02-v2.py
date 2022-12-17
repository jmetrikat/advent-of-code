#!/usr/bin/env python

score = 0

f = open("day-02-input.txt", "r")

for line in f:
    if line == "A X\n":
        score = score + 3
    elif line == "A Y\n":
        score = score + 4
    elif line == "A Z\n":
        score = score + 8
    elif line == "B X\n":
        score = score + 1
    elif line == "B Y\n":
        score = score + 5
    elif line == "B Z\n":
        score = score + 9
    elif line == "C X\n":
        score = score + 2
    elif line == "C Y\n":
        score = score + 6
    elif line == "C Z\n":
        score = score + 7
        
print(score)