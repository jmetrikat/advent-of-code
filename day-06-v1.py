#! /usr/bin/env python

input = []

# read message into list
with open("day-06-input.txt") as f:
    input = f.read()

# compare consecutive four characters and print starting position, if marker detected
for i in range(len(input)):
    if input[i] != input[i+1] and input[i] != input[i+2] and input[i] != input[i+3] and input[i+1] != input[i+2] and input[i+1] != input[i+3] and input[i+2] != input[i+3]:
        print("Starting position:", i+4)
        break
