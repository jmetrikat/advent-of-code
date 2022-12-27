#!/usr/bin/env python

maximum = 0 

with open('day-01-input.txt') as f:
    summe = 0
    for line in f.readlines():
        if line == "\n": 
            if summe >= maximum:
                maximum = summe
            summe = 0
        else:
            summe = summe + int(line)
print(maximum)