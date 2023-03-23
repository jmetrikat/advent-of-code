#!/usr/bin/env python
# -*- coding: utf-8 -*-

""" --- Advent of Code 2022 - Day 7: No Space Left On Device --- """

import os
import sys


def check_directories() -> dict:
    # use dictionary to store directories and size
    dirs = {"/root": 0}

    # store current path
    path = "/root"

    with open("input.txt") as f:
        for cmd in f.readlines():
            if cmd[0] == "$":

                # ls: nothing to do
                if cmd[2:4] == "ls":
                    pass

                elif cmd[2:4] == "cd":
                    # cd /: change to root directory
                    if cmd[5:6] == "/":
                        path = "/root"

                    # cd ..:change to parent directory
                    elif cmd[5:7] == "..":
                        path = path[0:path.rfind("/")]

                    # cd <dir_name>: change to child directory
                    else:
                        dir_name = cmd[5:len(cmd) - 1]
                        path += "/" + dir_name
                        dirs.update({path: 0})

            # dir <dir_name>: nothing to do
            elif cmd[0:3] == "dir":
                pass

            # <filesize>: update sizes of directories
            else:
                file_size = int(cmd[:cmd.rfind(" ")])
                dir = path

                for _ in range(path.count("/")):
                    dirs[dir] += file_size
                    dir = dir[:dir.rfind("/")]

    return dirs


# solution part 1
def part_1():
    total_size = 0
    dirs = check_directories()

    # add the size of all directories smaller than 100000
    for dir in dirs:
        if dirs[dir] < 100000:
            total_size += dirs[dir]

    print(total_size)


# solution part 2
def part_2():
    dirs = check_directories()

    # total disk space available to the filesystem is 70000000
    free_space = 70000000 - dirs["/root"]

    # to run the update,  unused space of at least 30000000 is needed
    needed_space = 30000000 - free_space
    candidate_dirs = []

    # collect all possible directories that are big enough
    for dir in dirs:
        if dirs[dir] >= needed_space:
            candidate_dirs.append(dirs[dir])

    # choose to delete the smallest directory that's big enough
    print(min(candidate_dirs))


# main entry point
os.chdir(os.path.dirname(os.path.abspath(__file__)))

if len(sys.argv) > 1 and sys.argv[1] == "-p1":
    part_1()
elif len(sys.argv) > 1 and sys.argv[1] == "-p2":
    part_2()
else:
    print("Usage: python", sys.argv[0], "[-p1|-p2]")
    sys.exit(1)
