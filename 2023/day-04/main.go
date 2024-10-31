// Advent of Code 2023 - Day 4: Scratchcards

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

// use regex to split line into winning numbers and our numbers
func parseLine(line string) (winningNumbers []int, ourNumbers []int) {
	re := regexp.MustCompile(`Card\s*(?:\d+): \s*(\d+(?:\s*\d+)*)\s*\|\s*(\d+(?:\s*\d+)*)`)
	match := re.FindStringSubmatch(line)

	// parse the winning numbers
	winningPart := strings.Split(match[1], " ")
	winningNumbers = make([]int, 0, len(winningPart))
	for _, part := range winningPart {
		if part != "" && part != " " {
			num, err := strconv.Atoi(part)
			if err != nil {
				panic(err)
			}
			winningNumbers = append(winningNumbers, num)
		}
	}

	// parse our numbers
	ourPart := strings.Split(match[2], " ")
	ourNumbers = make([]int, 0, len(ourPart))
	for _, part := range ourPart {
		if part != "" && part != " " {
			num, err := strconv.Atoi(part)
			if err != nil {
				panic(err)
			}
			ourNumbers = append(ourNumbers, num)
		}
	}

	return winningNumbers, ourNumbers
}

func part1(input string) int {
	lines := parseInput(input)
	ans := 0

	for _, line := range lines {
		points := 0
		winningNumbers, ourNumbers := parseLine(line)

		// determine amount of matching numbers
		for _, winningNumber := range winningNumbers {
			for _, ourNumber := range ourNumbers {
				if ourNumber == winningNumber {
					if points == 0 {
						points = 1
					} else {
						points *= 2
					}
				}
			}
		}
		ans += points
	}

	return ans
}

func part2(input string) int {
	lines := parseInput(input)
	ans := 0

	amountOfInstances := make(map[int]int)
	for i, line := range lines {
		points := 0
		winningNumbers, ourNumbers := parseLine(line)

		// each scratchcard has at least 1 instance
		amountOfInstances[i] += 1

		// determine amount of matching numbers
		for _, winningNumber := range winningNumbers {
			for _, ourNumber := range ourNumbers {
				if ourNumber == winningNumber {
					points++
				}
			}
		}

		// update the amount of instances based on matching numbers for this scratchcard
		for j := i + 1; j <= i+points; j++ {
			amountOfInstances[j] += amountOfInstances[i]
		}
	}

	// sum up the amount of total scratchcards
	for _, amount := range amountOfInstances {
		ans += amount
	}

	return ans
}

func main() {
	if len(os.Args) != 2 {
		panic("Usage: go run main.go -p1|-p2")
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
