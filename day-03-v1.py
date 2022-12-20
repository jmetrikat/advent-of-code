#! /usr/bin/env python

def compare():
    global priority
    for x in firstpart:
        for y in secondpart:
            if x == y:
                if x.isupper():
                    priority += ord(x)-38
                    return
                else:
                    priority += ord(x)-96
                    return


priority = 0
f = open("day-03-input.txt", "r")

for line in f:
    firstpart, secondpart = line[:len(line)//2], line[len(line)//2:]
    compare()

print(priority)




        
