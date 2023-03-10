#!/usr/bin/env python
# -*- coding: utf-8 -*-

""" --- Advent of Code 2022 - Day 7: No Space Left On Device --- """

# use dictionary to store directories and size
dirs = {"/root": 0}

# store current path
path = "/root"
total_size = 0

with open("input.txt") as f:
    for cmd in f.readlines():
        if cmd[0] == "$":

            # nothing to do
            if cmd[2:4] == "ls":
                pass

            elif cmd[2:4] == "cd":
                # change to root
                if cmd[5:6] == "/":
                    path = "/root"

                # change to parent directory
                elif cmd[5:7] == "..":
                    path = path[0:path.rfind("/")]

                # change to dir_name
                else:
                    dir_name = cmd[5:len(cmd)-1]
                    path = path + "/" + dir_name
                    dirs.update({path: 0})

        #  nothing to do
        elif cmd[0:3] == "dir":
            pass

        else:
            file_size = int(cmd[:cmd.rfind(" ")])
            dir = path

            for _ in range(path.count("/")):
                dirs[dir] += file_size
                dir = dir[:dir.rfind("/")]


# add size of all directories greater than 100000
for dir in dirs:
    if dirs[dir] < 100000:
        total_size += dirs[dir]

print(total_size)
