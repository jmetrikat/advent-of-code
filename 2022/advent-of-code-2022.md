# Advent of Code 2022
- [Day 1: Calorie Counting](#day-1-calorie-counting)
- [Day 2: Rock Paper Scissors](#day-2-rock-paper-scissors)
- [Day 3: Rucksack Reorganization](#day-3-rucksack-reorganization)
- [Day 4: Camp Cleanup](#day-4-camp-cleanup)
- [Day 5: Supply Stacks](#day-5-supply-stacks)
- [Day 6: Tuning Trouble](#day-6-tuning-trouble)
- [Day 7: No Space Left On Device](#day-7-no-space-left-on-device)
- [Day 8: Treetop Tree House](#day-8-treetop-tree-house)
- [Day 9: Rope Bridge](#day-9-rope-bridge)
- [Day 10: Cathode-Ray Tube](#day-10-cathode-ray-tube)
- [Day 11: Monkey in the Middle](#day-11-monkey-in-the-middle)
- [Day 12: Hill Climbing Algorithm](#day-12-hill-climbing-algorithm)
- [Day 13: Distress Signal](#day-13-distress-signal)
- [Day 14: Regolith Reservoir](#day-14-regolith-reservoir)
- [Day 15: Beacon Exclusion Zone](#day-15-beacon-exclusion-zone)
- [Day 16: Proboscidea Volcanium](#day-16-proboscidea-volcanium)
- [Day 17: Pyroclastic Flow](#day-17-pyroclastic-flow)
- [Day 18: Boiling Boulders](#day-18-boiling-boulders)
- [Day 19: Not Enough Minerals](#day-19-not-enough-minerals)
- [Day 20: Grove Positioning System](#day-20-grove-positioning-system)
- [Day 21: Monkey Math](#day-21-monkey-math)
- [Day 22: Monkey Map](#day-22-monkey-map)
- [Day 23: Unstable Diffusion](#day-23-unstable-diffusion)
- [Day 24: Blizzard Basin](#day-24-blizzard-basin)
- [Day 25: Full of Hot Air](#day-25-full-of-hot-air)

# Day 1: Calorie Counting

[https://adventofcode.com/2022/day/1](https://adventofcode.com/2022/day/1)

## Description

### Part One

Santa's reindeer typically eat regular reindeer food, but they need a lot of [magical energy](https://adventofcode.com/2018/day/25) to deliver presents on Christmas. For that, their favorite snack is a special type of _star_ fruit that only grows deep in the jungle. The Elves have brought you on their annual expedition to the grove where the fruit grows.

To supply enough magical energy, the expedition needs to retrieve a minimum of _fifty stars_ by December 25th. Although the Elves assure you that the grove has plenty of fruit, you decide to grab any fruit you see along the way, just in case.

Collect stars by solving puzzles. Two puzzles will be made available on each day in the Advent calendar; the second puzzle is unlocked when you complete the first. Each puzzle grants _one star_. Good luck!

The jungle must be too overgrown and difficult to navigate in vehicles or access from the air; the Elves' expedition traditionally goes on foot. As your boats approach land, the Elves begin taking inventory of their supplies. One important consideration is food - in particular, the number of _Calories_ each Elf is carrying (your puzzle input).

The Elves take turns writing down the number of Calories contained by the various meals, snacks, rations, <span title="By &quot;etc&quot;, you're pretty sure they just mean &quot;more snacks&quot;.">etc.</span> that they've brought with them, one item per line. Each Elf separates their own inventory from the previous Elf's inventory (if any) by a blank line.

For example, suppose the Elves finish writing their items' Calories and end up with the following list:

    1000
    2000
    3000

    4000

    5000
    6000

    7000
    8000
    9000

    10000


This list represents the Calories of the food carried by five Elves:

*   The first Elf is carrying food with `1000`, `2000`, and `3000` Calories, a total of _`6000`_ Calories.
*   The second Elf is carrying one food item with _`4000`_ Calories.
*   The third Elf is carrying food with `5000` and `6000` Calories, a total of _`11000`_ Calories.
*   The fourth Elf is carrying food with `7000`, `8000`, and `9000` Calories, a total of _`24000`_ Calories.
*   The fifth Elf is carrying one food item with _`10000`_ Calories.

In case the Elves get hungry and need extra snacks, they need to know which Elf to ask: they'd like to know how many Calories are being carried by the Elf carrying the _most_ Calories. In the example above, this is _`24000`_ (carried by the fourth Elf).

Find the Elf carrying the most Calories. _How many total Calories is that Elf carrying?_

### Part Two

By the time you calculate the answer to the Elves' question, they've already realized that the Elf carrying the most Calories of food might eventually _run out of snacks_.

To avoid this unacceptable situation, the Elves would instead like to know the total Calories carried by the _top three_ Elves carrying the most Calories. That way, even if one of those Elves runs out of snacks, they still have two backups.

In the example above, the top three Elves are the fourth Elf (with `24000` Calories), then the third Elf (with `11000` Calories), then the fifth Elf (with `10000` Calories). The sum of the Calories carried by these three elves is _`45000`_.

Find the top three Elves carrying the most Calories. _How many Calories are those Elves carrying in total?_

# Day 2: Rock Paper Scissors

[https://adventofcode.com/2022/day/2](https://adventofcode.com/2022/day/2)

## Description

### Part One

The Elves begin to set up camp on the beach. To decide whose tent gets to be closest to the snack storage, a giant [Rock Paper Scissors](https://en.wikipedia.org/wiki/Rock_paper_scissors) tournament is already in progress.

Rock Paper Scissors is a game between two players. Each game contains many rounds; in each round, the players each simultaneously choose one of Rock, Paper, or Scissors using a hand shape. Then, a winner for that round is selected: Rock defeats Scissors, Scissors defeats Paper, and Paper defeats Rock. If both players choose the same shape, the round instead ends in a draw.

Appreciative of your help yesterday, one Elf gives you an _encrypted strategy guide_ (your puzzle input) that they say will be sure to help you win. "The first column is what your opponent is going to play: `A` for Rock, `B` for Paper, and `C` for Scissors. The second column--" Suddenly, the Elf is called away to help with someone's tent.

The second column, <span title="Why do you keep guessing?!">you reason</span>, must be what you should play in response: `X` for Rock, `Y` for Paper, and `Z` for Scissors. Winning every time would be suspicious, so the responses must have been carefully chosen.

The winner of the whole tournament is the player with the highest score. Your _total score_ is the sum of your scores for each round. The score for a single round is the score for the _shape you selected_ (1 for Rock, 2 for Paper, and 3 for Scissors) plus the score for the _outcome of the round_ (0 if you lost, 3 if the round was a draw, and 6 if you won).

Since you can't be sure if the Elf is trying to help you or trick you, you should calculate the score you would get if you were to follow the strategy guide.

For example, suppose you were given the following strategy guide:

    A Y
    B X
    C Z


This strategy guide predicts and recommends the following:

*   In the first round, your opponent will choose Rock (`A`), and you should choose Paper (`Y`). This ends in a win for you with a score of _8_ (2 because you chose Paper + 6 because you won).
*   In the second round, your opponent will choose Paper (`B`), and you should choose Rock (`X`). This ends in a loss for you with a score of _1_ (1 + 0).
*   The third round is a draw with both players choosing Scissors, giving you a score of 3 + 3 = _6_.

In this example, if you were to follow the strategy guide, you would get a total score of _`15`_ (8 + 1 + 6).

_What would your total score be if everything goes exactly according to your strategy guide?_

### Part Two

The Elf finishes helping with the tent and sneaks back over to you. "Anyway, the second column says how the round needs to end: `X` means you need to lose, `Y` means you need to end the round in a draw, and `Z` means you need to win. Good luck!"

The total score is still calculated in the same way, but now you need to figure out what shape to choose so the round ends as indicated. The example above now goes like this:

*   In the first round, your opponent will choose Rock (`A`), and you need the round to end in a draw (`Y`), so you also choose Rock. This gives you a score of 1 + 3 = _4_.
*   In the second round, your opponent will choose Paper (`B`), and you choose Rock so you lose (`X`) with a score of 1 + 0 = _1_.
*   In the third round, you will defeat your opponent's Scissors with Rock for a score of 1 + 6 = _7_.

Now that you're correctly decrypting the ultra top secret strategy guide, you would get a total score of _`12`_.

Following the Elf's instructions for the second column, _what would your total score be if everything goes exactly according to your strategy guide?_

# Day 3: Rucksack Reorganization

[https://adventofcode.com/2022/day/3](https://adventofcode.com/2022/day/3)

## Description

### Part One

One Elf has the important job of loading all of the [rucksacks](https://en.wikipedia.org/wiki/Rucksack) with supplies for the <span title="Where there's jungle, there's hijinxs.">jungle</span> journey. Unfortunately, that Elf didn't quite follow the packing instructions, and so a few items now need to be rearranged.

Each rucksack has two large _compartments_. All items of a given type are meant to go into exactly one of the two compartments. The Elf that did the packing failed to follow this rule for exactly one item type per rucksack.

The Elves have made a list of all of the items currently in each rucksack (your puzzle input), but they need your help finding the errors. Every item type is identified by a single lowercase or uppercase letter (that is, `a` and `A` refer to different types of items).

The list of items for each rucksack is given as characters all on a single line. A given rucksack always has the same number of items in each of its two compartments, so the first half of the characters represent items in the first compartment, while the second half of the characters represent items in the second compartment.

For example, suppose you have the following list of contents from six rucksacks:

    vJrwpWtwJgWrhcsFMMfFFhFp
    jqHRNqRjqzjGDLGLrsFMfFZSrLrFZsSL
    PmmdzqPrVvPwwTWBwg
    wMqvLMZHhHMvwLHjbvcjnnSBnvTQFn
    ttgJtRGJQctTZtZT
    CrZsJsPPZsGzwwsLwLmpwMDw


*   The first rucksack contains the items `vJrwpWtwJgWrhcsFMMfFFhFp`, which means its first compartment contains the items `vJrwpWtwJgWr`, while the second compartment contains the items `hcsFMMfFFhFp`. The only item type that appears in both compartments is lowercase _`p`_.
*   The second rucksack's compartments contain `jqHRNqRjqzjGDLGL` and `rsFMfFZSrLrFZsSL`. The only item type that appears in both compartments is uppercase _`L`_.
*   The third rucksack's compartments contain `PmmdzqPrV` and `vPwwTWBwg`; the only common item type is uppercase _`P`_.
*   The fourth rucksack's compartments only share item type _`v`_.
*   The fifth rucksack's compartments only share item type _`t`_.
*   The sixth rucksack's compartments only share item type _`s`_.

To help prioritize item rearrangement, every item type can be converted to a _priority_:

*   Lowercase item types `a` through `z` have priorities 1 through 26.
*   Uppercase item types `A` through `Z` have priorities 27 through 52.

In the above example, the priority of the item type that appears in both compartments of each rucksack is 16 (`p`), 38 (`L`), 42 (`P`), 22 (`v`), 20 (`t`), and 19 (`s`); the sum of these is _`157`_.

Find the item type that appears in both compartments of each rucksack. _What is the sum of the priorities of those item types?_

### Part Two

As you finish identifying the misplaced items, the Elves come to you with another issue.

For safety, the Elves are divided into groups of three. Every Elf carries a badge that identifies their group. For efficiency, within each group of three Elves, the badge is the _only item type carried by all three Elves_. That is, if a group's badge is item type `B`, then all three Elves will have item type `B` somewhere in their rucksack, and at most two of the Elves will be carrying any other item type.

The problem is that someone forgot to put this year's updated authenticity sticker on the badges. All of the badges need to be pulled out of the rucksacks so the new authenticity stickers can be attached.

Additionally, nobody wrote down which item type corresponds to each group's badges. The only way to tell which item type is the right one is by finding the one item type that is _common between all three Elves_ in each group.

Every set of three lines in your list corresponds to a single group, but each group can have a different badge item type. So, in the above example, the first group's rucksacks are the first three lines:

    vJrwpWtwJgWrhcsFMMfFFhFp
    jqHRNqRjqzjGDLGLrsFMfFZSrLrFZsSL
    PmmdzqPrVvPwwTWBwg


And the second group's rucksacks are the next three lines:

    wMqvLMZHhHMvwLHjbvcjnnSBnvTQFn
    ttgJtRGJQctTZtZT
    CrZsJsPPZsGzwwsLwLmpwMDw


In the first group, the only item type that appears in all three rucksacks is lowercase `r`; this must be their badges. In the second group, their badge item type must be `Z`.

Priorities for these items must still be found to organize the sticker attachment efforts: here, they are 18 (`r`) for the first group and 52 (`Z`) for the second group. The sum of these is _`70`_.

Find the item type that corresponds to the badges of each three-Elf group. _What is the sum of the priorities of those item types?_

# Day 4: Camp Cleanup

[https://adventofcode.com/2022/day/4](https://adventofcode.com/2022/day/4)

## Description

### Part One

Space needs to be cleared before the last supplies can be unloaded from the ships, and so several Elves have been assigned the job of cleaning up sections of the camp. Every section has a unique _ID number_, and each Elf is assigned a range of section IDs.

However, as some of the Elves compare their section assignments with each other, they've noticed that many of the assignments _overlap_. To try to quickly find overlaps and reduce duplicated effort, the Elves pair up and make a _big list of the section assignments for each pair_ (your puzzle input).

For example, consider the following list of section assignment pairs:

    2-4,6-8
    2-3,4-5
    5-7,7-9
    2-8,3-7
    6-6,4-6
    2-6,4-8


For the first few pairs, this list means:

*   Within the first pair of Elves, the first Elf was assigned sections `2-4` (sections `2`, `3`, and `4`), while the second Elf was assigned sections `6-8` (sections `6`, `7`, `8`).
*   The Elves in the second pair were each assigned two sections.
*   The Elves in the third pair were each assigned three sections: one got sections `5`, `6`, and `7`, while the other also got `7`, plus `8` and `9`.

This example list uses single-digit section IDs to make it easier to draw; your actual list might contain larger numbers. Visually, these pairs of section assignments look like this:

    .234.....  2-4
    .....678.  6-8

    .23......  2-3
    ...45....  4-5

    ....567..  5-7
    ......789  7-9

    .2345678.  2-8
    ..34567..  3-7

    .....6...  6-6
    ...456...  4-6

    .23456...  2-6
    ...45678.  4-8


Some of the pairs have noticed that one of their assignments _fully contains_ the other. For example, `2-8` fully contains `3-7`, and `6-6` is fully contained by `4-6`. In pairs where one assignment fully contains the other, one Elf in the pair would be exclusively cleaning sections their partner will already be cleaning, so these seem like the most in need of reconsideration. In this example, there are _`2`_ such pairs.

_In how many assignment pairs does one range fully contain the other?_

### Part Two

It seems like there is still quite a bit of duplicate work planned. Instead, the Elves would <span title="If you like this, you'll *love* axis-aligned bounding box intersection testing.">like</span> to know the number of pairs that _overlap at all_.

In the above example, the first two pairs (`2-4,6-8` and `2-3,4-5`) don't overlap, while the remaining four pairs (`5-7,7-9`, `2-8,3-7`, `6-6,4-6`, and `2-6,4-8`) do overlap:

*   `5-7,7-9` overlaps in a single section, `7`.
*   `2-8,3-7` overlaps all of the sections `3` through `7`.
*   `6-6,4-6` overlaps in a single section, `6`.
*   `2-6,4-8` overlaps in sections `4`, `5`, and `6`.

So, in this example, the number of overlapping assignment pairs is _`4`_.

_In how many assignment pairs do the ranges overlap?_

# Day 5: Supply Stacks

[https://adventofcode.com/2022/day/5](https://adventofcode.com/2022/day/5)

## Description

### Part One

The expedition can depart as soon as the final supplies have been unloaded from the ships. Supplies are stored in stacks of marked _crates_, but because the needed supplies are buried under many other crates, the crates need to be rearranged.

The ship has a _giant cargo crane_ capable of moving crates between stacks. To ensure none of the crates get crushed or fall over, the crane operator will rearrange them in a series of carefully-planned steps. After the crates are rearranged, the desired crates will be at the top of each stack.

The Elves don't want to interrupt the crane operator during this delicate procedure, but they forgot to ask her _which_ crate will end up where, and they want to be ready to unload them as soon as possible so they can embark.

They do, however, have a drawing of the starting stacks of crates _and_ the rearrangement procedure (your puzzle input). For example:

        [D]
    [N] [C]
    [Z] [M] [P]
     1   2   3

    move 1 from 2 to 1
    move 3 from 1 to 3
    move 2 from 2 to 1
    move 1 from 1 to 2


In this example, there are three stacks of crates. Stack 1 contains two crates: crate `Z` is on the bottom, and crate `N` is on top. Stack 2 contains three crates; from bottom to top, they are crates `M`, `C`, and `D`. Finally, stack 3 contains a single crate, `P`.

Then, the rearrangement procedure is given. In each step of the procedure, a quantity of crates is moved from one stack to a different stack. In the first step of the above rearrangement procedure, one crate is moved from stack 2 to stack 1, resulting in this configuration:

    [D]
    [N] [C]
    [Z] [M] [P]
     1   2   3


In the second step, three crates are moved from stack 1 to stack 3. Crates are moved _one at a time_, so the first crate to be moved (`D`) ends up below the second and third crates:

            [Z]
            [N]
        [C] [D]
        [M] [P]
     1   2   3


Then, both crates are moved from stack 2 to stack 1. Again, because crates are moved _one at a time_, crate `C` ends up below crate `M`:

            [Z]
            [N]
    [M]     [D]
    [C]     [P]
     1   2   3


Finally, one crate is moved from stack 1 to stack 2:

            [Z]
            [N]
            [D]
    [C] [M] [P]
     1   2   3


The Elves just need to know _which crate will end up on top of each stack_; in this example, the top crates are `C` in stack 1, `M` in stack 2, and `Z` in stack 3, so you should combine these together and give the Elves the message _`CMZ`_.

_After the rearrangement procedure completes, what crate ends up on top of each stack?_

### Part Two

As you watch the crane operator expertly rearrange the crates, you notice the process isn't following your prediction.

Some mud was covering the writing on the side of the crane, and you quickly wipe it away. The crane isn't a CrateMover 9000 - it's a _<span title="It's way better than the old CrateMover 1006.">CrateMover 9001</span>_.

The CrateMover 9001 is notable for many new and exciting features: air conditioning, leather seats, an extra cup holder, and _the ability to pick up and move multiple crates at once_.

Again considering the example above, the crates begin in the same configuration:

        [D]
    [N] [C]
    [Z] [M] [P]
     1   2   3


Moving a single crate from stack 2 to stack 1 behaves the same as before:

    [D]
    [N] [C]
    [Z] [M] [P]
     1   2   3


However, the action of moving three crates from stack 1 to stack 3 means that those three moved crates _stay in the same order_, resulting in this new configuration:

            [D]
            [N]
        [C] [Z]
        [M] [P]
     1   2   3


Next, as both crates are moved from stack 2 to stack 1, they _retain their order_ as well:

            [D]
            [N]
    [C]     [Z]
    [M]     [P]
     1   2   3


Finally, a single crate is still moved from stack 1 to stack 2, but now it's crate `C` that gets moved:

            [D]
            [N]
            [Z]
    [M] [C] [P]
     1   2   3


In this example, the CrateMover 9001 has put the crates in a totally different order: _`MCD`_.

Before the rearrangement process finishes, update your simulation so that the Elves know where they should stand to be ready to unload the final supplies. _After the rearrangement procedure completes, what crate ends up on top of each stack?_

# Day 6: Tuning Trouble

[https://adventofcode.com/2022/day/6](https://adventofcode.com/2022/day/6)

## Description

### Part One

The preparations are finally complete; you and the Elves leave camp on foot and begin to make your way toward the _star_ fruit grove.

As you move through the dense undergrowth, one of the Elves gives you a handheld _device_. He says that it has many fancy features, but the most important one to set up right now is the _communication system_.

However, because he's heard you have [significant](https://adventofcode.com/2016/day/6) [experience](https://adventofcode.com/2016/day/25) [dealing](https://adventofcode.com/2019/day/7) [with](https://adventofcode.com/2019/day/9) [signal-based](https://adventofcode.com/2019/day/16) [systems](https://adventofcode.com/2021/day/25), he convinced the other Elves that it would be okay to give you their one malfunctioning device - surely you'll have no problem fixing it.

As if inspired by comedic timing, the device emits a few <span title="The magic smoke, on the other hand, seems to be contained... FOR NOW!">colorful sparks</span>.

To be able to communicate with the Elves, the device needs to _lock on to their signal_. The signal is a series of seemingly-random characters that the device receives one at a time.

To fix the communication system, you need to add a subroutine to the device that detects a _start-of-packet marker_ in the datastream. In the protocol being used by the Elves, the start of a packet is indicated by a sequence of _four characters that are all different_.

The device will send your subroutine a datastream buffer (your puzzle input); your subroutine needs to identify the first position where the four most recently received characters were all different. Specifically, it needs to report the number of characters from the beginning of the buffer to the end of the first such four-character marker.

For example, suppose you receive the following datastream buffer:

    mjqjpqmgbljsphdztnvjfqwrcgsmlb

After the first three characters (`mjq`) have been received, there haven't been enough characters received yet to find the marker. The first time a marker could occur is after the fourth character is received, making the most recent four characters `mjqj`. Because `j` is repeated, this isn't a marker.

The first time a marker appears is after the _seventh_ character arrives. Once it does, the last four characters received are `jpqm`, which are all different. In this case, your subroutine should report the value _`7`_, because the first start-of-packet marker is complete after 7 characters have been processed.

Here are a few more examples:

*   `bvwbjplbgvbhsrlpgdmjqwftvncz`: first marker after character _`5`_
*   `nppdvjthqldpwncqszvftbrmjlhg`: first marker after character _`6`_
*   `nznrnfrfntjfmvfwmzdfjlvtqnbhcprsg`: first marker after character _`10`_
*   `zcfzfwzzqfrljwzlrfnpqdbhtmscgvjw`: first marker after character _`11`_

_How many characters need to be processed before the first start-of-packet marker is detected?_

### Part Two

Your device's communication system is correctly detecting packets, but still isn't working. It looks like it also needs to look for _messages_.

A _start-of-message marker_ is just like a start-of-packet marker, except it consists of _14 distinct characters_ rather than 4.

Here are the first positions of start-of-message markers for all of the above examples:

*   `mjqjpqmgbljsphdztnvjfqwrcgsmlb`: first marker after character _`19`_
*   `bvwbjplbgvbhsrlpgdmjqwftvncz`: first marker after character _`23`_
*   `nppdvjthqldpwncqszvftbrmjlhg`: first marker after character _`23`_
*   `nznrnfrfntjfmvfwmzdfjlvtqnbhcprsg`: first marker after character _`29`_
*   `zcfzfwzzqfrljwzlrfnpqdbhtmscgvjw`: first marker after character _`26`_

_How many characters need to be processed before the first start-of-message marker is detected?_

# Day 7: No Space Left On Device

[https://adventofcode.com/2022/day/7](https://adventofcode.com/2022/day/7)

## Description

### Part One

You can hear birds chirping and raindrops hitting leaves as the expedition proceeds. Occasionally, you can even hear much louder sounds in the distance; how big do the animals get out here, anyway?

The device the Elves gave you has problems with more than just its communication system. You try to run a system update:

    $ system-update --please --pretty-please-with-sugar-on-top
    Error: No space left on device


Perhaps you can delete some files to make space for the update?

You browse around the filesystem to assess the situation and save the resulting terminal output (your puzzle input). For example:

    $ cd /
    $ ls
    dir a
    14848514 b.txt
    8504156 c.dat
    dir d
    $ cd a
    $ ls
    dir e
    29116 f
    2557 g
    62596 h.lst
    $ cd e
    $ ls
    584 i
    $ cd ..
    $ cd ..
    $ cd d
    $ ls
    4060174 j
    8033020 d.log
    5626152 d.ext
    7214296 k


The filesystem consists of a tree of files (plain data) and directories (which can contain other directories or files). The outermost directory is called `/`. You can navigate around the filesystem, moving into or out of directories and listing the contents of the directory you're currently in.

Within the terminal output, lines that begin with `$` are _commands you executed_, very much like some modern computers:

*   `cd` means _change directory_. This changes which directory is the current directory, but the specific result depends on the argument:
    *   `cd x` moves _in_ one level: it looks in the current directory for the directory named `x` and makes it the current directory.
    *   `cd ..` moves _out_ one level: it finds the directory that contains the current directory, then makes that directory the current directory.
    *   `cd /` switches the current directory to the outermost directory, `/`.
*   `ls` means _list_. It prints out all of the files and directories immediately contained by the current directory:
    *   `123 abc` means that the current directory contains a file named `abc` with size `123`.
    *   `dir xyz` means that the current directory contains a directory named `xyz`.

Given the commands and output in the example above, you can determine that the filesystem looks visually like this:

    - / (dir)
      - a (dir)
        - e (dir)
          - i (file, size=584)
        - f (file, size=29116)
        - g (file, size=2557)
        - h.lst (file, size=62596)
      - b.txt (file, size=14848514)
      - c.dat (file, size=8504156)
      - d (dir)
        - j (file, size=4060174)
        - d.log (file, size=8033020)
        - d.ext (file, size=5626152)
        - k (file, size=7214296)


Here, there are four directories: `/` (the outermost directory), `a` and `d` (which are in `/`), and `e` (which is in `a`). These directories also contain files of various sizes.

Since the disk is full, your first step should probably be to find directories that are good candidates for deletion. To do this, you need to determine the _total size_ of each directory. The total size of a directory is the sum of the sizes of the files it contains, directly or indirectly. (Directories themselves do not count as having any intrinsic size.)

The total sizes of the directories above can be found as follows:

*   The total size of directory `e` is _584_ because it contains a single file `i` of size 584 and no other directories.
*   The directory `a` has total size _94853_ because it contains files `f` (size 29116), `g` (size 2557), and `h.lst` (size 62596), plus file `i` indirectly (`a` contains `e` which contains `i`).
*   Directory `d` has total size _24933642_.
*   As the outermost directory, `/` contains every file. Its total size is _48381165_, the sum of the size of every file.

To begin, find all of the directories with a total size of _at most 100000_, then calculate the sum of their total sizes. In the example above, these directories are `a` and `e`; the sum of their total sizes is _`95437`_ (94853 + 584). (As in this example, this process can count files more than once!)

Find all of the directories with a total size of at most 100000. _What is the sum of the total sizes of those directories?_

### Part Two

Now, you're ready to choose a directory to delete.

The total disk space available to the filesystem is _`70000000`_. To run the update, you need unused space of at least _`30000000`_. You need to find a directory you can delete that will _free up enough space_ to run the update.

In the example above, the total size of the outermost directory (and thus the total amount of used space) is `48381165`; this means that the size of the _unused_ space must currently be `21618835`, which isn't quite the `30000000` required by the update. Therefore, the update still requires a directory with total size of at least `8381165` to be deleted before it can run.

To achieve this, you have the following options:

*   Delete directory `e`, which would increase unused space by `584`.
*   Delete directory `a`, which would increase unused space by `94853`.
*   Delete directory `d`, which would increase unused space by `24933642`.
*   Delete directory `/`, which would increase unused space by `48381165`.

Directories `e` and `a` are both too small; deleting them would not free up enough space. However, directories `d` and `/` are both big enough! Between these, choose the _smallest_: `d`, increasing unused space by _`24933642`_.

Find the smallest directory that, if deleted, would free up enough space on the filesystem to run the update. _What is the total size of that directory?_

# Day 8: Treetop Tree House

[https://adventofcode.com/2022/day/8](https://adventofcode.com/2022/day/8)

## Description

### Part One

The expedition comes across a peculiar patch of tall trees all planted carefully in a grid. The Elves explain that a previous expedition planted these trees as a reforestation effort. Now, they're curious if this would be a good location for a [tree house](https://en.wikipedia.org/wiki/Tree_house).

First, determine whether there is enough tree cover here to keep a tree house _hidden_. To do this, you need to count the number of trees that are _visible from outside the grid_ when looking directly along a row or column.

The Elves have already launched a [quadcopter](https://en.wikipedia.org/wiki/Quadcopter) to generate a map with the height of each tree (<span title="The Elves have already launched a quadcopter (your puzzle input).">your puzzle input</span>). For example:

    30373
    25512
    65332
    33549
    35390


Each tree is represented as a single digit whose value is its height, where `0` is the shortest and `9` is the tallest.

A tree is _visible_ if all of the other trees between it and an edge of the grid are _shorter_ than it. Only consider trees in the same row or column; that is, only look up, down, left, or right from any given tree.

All of the trees around the edge of the grid are _visible_ - since they are already on the edge, there are no trees to block the view. In this example, that only leaves the _interior nine trees_ to consider:

*   The top-left `5` is _visible_ from the left and top. (It isn't visible from the right or bottom since other trees of height `5` are in the way.)
*   The top-middle `5` is _visible_ from the top and right.
*   The top-right `1` is not visible from any direction; for it to be visible, there would need to only be trees of height _0_ between it and an edge.
*   The left-middle `5` is _visible_, but only from the right.
*   The center `3` is not visible from any direction; for it to be visible, there would need to be only trees of at most height `2` between it and an edge.
*   The right-middle `3` is _visible_ from the right.
*   In the bottom row, the middle `5` is _visible_, but the `3` and `4` are not.

With 16 trees visible on the edge and another 5 visible in the interior, a total of _`21`_ trees are visible in this arrangement.

Consider your map; _how many trees are visible from outside the grid?_

### Part Two

Content with the amount of tree cover available, the Elves just need to know the best spot to build their tree house: they would like to be able to see a lot of _trees_.

To measure the viewing distance from a given tree, look up, down, left, and right from that tree; stop if you reach an edge or at the first tree that is the same height or taller than the tree under consideration. (If a tree is right on the edge, at least one of its viewing distances will be zero.)

The Elves don't care about distant trees taller than those found by the rules above; the proposed tree house has large [eaves](https://en.wikipedia.org/wiki/Eaves) to keep it dry, so they wouldn't be able to see higher than the tree house anyway.

In the example above, consider the middle `5` in the second row:

    30373
    25512
    65332
    33549
    35390


*   Looking up, its view is not blocked; it can see _`1`_ tree (of height `3`).
*   Looking left, its view is blocked immediately; it can see only _`1`_ tree (of height `5`, right next to it).
*   Looking right, its view is not blocked; it can see _`2`_ trees.
*   Looking down, its view is blocked eventually; it can see _`2`_ trees (one of height `3`, then the tree of height `5` that blocks its view).

A tree's _scenic score_ is found by _multiplying together_ its viewing distance in each of the four directions. For this tree, this is _`4`_ (found by multiplying `1 * 1 * 2 * 2`).

However, you can do even better: consider the tree of height `5` in the middle of the fourth row:

    30373
    25512
    65332
    33549
    35390


*   Looking up, its view is blocked at _`2`_ trees (by another tree with a height of `5`).
*   Looking left, its view is not blocked; it can see _`2`_ trees.
*   Looking down, its view is also not blocked; it can see _`1`_ tree.
*   Looking right, its view is blocked at _`2`_ trees (by a massive tree of height `9`).

This tree's scenic score is _`8`_ (`2 * 2 * 1 * 2`); this is the ideal spot for the tree house.

Consider each tree on your map. _What is the highest scenic score possible for any tree?_

# Day 9: Rope Bridge

[https://adventofcode.com/2022/day/9](https://adventofcode.com/2022/day/9)

## Description

### Part One

This rope bridge creaks as you walk along it. You aren't sure how old it is, or whether it can even support your weight.

It seems to support the Elves just fine, though. The bridge spans a gorge which was carved out by the massive river far below you.

You step carefully; as you do, the ropes stretch and twist. You decide to distract yourself by modeling rope physics; maybe you can even figure out where _not_ to step.

Consider a rope with a knot at each end; these knots mark the _head_ and the _tail_ of the rope. If the head moves far enough away from the tail, the tail is pulled toward the head.

Due to nebulous reasoning involving [Planck lengths](https://en.wikipedia.org/wiki/Planck_units#Planck_length), you should be able to model the positions of the knots on a two-dimensional grid. Then, by following a hypothetical _series of motions_ (your puzzle input) for the head, you can determine how the tail will move.

<span title="I'm an engineer, not a physicist!">Due to the aforementioned Planck lengths</span>, the rope must be quite short; in fact, the head (`H`) and tail (`T`) must _always be touching_ (diagonally adjacent and even overlapping both count as touching):

    ....
    .TH.
    ....

    ....
    .H..
    ..T.
    ....

    ...
    .H. (H covers T)
    ...


If the head is ever two steps directly up, down, left, or right from the tail, the tail must also move one step in that direction so it remains close enough:

    .....    .....    .....
    .TH.. -> .T.H. -> ..TH.
    .....    .....    .....

    ...    ...    ...
    .T.    .T.    ...
    .H. -> ... -> .T.
    ...    .H.    .H.
    ...    ...    ...


Otherwise, if the head and tail aren't touching and aren't in the same row or column, the tail always moves one step diagonally to keep up:

    .....    .....    .....
    .....    ..H..    ..H..
    ..H.. -> ..... -> ..T..
    .T...    .T...    .....
    .....    .....    .....

    .....    .....    .....
    .....    .....    .....
    ..H.. -> ...H. -> ..TH.
    .T...    .T...    .....
    .....    .....    .....


You just need to work out where the tail goes as the head follows a series of motions. Assume the head and the tail both start at the same position, overlapping.

For example:

    R 4
    U 4
    L 3
    D 1
    R 4
    D 1
    L 5
    R 2


This series of motions moves the head _right_ four steps, then _up_ four steps, then _left_ three steps, then _down_ one step, and so on. After each step, you'll need to update the position of the tail if the step means the head is no longer adjacent to the tail. Visually, these motions occur as follows (`s` marks the starting position as a reference point):

    == Initial State ==

    ......
    ......
    ......
    ......
    H.....  (H covers T, s)

    == R 4 ==

    ......
    ......
    ......
    ......
    TH....  (T covers s)

    ......
    ......
    ......
    ......
    sTH...

    ......
    ......
    ......
    ......
    s.TH..

    ......
    ......
    ......
    ......
    s..TH.

    == U 4 ==

    ......
    ......
    ......
    ....H.
    s..T..

    ......
    ......
    ....H.
    ....T.
    s.....

    ......
    ....H.
    ....T.
    ......
    s.....

    ....H.
    ....T.
    ......
    ......
    s.....

    == L 3 ==

    ...H..
    ....T.
    ......
    ......
    s.....

    ..HT..
    ......
    ......
    ......
    s.....

    .HT...
    ......
    ......
    ......
    s.....

    == D 1 ==

    ..T...
    .H....
    ......
    ......
    s.....

    == R 4 ==

    ..T...
    ..H...
    ......
    ......
    s.....

    ..T...
    ...H..
    ......
    ......
    s.....

    ......
    ...TH.
    ......
    ......
    s.....

    ......
    ....TH
    ......
    ......
    s.....

    == D 1 ==

    ......
    ....T.
    .....H
    ......
    s.....

    == L 5 ==

    ......
    ....T.
    ....H.
    ......
    s.....

    ......
    ....T.
    ...H..
    ......
    s.....

    ......
    ......
    ..HT..
    ......
    s.....

    ......
    ......
    .HT...
    ......
    s.....

    ......
    ......
    HT....
    ......
    s.....

    == R 2 ==

    ......
    ......
    .H....  (H covers T)
    ......
    s.....

    ......
    ......
    .TH...
    ......
    s.....


After simulating the rope, you can count up all of the positions the _tail visited at least once_. In this diagram, `s` again marks the starting position (which the tail also visited) and `#` marks other positions the tail visited:

    ..##..
    ...##.
    .####.
    ....#.
    s###..


So, there are _`13`_ positions the tail visited at least once.

Simulate your complete hypothetical series of motions. _How many positions does the tail of the rope visit at least once?_

### Part Two

A rope snaps! Suddenly, the river is getting a lot closer than you remember. The bridge is still there, but some of the ropes that broke are now whipping toward you as you fall through the air!

The ropes are moving too quickly to grab; you only have a few seconds to choose how to arch your body to avoid being hit. Fortunately, your simulation can be extended to support longer ropes.

Rather than two knots, you now must simulate a rope consisting of _ten_ knots. One knot is still the head of the rope and moves according to the series of motions. Each knot further down the rope follows the knot in front of it using the same rules as before.

Using the same series of motions as the above example, but with the knots marked `H`, `1`, `2`, ..., `9`, the motions now occur as follows:

    == Initial State ==

    ......
    ......
    ......
    ......
    H.....  (H covers 1, 2, 3, 4, 5, 6, 7, 8, 9, s)

    == R 4 ==

    ......
    ......
    ......
    ......
    1H....  (1 covers 2, 3, 4, 5, 6, 7, 8, 9, s)

    ......
    ......
    ......
    ......
    21H...  (2 covers 3, 4, 5, 6, 7, 8, 9, s)

    ......
    ......
    ......
    ......
    321H..  (3 covers 4, 5, 6, 7, 8, 9, s)

    ......
    ......
    ......
    ......
    4321H.  (4 covers 5, 6, 7, 8, 9, s)

    == U 4 ==

    ......
    ......
    ......
    ....H.
    4321..  (4 covers 5, 6, 7, 8, 9, s)

    ......
    ......
    ....H.
    .4321.
    5.....  (5 covers 6, 7, 8, 9, s)

    ......
    ....H.
    ....1.
    .432..
    5.....  (5 covers 6, 7, 8, 9, s)

    ....H.
    ....1.
    ..432.
    .5....
    6.....  (6 covers 7, 8, 9, s)

    == L 3 ==

    ...H..
    ....1.
    ..432.
    .5....
    6.....  (6 covers 7, 8, 9, s)

    ..H1..
    ...2..
    ..43..
    .5....
    6.....  (6 covers 7, 8, 9, s)

    .H1...
    ...2..
    ..43..
    .5....
    6.....  (6 covers 7, 8, 9, s)

    == D 1 ==

    ..1...
    .H.2..
    ..43..
    .5....
    6.....  (6 covers 7, 8, 9, s)

    == R 4 ==

    ..1...
    ..H2..
    ..43..
    .5....
    6.....  (6 covers 7, 8, 9, s)

    ..1...
    ...H..  (H covers 2)
    ..43..
    .5....
    6.....  (6 covers 7, 8, 9, s)

    ......
    ...1H.  (1 covers 2)
    ..43..
    .5....
    6.....  (6 covers 7, 8, 9, s)

    ......
    ...21H
    ..43..
    .5....
    6.....  (6 covers 7, 8, 9, s)

    == D 1 ==

    ......
    ...21.
    ..43.H
    .5....
    6.....  (6 covers 7, 8, 9, s)

    == L 5 ==

    ......
    ...21.
    ..43H.
    .5....
    6.....  (6 covers 7, 8, 9, s)

    ......
    ...21.
    ..4H..  (H covers 3)
    .5....
    6.....  (6 covers 7, 8, 9, s)

    ......
    ...2..
    ..H1..  (H covers 4; 1 covers 3)
    .5....
    6.....  (6 covers 7, 8, 9, s)

    ......
    ...2..
    .H13..  (1 covers 4)
    .5....
    6.....  (6 covers 7, 8, 9, s)

    ......
    ......
    H123..  (2 covers 4)
    .5....
    6.....  (6 covers 7, 8, 9, s)

    == R 2 ==

    ......
    ......
    .H23..  (H covers 1; 2 covers 4)
    .5....
    6.....  (6 covers 7, 8, 9, s)

    ......
    ......
    .1H3..  (H covers 2, 4)
    .5....
    6.....  (6 covers 7, 8, 9, s)


Now, you need to keep track of the positions the new tail, `9`, visits. In this example, the tail never moves, and so it only visits _`1`_ position. However, _be careful_: more types of motion are possible than before, so you might want to visually compare your simulated rope to the one above.

Here's a larger example:

    R 5
    U 8
    L 8
    D 3
    R 17
    D 10
    L 25
    U 20


These motions occur as follows (individual steps are not shown):

    == Initial State ==

    ..........................
    ..........................
    ..........................
    ..........................
    ..........................
    ..........................
    ..........................
    ..........................
    ..........................
    ..........................
    ..........................
    ..........................
    ..........................
    ..........................
    ..........................
    ...........H..............  (H covers 1, 2, 3, 4, 5, 6, 7, 8, 9, s)
    ..........................
    ..........................
    ..........................
    ..........................
    ..........................

    == R 5 ==

    ..........................
    ..........................
    ..........................
    ..........................
    ..........................
    ..........................
    ..........................
    ..........................
    ..........................
    ..........................
    ..........................
    ..........................
    ..........................
    ..........................
    ..........................
    ...........54321H.........  (5 covers 6, 7, 8, 9, s)
    ..........................
    ..........................
    ..........................
    ..........................
    ..........................

    == U 8 ==

    ..........................
    ..........................
    ..........................
    ..........................
    ..........................
    ..........................
    ..........................
    ................H.........
    ................1.........
    ................2.........
    ................3.........
    ...............54.........
    ..............6...........
    .............7............
    ............8.............
    ...........9..............  (9 covers s)
    ..........................
    ..........................
    ..........................
    ..........................
    ..........................

    == L 8 ==

    ..........................
    ..........................
    ..........................
    ..........................
    ..........................
    ..........................
    ..........................
    ........H1234.............
    ............5.............
    ............6.............
    ............7.............
    ............8.............
    ............9.............
    ..........................
    ..........................
    ...........s..............
    ..........................
    ..........................
    ..........................
    ..........................
    ..........................

    == D 3 ==

    ..........................
    ..........................
    ..........................
    ..........................
    ..........................
    ..........................
    ..........................
    ..........................
    .........2345.............
    ........1...6.............
    ........H...7.............
    ............8.............
    ............9.............
    ..........................
    ..........................
    ...........s..............
    ..........................
    ..........................
    ..........................
    ..........................
    ..........................

    == R 17 ==

    ..........................
    ..........................
    ..........................
    ..........................
    ..........................
    ..........................
    ..........................
    ..........................
    ..........................
    ..........................
    ................987654321H
    ..........................
    ..........................
    ..........................
    ..........................
    ...........s..............
    ..........................
    ..........................
    ..........................
    ..........................
    ..........................

    == D 10 ==

    ..........................
    ..........................
    ..........................
    ..........................
    ..........................
    ..........................
    ..........................
    ..........................
    ..........................
    ..........................
    ..........................
    ..........................
    ..........................
    ..........................
    ..........................
    ...........s.........98765
    .........................4
    .........................3
    .........................2
    .........................1
    .........................H

    == L 25 ==

    ..........................
    ..........................
    ..........................
    ..........................
    ..........................
    ..........................
    ..........................
    ..........................
    ..........................
    ..........................
    ..........................
    ..........................
    ..........................
    ..........................
    ..........................
    ...........s..............
    ..........................
    ..........................
    ..........................
    ..........................
    H123456789................

    == U 20 ==

    H.........................
    1.........................
    2.........................
    3.........................
    4.........................
    5.........................
    6.........................
    7.........................
    8.........................
    9.........................
    ..........................
    ..........................
    ..........................
    ..........................
    ..........................
    ...........s..............
    ..........................
    ..........................
    ..........................
    ..........................
    ..........................



Now, the tail (`9`) visits _`36`_ positions (including `s`) at least once:

    ..........................
    ..........................
    ..........................
    ..........................
    ..........................
    ..........................
    ..........................
    ..........................
    ..........................
    #.........................
    #.............###.........
    #............#...#........
    .#..........#.....#.......
    ..#..........#.....#......
    ...#........#.......#.....
    ....#......s.........#....
    .....#..............#.....
    ......#............#......
    .......#..........#.......
    ........#........#........
    .........########.........


Simulate your complete series of motions on a larger rope with ten knots. _How many positions does the tail of the rope visit at least once?_

# Day 10: Cathode-Ray Tube

[https://adventofcode.com/2022/day/10](https://adventofcode.com/2022/day/10)

## Description

### Part One

You avoid the ropes, plunge into the river, and swim to shore.

The Elves yell something about meeting back up with them upriver, but the river is too loud to tell exactly what they're saying. They finish crossing the bridge and disappear from view.

Situations like this must be why the Elves prioritized getting the communication system on your handheld device working. You pull it out of your pack, but the amount of water slowly draining from a big crack in its screen tells you it probably won't be of much immediate use.

_Unless_, that is, you can design a replacement for the device's video system! It seems to be some kind of [cathode-ray tube](https://en.wikipedia.org/wiki/Cathode-ray_tube) screen and simple CPU that are both driven by a precise _clock circuit_. The clock circuit ticks at a constant rate; each tick is called a _cycle_.

Start by figuring out the signal being sent by the CPU. The CPU has a single register, `X`, which starts with the value `1`. It supports only two instructions:

*   `addx V` takes _two cycles_ to complete. _After_ two cycles, the `X` register is increased by the value `V`. (`V` can be negative.)
*   `noop` takes _one cycle_ to complete. It has no other effect.

The CPU uses these instructions in a program (your puzzle input) to, somehow, tell the screen what to draw.

Consider the following small program:

    noop
    addx 3
    addx -5


Execution of this program proceeds as follows:

*   At the start of the first cycle, the `noop` instruction begins execution. During the first cycle, `X` is `1`. After the first cycle, the `noop` instruction finishes execution, doing nothing.
*   At the start of the second cycle, the `addx 3` instruction begins execution. During the second cycle, `X` is still `1`.
*   During the third cycle, `X` is still `1`. After the third cycle, the `addx 3` instruction finishes execution, setting `X` to `4`.
*   At the start of the fourth cycle, the `addx -5` instruction begins execution. During the fourth cycle, `X` is still `4`.
*   During the fifth cycle, `X` is still `4`. After the fifth cycle, the `addx -5` instruction finishes execution, setting `X` to `-1`.

Maybe you can learn something by looking at the value of the `X` register throughout execution. For now, consider the _signal strength_ (the cycle number multiplied by the value of the `X` register) _during_ the 20th cycle and every 40 cycles after that (that is, during the 20th, 60th, 100th, 140th, 180th, and 220th cycles).

For example, consider this larger program:

    addx 15
    addx -11
    addx 6
    addx -3
    addx 5
    addx -1
    addx -8
    addx 13
    addx 4
    noop
    addx -1
    addx 5
    addx -1
    addx 5
    addx -1
    addx 5
    addx -1
    addx 5
    addx -1
    addx -35
    addx 1
    addx 24
    addx -19
    addx 1
    addx 16
    addx -11
    noop
    noop
    addx 21
    addx -15
    noop
    noop
    addx -3
    addx 9
    addx 1
    addx -3
    addx 8
    addx 1
    addx 5
    noop
    noop
    noop
    noop
    noop
    addx -36
    noop
    addx 1
    addx 7
    noop
    noop
    noop
    addx 2
    addx 6
    noop
    noop
    noop
    noop
    noop
    addx 1
    noop
    noop
    addx 7
    addx 1
    noop
    addx -13
    addx 13
    addx 7
    noop
    addx 1
    addx -33
    noop
    noop
    noop
    addx 2
    noop
    noop
    noop
    addx 8
    noop
    addx -1
    addx 2
    addx 1
    noop
    addx 17
    addx -9
    addx 1
    addx 1
    addx -3
    addx 11
    noop
    noop
    addx 1
    noop
    addx 1
    noop
    noop
    addx -13
    addx -19
    addx 1
    addx 3
    addx 26
    addx -30
    addx 12
    addx -1
    addx 3
    addx 1
    noop
    noop
    noop
    addx -9
    addx 18
    addx 1
    addx 2
    noop
    noop
    addx 9
    noop
    noop
    noop
    addx -1
    addx 2
    addx -37
    addx 1
    addx 3
    noop
    addx 15
    addx -21
    addx 22
    addx -6
    addx 1
    noop
    addx 2
    addx 1
    noop
    addx -10
    noop
    noop
    addx 20
    addx 1
    addx 2
    addx 2
    addx -6
    addx -11
    noop
    noop
    noop


The interesting signal strengths can be determined as follows:

*   During the 20th cycle, register `X` has the value `21`, so the signal strength is 20 \* 21 = _420_. (The 20th cycle occurs in the middle of the second `addx -1`, so the value of register `X` is the starting value, `1`, plus all of the other `addx` values up to that point: 1 + 15 - 11 + 6 - 3 + 5 - 1 - 8 + 13 + 4 = 21.)
*   During the 60th cycle, register `X` has the value `19`, so the signal strength is 60 \* 19 = _`1140`_.
*   During the 100th cycle, register `X` has the value `18`, so the signal strength is 100 \* 18 = _`1800`_.
*   During the 140th cycle, register `X` has the value `21`, so the signal strength is 140 \* 21 = _`2940`_.
*   During the 180th cycle, register `X` has the value `16`, so the signal strength is 180 \* 16 = _`2880`_.
*   During the 220th cycle, register `X` has the value `18`, so the signal strength is 220 \* 18 = _`3960`_.

The sum of these signal strengths is _`13140`_.

Find the signal strength during the 20th, 60th, 100th, 140th, 180th, and 220th cycles. _What is the sum of these six signal strengths?_

### Part Two

It seems like the `X` register controls the horizontal position of a [sprite](https://en.wikipedia.org/wiki/Sprite_(computer_graphics)). Specifically, the sprite is 3 pixels wide, and the `X` register sets the horizontal position of the _middle_ of that sprite. (In this system, there is no such thing as "vertical position": if the sprite's horizontal position puts its pixels where the CRT is currently drawing, then those pixels will be drawn.)

You count the pixels on the CRT: 40 wide and 6 high. This CRT screen draws the top row of pixels left-to-right, then the row below that, and so on. The left-most pixel in each row is in position `0`, and the right-most pixel in each row is in position `39`.

Like the CPU, the CRT is tied closely to the clock circuit: the CRT draws _a single pixel during each cycle_. Representing each pixel of the screen as a `#`, here are the cycles during which the first and last pixel in each row are drawn:

    Cycle   1 -> ######################################## <- Cycle  40
    Cycle  41 -> ######################################## <- Cycle  80
    Cycle  81 -> ######################################## <- Cycle 120
    Cycle 121 -> ######################################## <- Cycle 160
    Cycle 161 -> ######################################## <- Cycle 200
    Cycle 201 -> ######################################## <- Cycle 240


So, by [carefully](https://en.wikipedia.org/wiki/Racing_the_Beam) [<span title="While you're at it, go watch everything else by Retro Game Mechanics Explained, too.">timing</span>](https://www.youtube.com/watch?v=sJFnWZH5FXc) the CPU instructions and the CRT drawing operations, you should be able to determine whether the sprite is visible the instant each pixel is drawn. If the sprite is positioned such that one of its three pixels is the pixel currently being drawn, the screen produces a _lit_ pixel (`#`); otherwise, the screen leaves the pixel _dark_ (`.`).

The first few pixels from the larger example above are drawn as follows:

    Sprite position: ###.....................................

    Start cycle   1: begin executing addx 15
    During cycle  1: CRT draws pixel in position 0
    Current CRT row: #

    During cycle  2: CRT draws pixel in position 1
    Current CRT row: ##
    End of cycle  2: finish executing addx 15 (Register X is now 16)
    Sprite position: ...............###......................

    Start cycle   3: begin executing addx -11
    During cycle  3: CRT draws pixel in position 2
    Current CRT row: ##.

    During cycle  4: CRT draws pixel in position 3
    Current CRT row: ##..
    End of cycle  4: finish executing addx -11 (Register X is now 5)
    Sprite position: ....###.................................

    Start cycle   5: begin executing addx 6
    During cycle  5: CRT draws pixel in position 4
    Current CRT row: ##..#

    During cycle  6: CRT draws pixel in position 5
    Current CRT row: ##..##
    End of cycle  6: finish executing addx 6 (Register X is now 11)
    Sprite position: ..........###...........................

    Start cycle   7: begin executing addx -3
    During cycle  7: CRT draws pixel in position 6
    Current CRT row: ##..##.

    During cycle  8: CRT draws pixel in position 7
    Current CRT row: ##..##..
    End of cycle  8: finish executing addx -3 (Register X is now 8)
    Sprite position: .......###..............................

    Start cycle   9: begin executing addx 5
    During cycle  9: CRT draws pixel in position 8
    Current CRT row: ##..##..#

    During cycle 10: CRT draws pixel in position 9
    Current CRT row: ##..##..##
    End of cycle 10: finish executing addx 5 (Register X is now 13)
    Sprite position: ............###.........................

    Start cycle  11: begin executing addx -1
    During cycle 11: CRT draws pixel in position 10
    Current CRT row: ##..##..##.

    During cycle 12: CRT draws pixel in position 11
    Current CRT row: ##..##..##..
    End of cycle 12: finish executing addx -1 (Register X is now 12)
    Sprite position: ...........###..........................

    Start cycle  13: begin executing addx -8
    During cycle 13: CRT draws pixel in position 12
    Current CRT row: ##..##..##..#

    During cycle 14: CRT draws pixel in position 13
    Current CRT row: ##..##..##..##
    End of cycle 14: finish executing addx -8 (Register X is now 4)
    Sprite position: ...###..................................

    Start cycle  15: begin executing addx 13
    During cycle 15: CRT draws pixel in position 14
    Current CRT row: ##..##..##..##.

    During cycle 16: CRT draws pixel in position 15
    Current CRT row: ##..##..##..##..
    End of cycle 16: finish executing addx 13 (Register X is now 17)
    Sprite position: ................###.....................

    Start cycle  17: begin executing addx 4
    During cycle 17: CRT draws pixel in position 16
    Current CRT row: ##..##..##..##..#

    During cycle 18: CRT draws pixel in position 17
    Current CRT row: ##..##..##..##..##
    End of cycle 18: finish executing addx 4 (Register X is now 21)
    Sprite position: ....................###.................

    Start cycle  19: begin executing noop
    During cycle 19: CRT draws pixel in position 18
    Current CRT row: ##..##..##..##..##.
    End of cycle 19: finish executing noop

    Start cycle  20: begin executing addx -1
    During cycle 20: CRT draws pixel in position 19
    Current CRT row: ##..##..##..##..##..

    During cycle 21: CRT draws pixel in position 20
    Current CRT row: ##..##..##..##..##..#
    End of cycle 21: finish executing addx -1 (Register X is now 20)
    Sprite position: ...................###..................


Allowing the program to run to completion causes the CRT to produce the following image:

    ##..##..##..##..##..##..##..##..##..##..
    ###...###...###...###...###...###...###.
    ####....####....####....####....####....
    #####.....#####.....#####.....#####.....
    ######......######......######......####
    #######.......#######.......#######.....


Render the image given by your program. _What eight capital letters appear on your CRT?_

# Day 11: Monkey in the Middle

[https://adventofcode.com/2022/day/11](https://adventofcode.com/2022/day/11)

## Description

### Part One

As you finally start making your way upriver, you realize your pack is much lighter than you remember. Just then, one of the items from your pack goes flying overhead. Monkeys are playing [Keep Away](https://en.wikipedia.org/wiki/Keep_away) with your missing things!

To get your stuff back, you need to be able to predict where the monkeys will throw your items. After some careful observation, you realize the monkeys operate based on _how worried you are about each item_.

You take some notes (your puzzle input) on the items each monkey currently has, how worried you are about those items, and how the monkey makes decisions based on your worry level. For example:

    Monkey 0:
      Starting items: 79, 98
      Operation: new = old * 19
      Test: divisible by 23
        If true: throw to monkey 2
        If false: throw to monkey 3

    Monkey 1:
      Starting items: 54, 65, 75, 74
      Operation: new = old + 6
      Test: divisible by 19
        If true: throw to monkey 2
        If false: throw to monkey 0

    Monkey 2:
      Starting items: 79, 60, 97
      Operation: new = old * old
      Test: divisible by 13
        If true: throw to monkey 1
        If false: throw to monkey 3

    Monkey 3:
      Starting items: 74
      Operation: new = old + 3
      Test: divisible by 17
        If true: throw to monkey 0
        If false: throw to monkey 1


Each monkey has several attributes:

*   `Starting items` lists your _worry level_ for each item the monkey is currently holding in the order they will be inspected.
*   `Operation` shows how your worry level changes as that monkey inspects an item. (An operation like `new = old * 5` means that your worry level after the monkey inspected the item is five times whatever your worry level was before inspection.)
*   `Test` shows how the monkey uses your worry level to decide where to throw an item next.
    *   `If true` shows what happens with an item if the `Test` was true.
    *   `If false` shows what happens with an item if the `Test` was false.

After each monkey inspects an item but before it tests your worry level, your relief that the monkey's inspection didn't damage the item causes your worry level to be _divided by three_ and rounded down to the nearest integer.

The monkeys take turns inspecting and throwing items. On a single monkey's _turn_, it inspects and throws all of the items it is holding one at a time and in the order listed. Monkey `0` goes first, then monkey `1`, and so on until each monkey has had one turn. The process of each monkey taking a single turn is called a _round_.

When a monkey throws an item to another monkey, the item goes on the _end_ of the recipient monkey's list. A monkey that starts a round with no items could end up inspecting and throwing many items by the time its turn comes around. If a monkey is holding no items at the start of its turn, its turn ends.

In the above example, the first round proceeds as follows:

    Monkey 0:
      Monkey inspects an item with a worry level of 79.
        Worry level is multiplied by 19 to 1501.
        Monkey gets bored with item. Worry level is divided by 3 to 500.
        Current worry level is not divisible by 23.
        Item with worry level 500 is thrown to monkey 3.
      Monkey inspects an item with a worry level of 98.
        Worry level is multiplied by 19 to 1862.
        Monkey gets bored with item. Worry level is divided by 3 to 620.
        Current worry level is not divisible by 23.
        Item with worry level 620 is thrown to monkey 3.
    Monkey 1:
      Monkey inspects an item with a worry level of 54.
        Worry level increases by 6 to 60.
        Monkey gets bored with item. Worry level is divided by 3 to 20.
        Current worry level is not divisible by 19.
        Item with worry level 20 is thrown to monkey 0.
      Monkey inspects an item with a worry level of 65.
        Worry level increases by 6 to 71.
        Monkey gets bored with item. Worry level is divided by 3 to 23.
        Current worry level is not divisible by 19.
        Item with worry level 23 is thrown to monkey 0.
      Monkey inspects an item with a worry level of 75.
        Worry level increases by 6 to 81.
        Monkey gets bored with item. Worry level is divided by 3 to 27.
        Current worry level is not divisible by 19.
        Item with worry level 27 is thrown to monkey 0.
      Monkey inspects an item with a worry level of 74.
        Worry level increases by 6 to 80.
        Monkey gets bored with item. Worry level is divided by 3 to 26.
        Current worry level is not divisible by 19.
        Item with worry level 26 is thrown to monkey 0.
    Monkey 2:
      Monkey inspects an item with a worry level of 79.
        Worry level is multiplied by itself to 6241.
        Monkey gets bored with item. Worry level is divided by 3 to 2080.
        Current worry level is divisible by 13.
        Item with worry level 2080 is thrown to monkey 1.
      Monkey inspects an item with a worry level of 60.
        Worry level is multiplied by itself to 3600.
        Monkey gets bored with item. Worry level is divided by 3 to 1200.
        Current worry level is not divisible by 13.
        Item with worry level 1200 is thrown to monkey 3.
      Monkey inspects an item with a worry level of 97.
        Worry level is multiplied by itself to 9409.
        Monkey gets bored with item. Worry level is divided by 3 to 3136.
        Current worry level is not divisible by 13.
        Item with worry level 3136 is thrown to monkey 3.
    Monkey 3:
      Monkey inspects an item with a worry level of 74.
        Worry level increases by 3 to 77.
        Monkey gets bored with item. Worry level is divided by 3 to 25.
        Current worry level is not divisible by 17.
        Item with worry level 25 is thrown to monkey 1.
      Monkey inspects an item with a worry level of 500.
        Worry level increases by 3 to 503.
        Monkey gets bored with item. Worry level is divided by 3 to 167.
        Current worry level is not divisible by 17.
        Item with worry level 167 is thrown to monkey 1.
      Monkey inspects an item with a worry level of 620.
        Worry level increases by 3 to 623.
        Monkey gets bored with item. Worry level is divided by 3 to 207.
        Current worry level is not divisible by 17.
        Item with worry level 207 is thrown to monkey 1.
      Monkey inspects an item with a worry level of 1200.
        Worry level increases by 3 to 1203.
        Monkey gets bored with item. Worry level is divided by 3 to 401.
        Current worry level is not divisible by 17.
        Item with worry level 401 is thrown to monkey 1.
      Monkey inspects an item with a worry level of 3136.
        Worry level increases by 3 to 3139.
        Monkey gets bored with item. Worry level is divided by 3 to 1046.
        Current worry level is not divisible by 17.
        Item with worry level 1046 is thrown to monkey 1.


After round 1, the monkeys are holding items with these worry levels:

    Monkey 0: 20, 23, 27, 26
    Monkey 1: 2080, 25, 167, 207, 401, 1046
    Monkey 2:
    Monkey 3:


Monkeys 2 and 3 aren't holding any items at the end of the round; they both inspected items during the round and threw them all before the round ended.

This process continues for a few more rounds:

    After round 2, the monkeys are holding items with these worry levels:
    Monkey 0: 695, 10, 71, 135, 350
    Monkey 1: 43, 49, 58, 55, 362
    Monkey 2:
    Monkey 3:

    After round 3, the monkeys are holding items with these worry levels:
    Monkey 0: 16, 18, 21, 20, 122
    Monkey 1: 1468, 22, 150, 286, 739
    Monkey 2:
    Monkey 3:

    After round 4, the monkeys are holding items with these worry levels:
    Monkey 0: 491, 9, 52, 97, 248, 34
    Monkey 1: 39, 45, 43, 258
    Monkey 2:
    Monkey 3:

    After round 5, the monkeys are holding items with these worry levels:
    Monkey 0: 15, 17, 16, 88, 1037
    Monkey 1: 20, 110, 205, 524, 72
    Monkey 2:
    Monkey 3:

    After round 6, the monkeys are holding items with these worry levels:
    Monkey 0: 8, 70, 176, 26, 34
    Monkey 1: 481, 32, 36, 186, 2190
    Monkey 2:
    Monkey 3:

    After round 7, the monkeys are holding items with these worry levels:
    Monkey 0: 162, 12, 14, 64, 732, 17
    Monkey 1: 148, 372, 55, 72
    Monkey 2:
    Monkey 3:

    After round 8, the monkeys are holding items with these worry levels:
    Monkey 0: 51, 126, 20, 26, 136
    Monkey 1: 343, 26, 30, 1546, 36
    Monkey 2:
    Monkey 3:

    After round 9, the monkeys are holding items with these worry levels:
    Monkey 0: 116, 10, 12, 517, 14
    Monkey 1: 108, 267, 43, 55, 288
    Monkey 2:
    Monkey 3:

    After round 10, the monkeys are holding items with these worry levels:
    Monkey 0: 91, 16, 20, 98
    Monkey 1: 481, 245, 22, 26, 1092, 30
    Monkey 2:
    Monkey 3:

    ...

    After round 15, the monkeys are holding items with these worry levels:
    Monkey 0: 83, 44, 8, 184, 9, 20, 26, 102
    Monkey 1: 110, 36
    Monkey 2:
    Monkey 3:

    ...

    After round 20, the monkeys are holding items with these worry levels:
    Monkey 0: 10, 12, 14, 26, 34
    Monkey 1: 245, 93, 53, 199, 115
    Monkey 2:
    Monkey 3:


Chasing all of the monkeys at once is impossible; you're going to have to focus on the _two most active_ monkeys if you want any hope of getting your stuff back. Count the _total number of times each monkey inspects items_ over 20 rounds:

    Monkey 0 inspected items 101 times.
    Monkey 1 inspected items 95 times.
    Monkey 2 inspected items 7 times.
    Monkey 3 inspected items 105 times.


In this example, the two most active monkeys inspected items 101 and 105 times. The level of _monkey business_ in this situation can be found by multiplying these together: _`10605`_.

Figure out which monkeys to chase by counting how many items they inspect over 20 rounds. _What is the level of monkey business after 20 rounds of stuff-slinging simian shenanigans?_

# Day 12: Hill Climbing Algorithm

[https://adventofcode.com/2022/day/12](https://adventofcode.com/2022/day/12)

## Description

### Part One

You try contacting the Elves using your <span title="When you look up the specs for your handheld device, every field just says &quot;plot&quot;.">handheld device</span>, but the river you're following must be too low to get a decent signal.

You ask the device for a heightmap of the surrounding area (your puzzle input). The heightmap shows the local area from above broken into a grid; the elevation of each square of the grid is given by a single lowercase letter, where `a` is the lowest elevation, `b` is the next-lowest, and so on up to the highest elevation, `z`.

Also included on the heightmap are marks for your current position (`S`) and the location that should get the best signal (`E`). Your current position (`S`) has elevation `a`, and the location that should get the best signal (`E`) has elevation `z`.

You'd like to reach `E`, but to save energy, you should do it in _as few steps as possible_. During each step, you can move exactly one square up, down, left, or right. To avoid needing to get out your climbing gear, the elevation of the destination square can be _at most one higher_ than the elevation of your current square; that is, if your current elevation is `m`, you could step to elevation `n`, but not to elevation `o`. (This also means that the elevation of the destination square can be much lower than the elevation of your current square.)

For example:

    Sabqponm
    abcryxxl
    accszExk
    acctuvwj
    abdefghi


Here, you start in the top-left corner; your goal is near the middle. You could start by moving down or right, but eventually you'll need to head toward the `e` at the bottom. From there, you can spiral around to the goal:

    v..v<<<<
    >v.vv<<^
    .>vv>E^^
    ..v>>>^^
    ..>>>>>^


In the above diagram, the symbols indicate whether the path exits each square moving up (`^`), down (`v`), left (`<`), or right (`>`). The location that should get the best signal is still `E`, and `.` marks unvisited squares.

This path reaches the goal in _`31`_ steps, the fewest possible.

_What is the fewest steps required to move from your current position to the location that should get the best signal?_

# Day 13: Distress Signal

[https://adventofcode.com/2022/day/13](https://adventofcode.com/2022/day/13)

## Description

### Part One

You climb the hill and again try contacting the Elves. However, you instead receive a signal you weren't expecting: a _distress signal_.

Your handheld device must still not be working properly; the packets from the distress signal got decoded _out of order_. You'll need to re-order the list of received packets (your puzzle input) to decode the message.

Your list consists of pairs of packets; pairs are separated by a blank line. You need to identify _how many pairs of packets are in the right order_.

For example:

    [1,1,3,1,1]
    [1,1,5,1,1]

    [[1],[2,3,4]]
    [[1],4]

    [9]
    [[8,7,6]]

    [[4,4],4,4]
    [[4,4],4,4,4]

    [7,7,7,7]
    [7,7,7]

    []
    [3]

    [[[]]]
    [[]]

    [1,[2,[3,[4,[5,6,7]]]],8,9]
    [1,[2,[3,[4,[5,6,0]]]],8,9]


<span title="The snailfish called. They want their distress signal back.">Packet data consists of lists and integers.</span> Each list starts with `[`, ends with `]`, and contains zero or more comma-separated values (either integers or other lists). Each packet is always a list and appears on its own line.

When comparing two values, the first value is called _left_ and the second value is called _right_. Then:

*   If _both values are integers_, the _lower integer_ should come first. If the left integer is lower than the right integer, the inputs are in the right order. If the left integer is higher than the right integer, the inputs are not in the right order. Otherwise, the inputs are the same integer; continue checking the next part of the input.
*   If _both values are lists_, compare the first value of each list, then the second value, and so on. If the left list runs out of items first, the inputs are in the right order. If the right list runs out of items first, the inputs are not in the right order. If the lists are the same length and no comparison makes a decision about the order, continue checking the next part of the input.
*   If _exactly one value is an integer_, convert the integer to a list which contains that integer as its only value, then retry the comparison. For example, if comparing `[0,0,0]` and `2`, convert the right value to `[2]` (a list containing `2`); the result is then found by instead comparing `[0,0,0]` and `[2]`.

Using these rules, you can determine which of the pairs in the example are in the right order:

    == Pair 1 ==
    - Compare [1,1,3,1,1] vs [1,1,5,1,1]
      - Compare 1 vs 1
      - Compare 1 vs 1
      - Compare 3 vs 5
        - Left side is smaller, so inputs are in the right order

    == Pair 2 ==
    - Compare [[1],[2,3,4]] vs [[1],4]
      - Compare [1] vs [1]
        - Compare 1 vs 1
      - Compare [2,3,4] vs 4
        - Mixed types; convert right to [4] and retry comparison
        - Compare [2,3,4] vs [4]
          - Compare 2 vs 4
            - Left side is smaller, so inputs are in the right order

    == Pair 3 ==
    - Compare [9] vs [[8,7,6]]
      - Compare 9 vs [8,7,6]
        - Mixed types; convert left to [9] and retry comparison
        - Compare [9] vs [8,7,6]
          - Compare 9 vs 8
            - Right side is smaller, so inputs are not in the right order

    == Pair 4 ==
    - Compare [[4,4],4,4] vs [[4,4],4,4,4]
      - Compare [4,4] vs [4,4]
        - Compare 4 vs 4
        - Compare 4 vs 4
      - Compare 4 vs 4
      - Compare 4 vs 4
      - Left side ran out of items, so inputs are in the right order

    == Pair 5 ==
    - Compare [7,7,7,7] vs [7,7,7]
      - Compare 7 vs 7
      - Compare 7 vs 7
      - Compare 7 vs 7
      - Right side ran out of items, so inputs are not in the right order

    == Pair 6 ==
    - Compare [] vs [3]
      - Left side ran out of items, so inputs are in the right order

    == Pair 7 ==
    - Compare [[[]]] vs [[]]
      - Compare [[]] vs []
        - Right side ran out of items, so inputs are not in the right order

    == Pair 8 ==
    - Compare [1,[2,[3,[4,[5,6,7]]]],8,9] vs [1,[2,[3,[4,[5,6,0]]]],8,9]
      - Compare 1 vs 1
      - Compare [2,[3,[4,[5,6,7]]]] vs [2,[3,[4,[5,6,0]]]]
        - Compare 2 vs 2
        - Compare [3,[4,[5,6,7]]] vs [3,[4,[5,6,0]]]
          - Compare 3 vs 3
          - Compare [4,[5,6,7]] vs [4,[5,6,0]]
            - Compare 4 vs 4
            - Compare [5,6,7] vs [5,6,0]
              - Compare 5 vs 5
              - Compare 6 vs 6
              - Compare 7 vs 0
                - Right side is smaller, so inputs are not in the right order


What are the indices of the pairs that are already _in the right order_? (The first pair has index 1, the second pair has index 2, and so on.) In the above example, the pairs in the right order are 1, 2, 4, and 6; the sum of these indices is _`13`_.

Determine which pairs of packets are already in the right order. _What is the sum of the indices of those pairs?_

# Day 14: Regolith Reservoir

[https://adventofcode.com/2022/day/14](https://adventofcode.com/2022/day/14)

## Description

### Part One

The distress signal leads you to a giant waterfall! Actually, hang on - the signal seems like it's coming from the waterfall itself, and that doesn't make any sense. However, you do notice a little path that leads _behind_ the waterfall.

Correction: the distress signal leads you behind a giant waterfall! There seems to be a large cave system here, and the signal definitely leads further inside.

As you begin to make your way deeper underground, you feel the ground rumble for a moment. Sand begins pouring into the cave! If you don't quickly figure out where the sand is going, you could quickly become trapped!

Fortunately, your [familiarity](https://adventofcode.com/2018/day/17) with analyzing the path of falling material will come in handy here. You scan a two-dimensional vertical slice of the cave above you (your puzzle input) and discover that it is mostly _air_ with structures made of _rock_.

Your scan traces the path of each solid rock structure and reports the `x,y` coordinates that form the shape of the path, where `x` represents distance to the right and `y` represents distance down. Each path appears as a single line of text in your scan. After the first point of each path, each point indicates the end of a straight horizontal or vertical line to be drawn from the previous point. For example:

    498,4 -> 498,6 -> 496,6
    503,4 -> 502,4 -> 502,9 -> 494,9


This scan means that there are two paths of rock; the first path consists of two straight lines, and the second path consists of three straight lines. (Specifically, the first path consists of a line of rock from `498,4` through `498,6` and another line of rock from `498,6` through `496,6`.)

The sand is pouring into the cave from point `500,0`.

Drawing rock as `#`, air as `.`, and the source of the sand as `+`, this becomes:


      4     5  5
      9     0  0
      4     0  3
    0 ......+...
    1 ..........
    2 ..........
    3 ..........
    4 ....#...##
    5 ....#...#.
    6 ..###...#.
    7 ........#.
    8 ........#.
    9 #########.


Sand is produced _one unit at a time_, and the next unit of sand is not produced until the previous unit of sand _comes to rest_. A unit of sand is large enough to fill one tile of air in your scan.

A unit of sand always falls _down one step_ if possible. If the tile immediately below is blocked (by rock or sand), the unit of sand attempts to instead move diagonally _one step down and to the left_. If that tile is blocked, the unit of sand attempts to instead move diagonally _one step down and to the right_. Sand keeps moving as long as it is able to do so, at each step trying to move down, then down-left, then down-right. If all three possible destinations are blocked, the unit of sand _comes to rest_ and no longer moves, at which point the next unit of sand is created back at the source.

So, drawing sand that has come to rest as `o`, the first unit of sand simply falls straight down and then stops:

    ......+...
    ..........
    ..........
    ..........
    ....#...##
    ....#...#.
    ..###...#.
    ........#.
    ......o.#.
    #########.


The second unit of sand then falls straight down, lands on the first one, and then comes to rest to its left:

    ......+...
    ..........
    ..........
    ..........
    ....#...##
    ....#...#.
    ..###...#.
    ........#.
    .....oo.#.
    #########.


After a total of five units of sand have come to rest, they form this pattern:

    ......+...
    ..........
    ..........
    ..........
    ....#...##
    ....#...#.
    ..###...#.
    ......o.#.
    ....oooo#.
    #########.


After a total of 22 units of sand:

    ......+...
    ..........
    ......o...
    .....ooo..
    ....#ooo##
    ....#ooo#.
    ..###ooo#.
    ....oooo#.
    ...ooooo#.
    #########.


Finally, only two more units of sand can possibly come to rest:

    ......+...
    ..........
    ......o...
    .....ooo..
    ....#ooo##
    ...o#ooo#.
    ..###ooo#.
    ....oooo#.
    .o.ooooo#.
    #########.


Once all _`24`_ units of sand shown above have come to rest, all further sand flows out the bottom, falling into the endless void. Just for fun, the path any new sand takes before falling forever is shown here with `~`:

    .......+...
    .......~...
    ......~o...
    .....~ooo..
    ....~#ooo##
    ...~o#ooo#.
    ..~###ooo#.
    ..~..oooo#.
    .~o.ooooo#.
    ~#########.
    ~..........
    ~..........
    ~..........


Using your scan, simulate the falling sand. _How many units of sand come to rest before sand starts flowing into the abyss below?_

# Day 15: Beacon Exclusion Zone

[https://adventofcode.com/2022/day/15](https://adventofcode.com/2022/day/15)

## Description

### Part One

You feel the ground rumble again as the distress signal leads you to a large network of subterranean tunnels. You don't have time to search them all, but you don't need to: your pack contains a set of deployable _sensors_ that you imagine were originally built to locate lost Elves.

The sensors aren't very powerful, but that's okay; your handheld device indicates that you're close enough to the source of the distress signal to use them. You pull the emergency sensor system out of your pack, hit the big button on top, and the sensors zoom off down the tunnels.

Once a sensor finds a spot it thinks will give it a good reading, it attaches itself to a hard surface and begins monitoring for the nearest signal source _beacon_. Sensors and beacons always exist at integer coordinates. Each sensor knows its own position and can _determine the position of a beacon precisely_; however, sensors can only lock on to the one beacon _closest to the sensor_ as measured by the [Manhattan distance](https://en.wikipedia.org/wiki/Taxicab_geometry). (There is never a tie where two beacons are the same distance to a sensor.)

It doesn't take long for the sensors to report back their positions and closest beacons (your puzzle input). For example:

    Sensor at x=2, y=18: closest beacon is at x=-2, y=15
    Sensor at x=9, y=16: closest beacon is at x=10, y=16
    Sensor at x=13, y=2: closest beacon is at x=15, y=3
    Sensor at x=12, y=14: closest beacon is at x=10, y=16
    Sensor at x=10, y=20: closest beacon is at x=10, y=16
    Sensor at x=14, y=17: closest beacon is at x=10, y=16
    Sensor at x=8, y=7: closest beacon is at x=2, y=10
    Sensor at x=2, y=0: closest beacon is at x=2, y=10
    Sensor at x=0, y=11: closest beacon is at x=2, y=10
    Sensor at x=20, y=14: closest beacon is at x=25, y=17
    Sensor at x=17, y=20: closest beacon is at x=21, y=22
    Sensor at x=16, y=7: closest beacon is at x=15, y=3
    Sensor at x=14, y=3: closest beacon is at x=15, y=3
    Sensor at x=20, y=1: closest beacon is at x=15, y=3


So, consider the sensor at `2,18`; the closest beacon to it is at `-2,15`. For the sensor at `9,16`, the closest beacon to it is at `10,16`.

Drawing sensors as `S` and beacons as `B`, the above arrangement of sensors and beacons looks like this:

                   1    1    2    2
         0    5    0    5    0    5
     0 ....S.......................
     1 ......................S.....
     2 ...............S............
     3 ................SB..........
     4 ............................
     5 ............................
     6 ............................
     7 ..........S.......S.........
     8 ............................
     9 ............................
    10 ....B.......................
    11 ..S.........................
    12 ............................
    13 ............................
    14 ..............S.......S.....
    15 B...........................
    16 ...........SB...............
    17 ................S..........B
    18 ....S.......................
    19 ............................
    20 ............S......S........
    21 ............................
    22 .......................B....


This isn't necessarily a comprehensive map of all beacons in the area, though. Because each sensor only identifies its closest beacon, if a sensor detects a beacon, you know there are no other beacons that close or closer to that sensor. There could still be beacons that just happen to not be the closest beacon to any sensor. Consider the sensor at `8,7`:

                   1    1    2    2
         0    5    0    5    0    5
    -2 ..........#.................
    -1 .........###................
     0 ....S...#####...............
     1 .......#######........S.....
     2 ......#########S............
     3 .....###########SB..........
     4 ....#############...........
     5 ...###############..........
     6 ..#################.........
     7 .#########S#######S#........
     8 ..#################.........
     9 ...###############..........
    10 ....B############...........
    11 ..S..###########............
    12 ......#########.............
    13 .......#######..............
    14 ........#####.S.......S.....
    15 B........###................
    16 ..........#SB...............
    17 ................S..........B
    18 ....S.......................
    19 ............................
    20 ............S......S........
    21 ............................
    22 .......................B....


This sensor's closest beacon is at `2,10`, and so you know there are no beacons that close or closer (in any positions marked `#`).

None of the detected beacons seem to be producing the distress signal, so you'll need to <span title="&quot;When you have eliminated all which is impossible, then whatever remains, however improbable, must be where the missing beacon is.&quot; - Sherlock Holmes">work out</span> where the distress beacon is by working out where it _isn't_. For now, keep things simple by counting the positions where a beacon cannot possibly be along just a single row.

So, suppose you have an arrangement of beacons and sensors like in the example above and, just in the row where `y=10`, you'd like to count the number of positions a beacon cannot possibly exist. The coverage from all sensors near that row looks like this:

                     1    1    2    2
           0    5    0    5    0    5
     9 ...#########################...
    10 ..####B######################..
    11 .###S#############.###########.


In this example, in the row where `y=10`, there are _`26`_ positions where a beacon cannot be present.

Consult the report from the sensors you just deployed. _In the row where `y=2000000`, how many positions cannot contain a beacon?_

# Day 16: Proboscidea Volcanium

[https://adventofcode.com/2022/day/16](https://adventofcode.com/2022/day/16)

## Description

### Part One

The sensors have led you to the origin of the distress signal: yet another handheld device, just like the one the Elves gave you. However, you don't see any Elves around; instead, the device is surrounded by elephants! They must have gotten lost in these tunnels, and one of the elephants apparently figured out how to turn on the distress signal.

The ground rumbles again, much stronger this time. What kind of cave is this, exactly? You scan the cave with your handheld device; it reports mostly igneous rock, some ash, pockets of pressurized gas, magma... this isn't just a cave, it's a volcano!

You need to get the elephants out of here, quickly. Your device estimates that you have _30 minutes_ before the volcano erupts, so you don't have time to go back out the way you came in.

You scan the cave for other options and discover a network of pipes and pressure-release _valves_. You aren't sure how such a system got into a volcano, but you don't have time to complain; your device produces a report (your puzzle input) of each valve's _flow rate_ if it were opened (in pressure per minute) and the tunnels you could use to move between the valves.

There's even a valve in the room you and the elephants are currently standing in labeled `AA`. You estimate it will take you one minute to open a single valve and one minute to follow any tunnel from one valve to another. What is the most pressure you could release?

For example, suppose you had the following scan output:

    Valve AA has flow rate=0; tunnels lead to valves DD, II, BB
    Valve BB has flow rate=13; tunnels lead to valves CC, AA
    Valve CC has flow rate=2; tunnels lead to valves DD, BB
    Valve DD has flow rate=20; tunnels lead to valves CC, AA, EE
    Valve EE has flow rate=3; tunnels lead to valves FF, DD
    Valve FF has flow rate=0; tunnels lead to valves EE, GG
    Valve GG has flow rate=0; tunnels lead to valves FF, HH
    Valve HH has flow rate=22; tunnel leads to valve GG
    Valve II has flow rate=0; tunnels lead to valves AA, JJ
    Valve JJ has flow rate=21; tunnel leads to valve II


All of the valves begin _closed_. You start at valve `AA`, but it must be damaged or <span title="Wait, sir! The valve, sir! it appears to be... jammed!">jammed</span> or something: its flow rate is `0`, so there's no point in opening it. However, you could spend one minute moving to valve `BB` and another minute opening it; doing so would release pressure during the remaining _28 minutes_ at a flow rate of `13`, a total eventual pressure release of `28 * 13 = 364`. Then, you could spend your third minute moving to valve `CC` and your fourth minute opening it, providing an additional _26 minutes_ of eventual pressure release at a flow rate of `2`, or _`52`_ total pressure released by valve `CC`.

Making your way through the tunnels like this, you could probably open many or all of the valves by the time 30 minutes have elapsed. However, you need to release as much pressure as possible, so you'll need to be methodical. Instead, consider this approach:

    == Minute 1 ==
    No valves are open.
    You move to valve DD.

    == Minute 2 ==
    No valves are open.
    You open valve DD.

    == Minute 3 ==
    Valve DD is open, releasing 20 pressure.
    You move to valve CC.

    == Minute 4 ==
    Valve DD is open, releasing 20 pressure.
    You move to valve BB.

    == Minute 5 ==
    Valve DD is open, releasing 20 pressure.
    You open valve BB.

    == Minute 6 ==
    Valves BB and DD are open, releasing 33 pressure.
    You move to valve AA.

    == Minute 7 ==
    Valves BB and DD are open, releasing 33 pressure.
    You move to valve II.

    == Minute 8 ==
    Valves BB and DD are open, releasing 33 pressure.
    You move to valve JJ.

    == Minute 9 ==
    Valves BB and DD are open, releasing 33 pressure.
    You open valve JJ.

    == Minute 10 ==
    Valves BB, DD, and JJ are open, releasing 54 pressure.
    You move to valve II.

    == Minute 11 ==
    Valves BB, DD, and JJ are open, releasing 54 pressure.
    You move to valve AA.

    == Minute 12 ==
    Valves BB, DD, and JJ are open, releasing 54 pressure.
    You move to valve DD.

    == Minute 13 ==
    Valves BB, DD, and JJ are open, releasing 54 pressure.
    You move to valve EE.

    == Minute 14 ==
    Valves BB, DD, and JJ are open, releasing 54 pressure.
    You move to valve FF.

    == Minute 15 ==
    Valves BB, DD, and JJ are open, releasing 54 pressure.
    You move to valve GG.

    == Minute 16 ==
    Valves BB, DD, and JJ are open, releasing 54 pressure.
    You move to valve HH.

    == Minute 17 ==
    Valves BB, DD, and JJ are open, releasing 54 pressure.
    You open valve HH.

    == Minute 18 ==
    Valves BB, DD, HH, and JJ are open, releasing 76 pressure.
    You move to valve GG.

    == Minute 19 ==
    Valves BB, DD, HH, and JJ are open, releasing 76 pressure.
    You move to valve FF.

    == Minute 20 ==
    Valves BB, DD, HH, and JJ are open, releasing 76 pressure.
    You move to valve EE.

    == Minute 21 ==
    Valves BB, DD, HH, and JJ are open, releasing 76 pressure.
    You open valve EE.

    == Minute 22 ==
    Valves BB, DD, EE, HH, and JJ are open, releasing 79 pressure.
    You move to valve DD.

    == Minute 23 ==
    Valves BB, DD, EE, HH, and JJ are open, releasing 79 pressure.
    You move to valve CC.

    == Minute 24 ==
    Valves BB, DD, EE, HH, and JJ are open, releasing 79 pressure.
    You open valve CC.

    == Minute 25 ==
    Valves BB, CC, DD, EE, HH, and JJ are open, releasing 81 pressure.

    == Minute 26 ==
    Valves BB, CC, DD, EE, HH, and JJ are open, releasing 81 pressure.

    == Minute 27 ==
    Valves BB, CC, DD, EE, HH, and JJ are open, releasing 81 pressure.

    == Minute 28 ==
    Valves BB, CC, DD, EE, HH, and JJ are open, releasing 81 pressure.

    == Minute 29 ==
    Valves BB, CC, DD, EE, HH, and JJ are open, releasing 81 pressure.

    == Minute 30 ==
    Valves BB, CC, DD, EE, HH, and JJ are open, releasing 81 pressure.


This approach lets you release the most pressure possible in 30 minutes with this valve layout, _`1651`_.

Work out the steps to release the most pressure in 30 minutes. _What is the most pressure you can release?_

# Day 17: Pyroclastic Flow

[https://adventofcode.com/2022/day/17](https://adventofcode.com/2022/day/17)

## Description

### Part One

Your handheld device has located an alternative exit from the cave for you and the elephants. The ground is rumbling almost continuously now, but the strange valves bought you some time. It's definitely getting warmer in here, though.

The tunnels eventually open into a very tall, narrow chamber. Large, oddly-shaped rocks are falling into the chamber from above, presumably due to all the rumbling. If you can't work out where the rocks will fall next, you might be <span title="I am the man who arranges the blocks / that descend upon me from up above!">crushed</span>!

The five types of rocks have the following peculiar shapes, where `#` is rock and `.` is empty space:

    ####

    .#.
    ###
    .#.

    ..#
    ..#
    ###

    #
    #
    #
    #

    ##
    ##


The rocks fall in the order shown above: first the `-` shape, then the `+` shape, and so on. Once the end of the list is reached, the same order repeats: the `-` shape falls first, sixth, 11th, 16th, etc.

The rocks don't spin, but they do get pushed around by jets of hot gas coming out of the walls themselves. A quick scan reveals the effect the jets of hot gas will have on the rocks as they fall (your puzzle input).

For example, suppose this was the jet pattern in your cave:

    >>><<><>><<<>><>>><<<>>><<<><<<>><>><<>>


In jet patterns, `<` means a push to the left, while `>` means a push to the right. The pattern above means that the jets will push a falling rock right, then right, then right, then left, then left, then right, and so on. If the end of the list is reached, it repeats.

The tall, vertical chamber is exactly _seven units wide_. Each rock appears so that its left edge is two units away from the left wall and its bottom edge is three units above the highest rock in the room (or the floor, if there isn't one).

After a rock appears, it alternates between _being pushed by a jet of hot gas_ one unit (in the direction indicated by the next symbol in the jet pattern) and then _falling one unit down_. If any movement would cause any part of the rock to move into the walls, floor, or a stopped rock, the movement instead does not occur. If a _downward_ movement would have caused a falling rock to move into the floor or an already-fallen rock, the falling rock stops where it is (having landed on something) and a new rock immediately begins falling.

Drawing falling rocks with `@` and stopped rocks with `#`, the jet pattern in the example above manifests as follows:

    The first rock begins falling:
    |..@@@@.|
    |.......|
    |.......|
    |.......|
    +-------+

    Jet of gas pushes rock right:
    |...@@@@|
    |.......|
    |.......|
    |.......|
    +-------+

    Rock falls 1 unit:
    |...@@@@|
    |.......|
    |.......|
    +-------+

    Jet of gas pushes rock right, but nothing happens:
    |...@@@@|
    |.......|
    |.......|
    +-------+

    Rock falls 1 unit:
    |...@@@@|
    |.......|
    +-------+

    Jet of gas pushes rock right, but nothing happens:
    |...@@@@|
    |.......|
    +-------+

    Rock falls 1 unit:
    |...@@@@|
    +-------+

    Jet of gas pushes rock left:
    |..@@@@.|
    +-------+

    Rock falls 1 unit, causing it to come to rest:
    |..####.|
    +-------+

    A new rock begins falling:
    |...@...|
    |..@@@..|
    |...@...|
    |.......|
    |.......|
    |.......|
    |..####.|
    +-------+

    Jet of gas pushes rock left:
    |..@....|
    |.@@@...|
    |..@....|
    |.......|
    |.......|
    |.......|
    |..####.|
    +-------+

    Rock falls 1 unit:
    |..@....|
    |.@@@...|
    |..@....|
    |.......|
    |.......|
    |..####.|
    +-------+

    Jet of gas pushes rock right:
    |...@...|
    |..@@@..|
    |...@...|
    |.......|
    |.......|
    |..####.|
    +-------+

    Rock falls 1 unit:
    |...@...|
    |..@@@..|
    |...@...|
    |.......|
    |..####.|
    +-------+

    Jet of gas pushes rock left:
    |..@....|
    |.@@@...|
    |..@....|
    |.......|
    |..####.|
    +-------+

    Rock falls 1 unit:
    |..@....|
    |.@@@...|
    |..@....|
    |..####.|
    +-------+

    Jet of gas pushes rock right:
    |...@...|
    |..@@@..|
    |...@...|
    |..####.|
    +-------+

    Rock falls 1 unit, causing it to come to rest:
    |...#...|
    |..###..|
    |...#...|
    |..####.|
    +-------+

    A new rock begins falling:
    |....@..|
    |....@..|
    |..@@@..|
    |.......|
    |.......|
    |.......|
    |...#...|
    |..###..|
    |...#...|
    |..####.|
    +-------+


The moment each of the next few rocks begins falling, you would see this:

    |..@....|
    |..@....|
    |..@....|
    |..@....|
    |.......|
    |.......|
    |.......|
    |..#....|
    |..#....|
    |####...|
    |..###..|
    |...#...|
    |..####.|
    +-------+

    |..@@...|
    |..@@...|
    |.......|
    |.......|
    |.......|
    |....#..|
    |..#.#..|
    |..#.#..|
    |#####..|
    |..###..|
    |...#...|
    |..####.|
    +-------+

    |..@@@@.|
    |.......|
    |.......|
    |.......|
    |....##.|
    |....##.|
    |....#..|
    |..#.#..|
    |..#.#..|
    |#####..|
    |..###..|
    |...#...|
    |..####.|
    +-------+

    |...@...|
    |..@@@..|
    |...@...|
    |.......|
    |.......|
    |.......|
    |.####..|
    |....##.|
    |....##.|
    |....#..|
    |..#.#..|
    |..#.#..|
    |#####..|
    |..###..|
    |...#...|
    |..####.|
    +-------+

    |....@..|
    |....@..|
    |..@@@..|
    |.......|
    |.......|
    |.......|
    |..#....|
    |.###...|
    |..#....|
    |.####..|
    |....##.|
    |....##.|
    |....#..|
    |..#.#..|
    |..#.#..|
    |#####..|
    |..###..|
    |...#...|
    |..####.|
    +-------+

    |..@....|
    |..@....|
    |..@....|
    |..@....|
    |.......|
    |.......|
    |.......|
    |.....#.|
    |.....#.|
    |..####.|
    |.###...|
    |..#....|
    |.####..|
    |....##.|
    |....##.|
    |....#..|
    |..#.#..|
    |..#.#..|
    |#####..|
    |..###..|
    |...#...|
    |..####.|
    +-------+

    |..@@...|
    |..@@...|
    |.......|
    |.......|
    |.......|
    |....#..|
    |....#..|
    |....##.|
    |....##.|
    |..####.|
    |.###...|
    |..#....|
    |.####..|
    |....##.|
    |....##.|
    |....#..|
    |..#.#..|
    |..#.#..|
    |#####..|
    |..###..|
    |...#...|
    |..####.|
    +-------+

    |..@@@@.|
    |.......|
    |.......|
    |.......|
    |....#..|
    |....#..|
    |....##.|
    |##..##.|
    |######.|
    |.###...|
    |..#....|
    |.####..|
    |....##.|
    |....##.|
    |....#..|
    |..#.#..|
    |..#.#..|
    |#####..|
    |..###..|
    |...#...|
    |..####.|
    +-------+


To prove to the elephants your simulation is accurate, they want to know how tall the tower will get after 2022 rocks have stopped (but before the 2023rd rock begins falling). In this example, the tower of rocks will be _`3068`_ units tall.

_How many units tall will the tower of rocks be after 2022 rocks have stopped falling?_

# Day 18: Boiling Boulders

[https://adventofcode.com/2022/day/18](https://adventofcode.com/2022/day/18)

## Description

### Part One

You and the elephants finally reach fresh air. You've emerged near the base of a large volcano that seems to be actively erupting! Fortunately, the lava seems to be flowing away from you and toward the ocean.

Bits of lava are still being ejected toward you, so you're sheltering in the cavern exit a little longer. Outside the cave, you can see the lava landing in a pond and hear it loudly hissing as it solidifies.

Depending on the specific compounds in the lava and speed at which it cools, it might be forming [obsidian](https://en.wikipedia.org/wiki/Obsidian)! The cooling rate should be based on the surface area of the lava droplets, so you take a quick scan of a droplet as it flies past you (your puzzle input).

Because of how quickly the lava is moving, the scan isn't very good; its resolution is quite low and, as a result, it approximates the shape of the lava droplet with _1x1x1 <span title="Unfortunately, you forgot your flint and steel in another dimension.">cubes</span> on a 3D grid_, each given as its `x,y,z` position.

To approximate the surface area, count the number of sides of each cube that are not immediately connected to another cube. So, if your scan were only two adjacent cubes like `1,1,1` and `2,1,1`, each cube would have a single side covered and five sides exposed, a total surface area of _`10`_ sides.

Here's a larger example:

    2,2,2
    1,2,2
    3,2,2
    2,1,2
    2,3,2
    2,2,1
    2,2,3
    2,2,4
    2,2,6
    1,2,5
    3,2,5
    2,1,5
    2,3,5


In the above example, after counting up all the sides that aren't connected to another cube, the total surface area is _`64`_.

_What is the surface area of your scanned lava droplet?_

# Day 19: Not Enough Minerals

[https://adventofcode.com/2022/day/19](https://adventofcode.com/2022/day/19)

## Description

### Part One

Your scans show that the lava did indeed form obsidian!

The wind has changed direction enough to stop sending lava droplets toward you, so you and the elephants exit the cave. As you do, you notice a collection of [geodes](https://en.wikipedia.org/wiki/Geode) around the pond. Perhaps you could use the obsidian to create some _geode-cracking robots_ and break them open?

To collect the obsidian from the bottom of the pond, you'll need waterproof _obsidian-collecting robots_. Fortunately, there is an abundant amount of clay nearby that you can use to make them waterproof.

In order to harvest the clay, you'll need special-purpose _clay-collecting robots_. To make any type of robot, you'll need _ore_, which is also plentiful but in the opposite direction from the clay.

Collecting ore requires _ore-collecting robots_ with big drills. Fortunately, _you have exactly one ore-collecting robot_ in your pack that you can use to <span title="If You Give A Mouse An Ore-Collecting Robot">kickstart</span> the whole operation.

Each robot can collect 1 of its resource type per minute. It also takes one minute for the robot factory (also conveniently from your pack) to construct any type of robot, although it consumes the necessary resources available when construction begins.

The robot factory has many _blueprints_ (your puzzle input) you can choose from, but once you've configured it with a blueprint, you can't change it. You'll need to work out which blueprint is best.

For example:

    Blueprint 1:
      Each ore robot costs 4 ore.
      Each clay robot costs 2 ore.
      Each obsidian robot costs 3 ore and 14 clay.
      Each geode robot costs 2 ore and 7 obsidian.

    Blueprint 2:
      Each ore robot costs 2 ore.
      Each clay robot costs 3 ore.
      Each obsidian robot costs 3 ore and 8 clay.
      Each geode robot costs 3 ore and 12 obsidian.


(Blueprints have been line-wrapped here for legibility. The robot factory's actual assortment of blueprints are provided one blueprint per line.)

The elephants are starting to look hungry, so you shouldn't take too long; you need to figure out which blueprint would maximize the number of opened geodes after _24 minutes_ by figuring out which robots to build and when to build them.

Using blueprint 1 in the example above, the largest number of geodes you could open in 24 minutes is _`9`_. One way to achieve that is:

    == Minute 1 ==
    1 ore-collecting robot collects 1 ore; you now have 1 ore.

    == Minute 2 ==
    1 ore-collecting robot collects 1 ore; you now have 2 ore.

    == Minute 3 ==
    Spend 2 ore to start building a clay-collecting robot.
    1 ore-collecting robot collects 1 ore; you now have 1 ore.
    The new clay-collecting robot is ready; you now have 1 of them.

    == Minute 4 ==
    1 ore-collecting robot collects 1 ore; you now have 2 ore.
    1 clay-collecting robot collects 1 clay; you now have 1 clay.

    == Minute 5 ==
    Spend 2 ore to start building a clay-collecting robot.
    1 ore-collecting robot collects 1 ore; you now have 1 ore.
    1 clay-collecting robot collects 1 clay; you now have 2 clay.
    The new clay-collecting robot is ready; you now have 2 of them.

    == Minute 6 ==
    1 ore-collecting robot collects 1 ore; you now have 2 ore.
    2 clay-collecting robots collect 2 clay; you now have 4 clay.

    == Minute 7 ==
    Spend 2 ore to start building a clay-collecting robot.
    1 ore-collecting robot collects 1 ore; you now have 1 ore.
    2 clay-collecting robots collect 2 clay; you now have 6 clay.
    The new clay-collecting robot is ready; you now have 3 of them.

    == Minute 8 ==
    1 ore-collecting robot collects 1 ore; you now have 2 ore.
    3 clay-collecting robots collect 3 clay; you now have 9 clay.

    == Minute 9 ==
    1 ore-collecting robot collects 1 ore; you now have 3 ore.
    3 clay-collecting robots collect 3 clay; you now have 12 clay.

    == Minute 10 ==
    1 ore-collecting robot collects 1 ore; you now have 4 ore.
    3 clay-collecting robots collect 3 clay; you now have 15 clay.

    == Minute 11 ==
    Spend 3 ore and 14 clay to start building an obsidian-collecting robot.
    1 ore-collecting robot collects 1 ore; you now have 2 ore.
    3 clay-collecting robots collect 3 clay; you now have 4 clay.
    The new obsidian-collecting robot is ready; you now have 1 of them.

    == Minute 12 ==
    Spend 2 ore to start building a clay-collecting robot.
    1 ore-collecting robot collects 1 ore; you now have 1 ore.
    3 clay-collecting robots collect 3 clay; you now have 7 clay.
    1 obsidian-collecting robot collects 1 obsidian; you now have 1 obsidian.
    The new clay-collecting robot is ready; you now have 4 of them.

    == Minute 13 ==
    1 ore-collecting robot collects 1 ore; you now have 2 ore.
    4 clay-collecting robots collect 4 clay; you now have 11 clay.
    1 obsidian-collecting robot collects 1 obsidian; you now have 2 obsidian.

    == Minute 14 ==
    1 ore-collecting robot collects 1 ore; you now have 3 ore.
    4 clay-collecting robots collect 4 clay; you now have 15 clay.
    1 obsidian-collecting robot collects 1 obsidian; you now have 3 obsidian.

    == Minute 15 ==
    Spend 3 ore and 14 clay to start building an obsidian-collecting robot.
    1 ore-collecting robot collects 1 ore; you now have 1 ore.
    4 clay-collecting robots collect 4 clay; you now have 5 clay.
    1 obsidian-collecting robot collects 1 obsidian; you now have 4 obsidian.
    The new obsidian-collecting robot is ready; you now have 2 of them.

    == Minute 16 ==
    1 ore-collecting robot collects 1 ore; you now have 2 ore.
    4 clay-collecting robots collect 4 clay; you now have 9 clay.
    2 obsidian-collecting robots collect 2 obsidian; you now have 6 obsidian.

    == Minute 17 ==
    1 ore-collecting robot collects 1 ore; you now have 3 ore.
    4 clay-collecting robots collect 4 clay; you now have 13 clay.
    2 obsidian-collecting robots collect 2 obsidian; you now have 8 obsidian.

    == Minute 18 ==
    Spend 2 ore and 7 obsidian to start building a geode-cracking robot.
    1 ore-collecting robot collects 1 ore; you now have 2 ore.
    4 clay-collecting robots collect 4 clay; you now have 17 clay.
    2 obsidian-collecting robots collect 2 obsidian; you now have 3 obsidian.
    The new geode-cracking robot is ready; you now have 1 of them.

    == Minute 19 ==
    1 ore-collecting robot collects 1 ore; you now have 3 ore.
    4 clay-collecting robots collect 4 clay; you now have 21 clay.
    2 obsidian-collecting robots collect 2 obsidian; you now have 5 obsidian.
    1 geode-cracking robot cracks 1 geode; you now have 1 open geode.

    == Minute 20 ==
    1 ore-collecting robot collects 1 ore; you now have 4 ore.
    4 clay-collecting robots collect 4 clay; you now have 25 clay.
    2 obsidian-collecting robots collect 2 obsidian; you now have 7 obsidian.
    1 geode-cracking robot cracks 1 geode; you now have 2 open geodes.

    == Minute 21 ==
    Spend 2 ore and 7 obsidian to start building a geode-cracking robot.
    1 ore-collecting robot collects 1 ore; you now have 3 ore.
    4 clay-collecting robots collect 4 clay; you now have 29 clay.
    2 obsidian-collecting robots collect 2 obsidian; you now have 2 obsidian.
    1 geode-cracking robot cracks 1 geode; you now have 3 open geodes.
    The new geode-cracking robot is ready; you now have 2 of them.

    == Minute 22 ==
    1 ore-collecting robot collects 1 ore; you now have 4 ore.
    4 clay-collecting robots collect 4 clay; you now have 33 clay.
    2 obsidian-collecting robots collect 2 obsidian; you now have 4 obsidian.
    2 geode-cracking robots crack 2 geodes; you now have 5 open geodes.

    == Minute 23 ==
    1 ore-collecting robot collects 1 ore; you now have 5 ore.
    4 clay-collecting robots collect 4 clay; you now have 37 clay.
    2 obsidian-collecting robots collect 2 obsidian; you now have 6 obsidian.
    2 geode-cracking robots crack 2 geodes; you now have 7 open geodes.

    == Minute 24 ==
    1 ore-collecting robot collects 1 ore; you now have 6 ore.
    4 clay-collecting robots collect 4 clay; you now have 41 clay.
    2 obsidian-collecting robots collect 2 obsidian; you now have 8 obsidian.
    2 geode-cracking robots crack 2 geodes; you now have 9 open geodes.


However, by using blueprint 2 in the example above, you could do even better: the largest number of geodes you could open in 24 minutes is _`12`_.

Determine the _quality level_ of each blueprint by _multiplying that blueprint's ID number_ with the largest number of geodes that can be opened in 24 minutes using that blueprint. In this example, the first blueprint has ID 1 and can open 9 geodes, so its quality level is _`9`_. The second blueprint has ID 2 and can open 12 geodes, so its quality level is _`24`_. Finally, if you _add up the quality levels_ of all of the blueprints in the list, you get _`33`_.

Determine the quality level of each blueprint using the largest number of geodes it could produce in 24 minutes. _What do you get if you add up the quality level of all of the blueprints in your list?_

# Day 20: Grove Positioning System

[https://adventofcode.com/2022/day/20](https://adventofcode.com/2022/day/20)

## Description

### Part One

It's finally time to meet back up with the Elves. When you try to contact them, however, you get no reply. Perhaps you're out of range?

You know they're headed to the grove where the _star_ fruit grows, so if you can figure out where that is, you should be able to meet back up with them.

Fortunately, your handheld device has a file (your puzzle input) that contains the grove's coordinates! Unfortunately, the file is _encrypted_ - just in case the device were to fall into the wrong hands.

Maybe you can <span title="You once again make a mental note to remind the Elves later not to invent their own cryptographic functions.">decrypt</span> it?

When you were still back at the camp, you overheard some Elves talking about coordinate file encryption. The main operation involved in decrypting the file is called _mixing_.

The encrypted file is a list of numbers. To _mix_ the file, move each number forward or backward in the file a number of positions equal to the value of the number being moved. The list is _circular_, so moving a number off one end of the list wraps back around to the other end as if the ends were connected.

For example, to move the `1` in a sequence like `4, 5, 6, 1, 7, 8, 9`, the `1` moves one position forward: `4, 5, 6, 7, 1, 8, 9`. To move the `-2` in a sequence like `4, -2, 5, 6, 7, 8, 9`, the `-2` moves two positions backward, wrapping around: `4, 5, 6, 7, 8, -2, 9`.

The numbers should be moved _in the order they originally appear_ in the encrypted file. Numbers moving around during the mixing process do not change the order in which the numbers are moved.

Consider this encrypted file:

    1
    2
    -3
    3
    -2
    0
    4


Mixing this file proceeds as follows:

    Initial arrangement:
    1, 2, -3, 3, -2, 0, 4

    1 moves between 2 and -3:
    2, 1, -3, 3, -2, 0, 4

    2 moves between -3 and 3:
    1, -3, 2, 3, -2, 0, 4

    -3 moves between -2 and 0:
    1, 2, 3, -2, -3, 0, 4

    3 moves between 0 and 4:
    1, 2, -2, -3, 0, 3, 4

    -2 moves between 4 and 1:
    1, 2, -3, 0, 3, 4, -2

    0 does not move:
    1, 2, -3, 0, 3, 4, -2

    4 moves between -3 and 0:
    1, 2, -3, 4, 0, 3, -2


Then, the grove coordinates can be found by looking at the 1000th, 2000th, and 3000th numbers after the value `0`, wrapping around the list as necessary. In the above example, the 1000th number after `0` is _`4`_, the 2000th is _`-3`_, and the 3000th is _`2`_; adding these together produces _`3`_.

Mix your encrypted file exactly once. _What is the sum of the three numbers that form the grove coordinates?_

# Day 21: Monkey Math

[https://adventofcode.com/2022/day/21](https://adventofcode.com/2022/day/21)

## Description

### Part One

The [monkeys](https://adventofcode.com/2022/day/11) are back! You're worried they're going to try to steal your stuff again, but it seems like they're just holding their ground and making various monkey noises at you.

Eventually, one of the elephants realizes you don't speak monkey and comes over to interpret. As it turns out, they overheard you talking about trying to find the grove; they can show you a shortcut if you answer their _riddle_.

Each monkey is given a _job_: either to _yell a specific number_ or to _yell the result of a math operation_. All of the number-yelling monkeys know their number from the start; however, the math operation monkeys need to wait for two other monkeys to yell a number, and those two other monkeys might _also_ be waiting on other monkeys.

Your job is to _work out the number the monkey named `root` will yell_ before the monkeys figure it out themselves.

For example:

    root: pppw + sjmn
    dbpl: 5
    cczh: sllz + lgvd
    zczc: 2
    ptdq: humn - dvpt
    dvpt: 3
    lfqf: 4
    humn: 5
    ljgn: 2
    sjmn: drzm * dbpl
    sllz: 4
    pppw: cczh / lfqf
    lgvd: ljgn * ptdq
    drzm: hmdt - zczc
    hmdt: 32


Each line contains the name of a monkey, a colon, and then the job of that monkey:

*   A lone number means the monkey's job is simply to yell that number.
*   A job like `aaaa + bbbb` means the monkey waits for monkeys `aaaa` and `bbbb` to yell each of their numbers; the monkey then yells the sum of those two numbers.
*   `aaaa - bbbb` means the monkey yells `aaaa`'s number minus `bbbb`'s number.
*   Job `aaaa * bbbb` will yell `aaaa`'s number multiplied by `bbbb`'s number.
*   Job `aaaa / bbbb` will yell `aaaa`'s number divided by `bbbb`'s number.

So, in the above example, monkey `drzm` has to wait for monkeys `hmdt` and `zczc` to yell their numbers. Fortunately, both `hmdt` and `zczc` have jobs that involve simply yelling a single number, so they do this immediately: `32` and `2`. Monkey `drzm` can then yell its number by finding `32` minus `2`: _`30`_.

Then, monkey `sjmn` has one of its numbers (`30`, from monkey `drzm`), and already has its other number, `5`, from `dbpl`. This allows it to yell its own number by finding `30` multiplied by `5`: _`150`_.

This process continues until `root` yells a number: _`152`_.

However, your actual situation involves <span title="Advent of Code 2022: Now With Considerably More Monkeys">considerably more monkeys</span>. _What number will the monkey named `root` yell?_

# Day 22: Monkey Map

[https://adventofcode.com/2022/day/22](https://adventofcode.com/2022/day/22)

## Description

### Part One

The monkeys take you on a surprisingly easy trail through the jungle. They're even going in roughly the right direction according to your handheld device's Grove Positioning System.

As you walk, the monkeys explain that the grove is protected by a _force field_. To pass through the force field, you have to enter a password; doing so involves tracing a specific _path_ on a strangely-shaped board.

At least, you're pretty sure that's what you have to do; the elephants aren't exactly fluent in monkey.

The monkeys give you notes that they took when they last saw the password entered (your puzzle input).

For example:

            ...#
            .#..
            #...
            ....
    ...#.......#
    ........#...
    ..#....#....
    ..........#.
            ...#....
            .....#..
            .#......
            ......#.

    10R5L5R10L4R5L5


The first half of the monkeys' notes is a _map of the board_. It is comprised of a set of _open tiles_ (on which you can move, drawn `.`) and _solid walls_ (tiles which you cannot enter, drawn `#`).

The second half is a description of _the path you must follow_. It consists of alternating numbers and letters:

*   A _number_ indicates the _number of tiles to move_ in the direction you are facing. If you run into a wall, you stop moving forward and continue with the next instruction.
*   A _letter_ indicates whether to turn 90 degrees _clockwise_ (`R`) or _<span title="Or &quot;anticlockwise&quot;, if you're anti-counterclockwise.">counterclockwise</span>_ (`L`). Turning happens in-place; it does not change your current tile.

So, a path like `10R5` means "go forward 10 tiles, then turn clockwise 90 degrees, then go forward 5 tiles".

You begin the path in the leftmost open tile of the top row of tiles. Initially, you are facing _to the right_ (from the perspective of how the map is drawn).

If a movement instruction would take you off of the map, you _wrap around_ to the other side of the board. In other words, if your next tile is off of the board, you should instead look in the direction opposite of your current facing as far as you can until you find the opposite edge of the board, then reappear there.

For example, if you are at `A` and facing to the right, the tile in front of you is marked `B`; if you are at `C` and facing down, the tile in front of you is marked `D`:

            ...#
            .#..
            #...
            ....
    ...#.D.....#
    ........#...
    B.#....#...A
    .....C....#.
            ...#....
            .....#..
            .#......
            ......#.


It is possible for the next tile (after wrapping around) to be a _wall_; this still counts as there being a wall in front of you, and so movement stops before you actually wrap to the other side of the board.

By drawing the _last facing you had_ with an arrow on each tile you visit, the full path taken by the above example looks like this:

            >>v#
            .#v.
            #.v.
            ..v.
    ...#...v..v#
    >>>v...>#.>>
    ..#v...#....
    ...>>>>v..#.
            ...#....
            .....#..
            .#......
            ......#.


To finish providing the password to this strange input device, you need to determine numbers for your final _row_, _column_, and _facing_ as your final position appears from the perspective of the original map. Rows start from `1` at the top and count downward; columns start from `1` at the left and count rightward. (In the above example, row 1, column 1 refers to the empty space with no tile on it in the top-left corner.) Facing is `0` for right (`>`), `1` for down (`v`), `2` for left (`<`), and `3` for up (`^`). The _final password_ is the sum of 1000 times the row, 4 times the column, and the facing.

In the above example, the final row is `6`, the final column is `8`, and the final facing is `0`. So, the final password is 1000 \* 6 + 4 \* 8 + 0: _`6032`_.

Follow the path given in the monkeys' notes. _What is the final password?_

# Day 23: Unstable Diffusion

[https://adventofcode.com/2022/day/23](https://adventofcode.com/2022/day/23)

## Description

### Part One

You enter a large crater of gray dirt where the grove is supposed to be. All around you, plants you imagine were expected to be full of fruit are instead withered and broken. A large group of Elves has formed in the middle of the grove.

"...but this volcano has been dormant for months. Without ash, the fruit can't grow!"

You look up to see a massive, snow-capped mountain towering above you.

"It's not like there are other active volcanoes here; we've looked everywhere."

"But our scanners show active magma flows; clearly it's going _somewhere_."

They finally notice you at the edge of the grove, your pack almost overflowing from the random _star_ fruit you've been collecting. Behind you, elephants and monkeys explore the grove, looking concerned. Then, the Elves recognize the ash cloud slowly spreading above your recent detour.

"Why do you--" "How is--" "Did you just--"

Before any of them can form a complete question, another Elf speaks up: "Okay, new plan. We have almost enough fruit already, and ash from the plume should spread here eventually. If we quickly plant new seedlings now, we can still make it to the extraction point. Spread out!"

The Elves each reach into their pack and pull out a tiny plant. The plants rely on important nutrients from the ash, so they can't be planted too close together.

There isn't enough time to let the Elves figure out where to plant the seedlings themselves; you quickly scan the grove (your puzzle input) and note their positions.

For example:

    ....#..
    ..###.#
    #...#.#
    .#...##
    #.###..
    ##.#.##
    .#..#..


The scan shows Elves `#` and empty ground `.`; outside your scan, more empty ground extends a long way in every direction. The scan is oriented so that _north is up_; orthogonal directions are written N (north), S (south), W (west), and E (east), while diagonal directions are written NE, NW, SE, SW.

The Elves follow a time-consuming process to figure out where they should each go; you can speed up this process considerably. The process consists of some number of _rounds_ during which Elves alternate between considering where to move and actually moving.

During the _first half_ of each round, each Elf considers the eight positions adjacent to themself. If no other Elves are in one of those eight positions, the Elf _does not do anything_ during this round. Otherwise, the Elf looks in each of four directions in the following order and _proposes_ moving one step in the _first valid direction_:

*   If there is no Elf in the N, NE, or NW adjacent positions, the Elf proposes moving _north_ one step.
*   If there is no Elf in the S, SE, or SW adjacent positions, the Elf proposes moving _south_ one step.
*   If there is no Elf in the W, NW, or SW adjacent positions, the Elf proposes moving _west_ one step.
*   If there is no Elf in the E, NE, or SE adjacent positions, the Elf proposes moving _east_ one step.

After each Elf has had a chance to propose a move, the _second half_ of the round can begin. Simultaneously, each Elf moves to their proposed destination tile if they were the _only_ Elf to propose moving to that position. If two or more Elves propose moving to the same position, _none_ of those Elves move.

Finally, at the end of the round, the _first direction_ the Elves considered is moved to the end of the list of directions. For example, during the second round, the Elves would try proposing a move to the south first, then west, then east, then north. On the third round, the Elves would first consider west, then east, then north, then south.

As a smaller example, consider just these five Elves:

    .....
    ..##.
    ..#..
    .....
    ..##.
    .....


The northernmost two Elves and southernmost two Elves all propose moving north, while the middle Elf cannot move north and proposes moving south. The middle Elf proposes the same destination as the southwest Elf, so neither of them move, but the other three do:

    ..##.
    .....
    ..#..
    ...#.
    ..#..
    .....


Next, the northernmost two Elves and the southernmost Elf all propose moving south. Of the remaining middle two Elves, the west one cannot move south and proposes moving west, while the east one cannot move south _or_ west and proposes moving east. All five Elves succeed in moving to their proposed positions:

    .....
    ..##.
    .#...
    ....#
    .....
    ..#..


Finally, the southernmost two Elves choose not to move at all. Of the remaining three Elves, the west one proposes moving west, the east one proposes moving east, and the middle one proposes moving north; all three succeed in moving:

    ..#..
    ....#
    #....
    ....#
    .....
    ..#..


At this point, no Elves need to move, and so the process ends.

The larger example above proceeds as follows:

    == Initial State ==
    ..............
    ..............
    .......#......
    .....###.#....
    ...#...#.#....
    ....#...##....
    ...#.###......
    ...##.#.##....
    ....#..#......
    ..............
    ..............
    ..............

    == End of Round 1 ==
    ..............
    .......#......
    .....#...#....
    ...#..#.#.....
    .......#..#...
    ....#.#.##....
    ..#..#.#......
    ..#.#.#.##....
    ..............
    ....#..#......
    ..............
    ..............

    == End of Round 2 ==
    ..............
    .......#......
    ....#.....#...
    ...#..#.#.....
    .......#...#..
    ...#..#.#.....
    .#...#.#.#....
    ..............
    ..#.#.#.##....
    ....#..#......
    ..............
    ..............

    == End of Round 3 ==
    ..............
    .......#......
    .....#....#...
    ..#..#...#....
    .......#...#..
    ...#..#.#.....
    .#..#.....#...
    .......##.....
    ..##.#....#...
    ...#..........
    .......#......
    ..............

    == End of Round 4 ==
    ..............
    .......#......
    ......#....#..
    ..#...##......
    ...#.....#.#..
    .........#....
    .#...###..#...
    ..#......#....
    ....##....#...
    ....#.........
    .......#......
    ..............

    == End of Round 5 ==
    .......#......
    ..............
    ..#..#.....#..
    .........#....
    ......##...#..
    .#.#.####.....
    ...........#..
    ....##..#.....
    ..#...........
    ..........#...
    ....#..#......
    ..............


After a few more rounds...

    == End of Round 10 ==
    .......#......
    ...........#..
    ..#.#..#......
    ......#.......
    ...#.....#..#.
    .#......##....
    .....##.......
    ..#........#..
    ....#.#..#....
    ..............
    ....#..#..#...
    ..............


To make sure they're on the right track, the Elves like to check after round 10 that they're making good progress toward covering enough ground. To do this, count the number of empty ground tiles contained by the smallest rectangle that contains every Elf. (The edges of the rectangle should be aligned to the N/S/E/W directions; the Elves do not have the patience to calculate <span title="Arbitrary Rectangles is my Piet Mondrian cover band.">arbitrary rectangles</span>.) In the above example, that rectangle is:

    ......#.....
    ..........#.
    .#.#..#.....
    .....#......
    ..#.....#..#
    #......##...
    ....##......
    .#........#.
    ...#.#..#...
    ............
    ...#..#..#..


In this region, the number of empty ground tiles is _`110`_.

Simulate the Elves' process and find the smallest rectangle that contains the Elves after 10 rounds. _How many empty ground tiles does that rectangle contain?_

# Day 24: Blizzard Basin

[https://adventofcode.com/2022/day/24](https://adventofcode.com/2022/day/24)

## Description

### Part One

With everything replanted for next year (and with elephants and monkeys to tend the grove), you and the Elves leave for the extraction point.

Partway up the mountain that shields the grove is a flat, open area that serves as the extraction point. It's a bit of a climb, but nothing the expedition can't handle.

At least, that would normally be true; now that the mountain is covered in snow, things have become more difficult than the Elves are used to.

As the expedition reaches a valley that must be traversed to reach the extraction site, you find that strong, turbulent winds are pushing small _blizzards_ of snow and sharp ice around the valley. It's a good thing everyone packed warm clothes! To make it across safely, you'll need to find a way to avoid them.

Fortunately, it's easy to see all of this from the entrance to the valley, so you make a map of the valley and the blizzards (your puzzle input). For example:

    #.#####
    #.....#
    #>....#
    #.....#
    #...v.#
    #.....#
    #####.#


The walls of the valley are drawn as `#`; everything else is ground. Clear ground - where there is currently no blizzard - is drawn as `.`. Otherwise, blizzards are drawn with an arrow indicating their direction of motion: up (`^`), down (`v`), left (`<`), or right (`>`).

The above map includes two blizzards, one moving right (`>`) and one moving down (`v`). In one minute, each blizzard moves one position in the direction it is pointing:

    #.#####
    #.....#
    #.>...#
    #.....#
    #.....#
    #...v.#
    #####.#


Due to <span title="I think, anyway. Do I look like a theoretical blizzacist?">conservation of blizzard energy</span>, as a blizzard reaches the wall of the valley, a new blizzard forms on the opposite side of the valley moving in the same direction. After another minute, the bottom downward-moving blizzard has been replaced with a new downward-moving blizzard at the top of the valley instead:

    #.#####
    #...v.#
    #..>..#
    #.....#
    #.....#
    #.....#
    #####.#


Because blizzards are made of tiny snowflakes, they pass right through each other. After another minute, both blizzards temporarily occupy the same position, marked `2`:

    #.#####
    #.....#
    #...2.#
    #.....#
    #.....#
    #.....#
    #####.#


After another minute, the situation resolves itself, giving each blizzard back its personal space:

    #.#####
    #.....#
    #....>#
    #...v.#
    #.....#
    #.....#
    #####.#


Finally, after yet another minute, the rightward-facing blizzard on the right is replaced with a new one on the left facing the same direction:

    #.#####
    #.....#
    #>....#
    #.....#
    #...v.#
    #.....#
    #####.#


This process repeats at least as long as you are observing it, but probably forever.

Here is a more complex example:

    #.######
    #>>.<^<#
    #.<..<<#
    #>v.><>#
    #<^v^^>#
    ######.#


Your expedition begins in the only non-wall position in the top row and needs to reach the only non-wall position in the bottom row. On each minute, you can _move_ up, down, left, or right, or you can _wait_ in place. You and the blizzards act _simultaneously_, and you cannot share a position with a blizzard.

In the above example, the fastest way to reach your goal requires _`18`_ steps. Drawing the position of the expedition as `E`, one way to achieve this is:

    Initial state:
    #E######
    #>>.<^<#
    #.<..<<#
    #>v.><>#
    #<^v^^>#
    ######.#

    Minute 1, move down:
    #.######
    #E>3.<.#
    #<..<<.#
    #>2.22.#
    #>v..^<#
    ######.#

    Minute 2, move down:
    #.######
    #.2>2..#
    #E^22^<#
    #.>2.^>#
    #.>..<.#
    ######.#

    Minute 3, wait:
    #.######
    #<^<22.#
    #E2<.2.#
    #><2>..#
    #..><..#
    ######.#

    Minute 4, move up:
    #.######
    #E<..22#
    #<<.<..#
    #<2.>>.#
    #.^22^.#
    ######.#

    Minute 5, move right:
    #.######
    #2Ev.<>#
    #<.<..<#
    #.^>^22#
    #.2..2.#
    ######.#

    Minute 6, move right:
    #.######
    #>2E<.<#
    #.2v^2<#
    #>..>2>#
    #<....>#
    ######.#

    Minute 7, move down:
    #.######
    #.22^2.#
    #<vE<2.#
    #>>v<>.#
    #>....<#
    ######.#

    Minute 8, move left:
    #.######
    #.<>2^.#
    #.E<<.<#
    #.22..>#
    #.2v^2.#
    ######.#

    Minute 9, move up:
    #.######
    #<E2>>.#
    #.<<.<.#
    #>2>2^.#
    #.v><^.#
    ######.#

    Minute 10, move right:
    #.######
    #.2E.>2#
    #<2v2^.#
    #<>.>2.#
    #..<>..#
    ######.#

    Minute 11, wait:
    #.######
    #2^E^2>#
    #<v<.^<#
    #..2.>2#
    #.<..>.#
    ######.#

    Minute 12, move down:
    #.######
    #>>.<^<#
    #.<E.<<#
    #>v.><>#
    #<^v^^>#
    ######.#

    Minute 13, move down:
    #.######
    #.>3.<.#
    #<..<<.#
    #>2E22.#
    #>v..^<#
    ######.#

    Minute 14, move right:
    #.######
    #.2>2..#
    #.^22^<#
    #.>2E^>#
    #.>..<.#
    ######.#

    Minute 15, move right:
    #.######
    #<^<22.#
    #.2<.2.#
    #><2>E.#
    #..><..#
    ######.#

    Minute 16, move right:
    #.######
    #.<..22#
    #<<.<..#
    #<2.>>E#
    #.^22^.#
    ######.#

    Minute 17, move down:
    #.######
    #2.v.<>#
    #<.<..<#
    #.^>^22#
    #.2..2E#
    ######.#

    Minute 18, move down:
    #.######
    #>2.<.<#
    #.2v^2<#
    #>..>2>#
    #<....>#
    ######E#


_What is the fewest number of minutes required to avoid the blizzards and reach the goal?_

# Day 25: Full of Hot Air

[https://adventofcode.com/2022/day/25](https://adventofcode.com/2022/day/25)

## Description

### Part One

As the expedition finally reaches the extraction point, several large [hot air balloons](https://en.wikipedia.org/wiki/Hot_air_balloon) drift down to meet you. Crews quickly start unloading the equipment the balloons brought: many hot air balloon kits, some fuel tanks, and a _fuel heating machine_.

The fuel heating machine is a new addition to the process. When this mountain was a volcano, the ambient temperature was more reasonable; now, it's so cold that the fuel won't work at all without being warmed up first.

The Elves, seemingly in an attempt to make the new machine feel welcome, have already attached a pair of [googly eyes](https://en.wikipedia.org/wiki/Googly_eyes) and started calling it "Bob".

To heat the fuel, Bob needs to know the total amount of fuel that will be processed ahead of time so it can correctly calibrate heat output and flow rate. This amount is simply the _sum_ of the fuel requirements of all of the hot air balloons, and those fuel requirements are even listed clearly on the side of each hot air balloon's burner.

You assume the Elves will have no trouble adding up some numbers and are about to go back to figuring out which balloon is yours when you get a tap on the shoulder. Apparently, the fuel requirements use numbers written in a format the Elves don't recognize; predictably, they'd like your help deciphering them.

You make a list of all of the fuel requirements (your puzzle input), but you don't recognize the number format either. For example:

    1=-0-2
    12111
    2=0=
    21
    2=01
    111
    20012
    112
    1=-1=
    1-12
    12
    1=
    122


Fortunately, Bob is labeled with a support phone number. Not to be deterred, you call and ask for help.

"That's right, just supply the fuel amount to the-- oh, for more than one burner? No problem, you just need to add together our Special Numeral-Analogue Fuel Units. Patent pending! They're way better than normal numbers for--"

You mention that it's quite cold up here and ask if they can skip ahead.

"Okay, our Special Numeral-Analogue Fuel Units - SNAFU for short - are sort of like normal numbers. You know how starting on the right, normal numbers have a ones place, a tens place, a hundreds place, and so on, where the digit in each place tells you how many of that value you have?"

"SNAFU works the same way, except it uses powers of five instead of ten. Starting from the right, you have a ones place, a fives place, a twenty-fives place, a one-hundred-and-twenty-fives place, and so on. It's that easy!"

You ask why some of the digits look like `-` or `=` instead of "digits".

"You know, I never did ask the engineers why they did that. Instead of using digits four through zero, the digits are _`2`_, _`1`_, _`0`_, _minus_ (written `-`), and _double-minus_ (written `=`). Minus is worth -1, and double-minus is worth -2."

"So, because ten (in normal numbers) is two fives and no ones, in SNAFU it is written `20`. Since eight (in normal numbers) is two fives minus two ones, it is written `2=`."

"You can do it the other direction, too. Say you have the SNAFU number `2=-01`. That's `2` in the 625s place, `=` (double-minus) in the 125s place, `-` (minus) in the 25s place, `0` in the 5s place, and `1` in the 1s place. (2 times 625) plus (-2 times 125) plus (-1 times 25) plus (0 times 5) plus (1 times 1). That's 1250 plus -250 plus -25 plus 0 plus 1. _976_!"

"I see here that you're connected via our premium uplink service, so I'll transmit our handy SNAFU brochure to you now. Did you need anything else?"

You ask if the fuel will even work in these temperatures.

"Wait, it's _how_ cold? There's no _way_ the fuel - or _any_ fuel - would work in those conditions! There are only a few places in the-- where did you say you are again?"

Just then, you notice one of the Elves pour a few drops from a snowflake-shaped container into one of the fuel tanks, thank the support representative for their time, and disconnect the call.

The SNAFU brochure contains a few more examples of decimal ("normal") numbers and their SNAFU counterparts:

      Decimal          SNAFU
            1              1
            2              2
            3             1=
            4             1-
            5             10
            6             11
            7             12
            8             2=
            9             2-
           10             20
           15            1=0
           20            1-0
         2022         1=11-2
        12345        1-0---0
    314159265  1121-1110-1=0


Based on this process, the SNAFU numbers in the example above can be converted to decimal numbers as follows:

     SNAFU  Decimal
    1=-0-2     1747
     12111      906
      2=0=      198
        21       11
      2=01      201
       111       31
     20012     1257
       112       32
     1=-1=      353
      1-12      107
        12        7
        1=        3
       122       37


In decimal, the sum of these numbers is `4890`.

As you go to input this number on Bob's console, you discover that some buttons you expected are missing. Instead, you are met with buttons labeled `=`, `-`, `0`, `1`, and `2`. Bob needs the input value expressed as a SNAFU number, not in decimal.

Reversing the process, you can determine that for the decimal number `4890`, the SNAFU number you need to supply to Bob's console is _`2=-1=0`_.

The Elves are starting to get cold. _What SNAFU number do you supply to Bob's console?_
