#!/usr/bin/env python

blocks = []

with open('day-01-input.txt') as f:
    summe = 0
    for line in f.readlines():
        if line == "\n": 
            blocks.append(summe)
            summe = 0
        else:
            summe = summe + int(line)

blocks.sort()
print(sum(blocks[-3:]))
