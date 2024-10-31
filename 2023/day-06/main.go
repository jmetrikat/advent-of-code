// Advent of Code 2023 - Day 6: Wait For It

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

// extract times and distances from input
func parseRaces(lines []string) (times []int, distances []int) {
	// parse times
	re := regexp.MustCompile(`^Time:\s+((\d*\s*)*)`)
	match := re.FindStringSubmatch(lines[0])
	parts := strings.Split(match[1], " ")
	times = make([]int, 0, len(match))

	for _, part := range parts {
		if len(part) != 0 {
			num, err := strconv.Atoi(part)
			if err != nil {
				panic(err)
			}
			times = append(times, num)
		}
	}

	// parse distances
	re = regexp.MustCompile(`^Distance:\s+((\d*\s*)*)`)
	match = re.FindStringSubmatch(lines[1])
	parts = strings.Split(match[1], " ")
	distances = make([]int, 0, len(match))

	for _, part := range parts {
		if len(part) != 0 {
			num, err := strconv.Atoi(part)
			if err != nil {
				panic(err)
			}
			distances = append(distances, num)
		}
	}

	return times, distances
}

// find amount of strategies that would beat the current distance
func checkRaceStrategyPossibilities(time int, distance int) int {
	ans := 0

	// check all possible strategies
	for i := 0; i < time; i++ {
		speed := i
		timeToTravel := time - i
		// check if our strategy beats the current record
		if speed*timeToTravel > distance {
			ans++
		}
	}

	return ans
}

func part1(input string) int {
	lines := parseInput(input)
	times, distances := parseRaces(lines)
	ans := 1

	if len(times) != len(distances) {
		panic("Times and distances do not match")
	}

	// get possibilities for each race
	for i := 0; i < len(times); i++ {
		ans *= checkRaceStrategyPossibilities(times[i], distances[i])
	}

	return ans
}

func part2(input string) int {
	lines := parseInput(input)
	times, distances := parseRaces(lines)

	if len(times) != len(distances) {
		panic("Times and distances do not match")
	}

	// concatenate times and distances to treat all races as one
	cTime, cDistance := "", ""
	for i := 0; i < len(times); i++ {
		cTime += strconv.Itoa(times[i])
		cDistance += strconv.Itoa(distances[i])
	}

	time, err := strconv.Atoi(cTime)
	if err != nil {
		panic(err)
	}

	distance, err := strconv.Atoi(cDistance)
	if err != nil {
		panic(err)
	}

	return checkRaceStrategyPossibilities(time, distance)
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
