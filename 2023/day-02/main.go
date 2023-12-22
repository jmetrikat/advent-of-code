// Advent of Code 2023 - Day 2: Cube Conundrum

package main

import (
	_ "embed"
	"fmt"
	"os"
	"regexp"
	"strconv"
	"strings"
)

//go:embed input.txt
var input string

var availableCubes = map[string]int{
	"red":   12,
	"green": 13,
	"blue":  14,
}

func init() {
	input = strings.TrimRight(input, "\n")
	if len(input) == 0 {
		panic("Input is empty")
	}
}

func parseInput(input string) (ans []string) {
	for _, line := range strings.Split(input, "\n") {
		ans = append(ans, line)
	}
	return ans
}

// part 1: check if game is valid in terms of available cubes
func isValidGame(noOfShownCubesByElf map[string]int) bool {
	for color, count := range noOfShownCubesByElf {
		if count > availableCubes[color] {
			return false
		}
	}
	return true
}

// part 2: update minimum amount of cubes necessary to play the game
func updateMinimumCubes(minimumCubes map[string]int, noOfShownCubesByElf map[string]int) map[string]int {
	for color, count := range noOfShownCubesByElf {
		if count > minimumCubes[color] {
			minimumCubes[color] = count
		}
	}

	return minimumCubes
}

func checkGame(line string, minimumCubes map[string]int, part int) int {
	noOfShownCubesByElf := make(map[string]int)

	// split game data into sets of cubes
	re := regexp.MustCompile(`^Game (\d+): (.*)$`)
	cubeSets := strings.Split(re.FindStringSubmatch(line)[2], "; ")

	for _, set := range cubeSets {
		// reset no of shown cubes by color
		for color := range availableCubes {
			noOfShownCubesByElf[color] = 0
		}

		// count shown cubes by color
		cubes := strings.Split(set, ", ")
		for _, cube := range cubes {
			re := regexp.MustCompile(`(\d+) (\w+)`)
			tuple := re.FindStringSubmatch(cube)
			color := tuple[2]

			if _, ok := availableCubes[color]; !ok {
				panic("Invalid color")
			}

			count, err := strconv.Atoi(tuple[1])
			if err != nil {
				panic(err)
			}

			noOfShownCubesByElf[color] += count
		}

		if part == 2 {
			minimumCubes = updateMinimumCubes(minimumCubes, noOfShownCubesByElf)
		} else {
			if !isValidGame(noOfShownCubesByElf) {
				return -1
			}
		}
	}

	if part == 2 {
		return minimumCubes["red"] * minimumCubes["green"] * minimumCubes["blue"]
	}

	return 0
}

func part1(input string) int {
	lines := parseInput(input)
	ans := 0

	for i, line := range lines {
		if checkGame(line, nil, 1) == 0 {
			ans += i + 1
		}
	}

	return ans
}

func part2(input string) int {
	lines := parseInput(input)
	minimumCubes := make(map[string]int)
	ans := 0

	for _, line := range lines {
		for color := range availableCubes {
			minimumCubes[color] = 0
		}
		ans += checkGame(line, minimumCubes, 2)
	}

	return ans
}

func main() {
	if len(os.Args) != 2 {
		panic("Usage: ./main.go -p1|-p2")
	}

	switch os.Args[1] {
	case "-p1":
		ans := part1(input)
		fmt.Println(ans)
	case "-p2":
		ans := part2(input)
		fmt.Println(ans)
	default:
		fmt.Println("Invalid flag passed")
	}
}
