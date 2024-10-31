// Advent of Code 2023 - Day 5: If You Give A Seed A Fertilizer

package main

import (
	_ "embed"
	"fmt"
	"os"
	"regexp"
	"sort"
	"strconv"
	"strings"
)

//go:embed input.txt
var input string

type Mapping struct {
	Destination int
	Source      int
	Lenght      int
}

func init() {
	input = strings.TrimRight(input, "\n")
	if len(input) == 0 {
		panic("Input is empty")
	}
}

func parseInput(input string) (ans []string) {
	for _, line := range strings.Split(input, "\n\n") {
		ans = append(ans, line)
	}
	return ans
}

// parse input into seeds and 2D array of mappings
func parseSeedsAndMaps(seedsAndMaps []string) (seeds []int, maps [][]Mapping) {
	// parse initial seeds
	re := regexp.MustCompile(`^seeds: (\d+(?:\s*\d+)*)`)
	match := re.FindStringSubmatch(seedsAndMaps[0])
	parts := strings.Split(match[1], " ")
	seeds = make([]int, 0, len(match))

	for _, part := range parts {
		num, err := strconv.Atoi(part)
		if err != nil {
			panic(err)
		}
		seeds = append(seeds, num)
	}

	// parse various mappings
	re = regexp.MustCompile(`([a-z-: ]*)\n(\d+(?:\s*\d+)*)`)
	maps = make([][]Mapping, 0, len(seedsAndMaps[1:]))

	// go through all maps
	for _, group := range seedsAndMaps[1:] {
		match := re.FindStringSubmatch(group)
		parts := strings.Split(match[2], "\n")
		mapping := make([]Mapping, 0, len(parts))

		// go through entries in a map and create a mapping
		for _, part := range parts {
			m := Mapping{}
			nums := strings.Split(part, " ")
			m.Destination, _ = strconv.Atoi(nums[0])
			m.Source, _ = strconv.Atoi(nums[1])
			m.Lenght, _ = strconv.Atoi(nums[2])
			mapping = append(mapping, m)
		}

		maps = append(maps, mapping)
	}

	return seeds, maps
}

func part1(input string) int {
	seedsAndMaps := parseInput(input)
	seeds, maps := parseSeedsAndMaps(seedsAndMaps)

	// create seedPath from seed to location number
	seedPath := make([]int, 0, len(seeds))
	for _, seed := range seeds {
		seedPath = append(seedPath, seed)
	}

	// find seedPath from seed to location number
	for _, mapping := range maps {
		for i, _ := range seeds {
			for _, m := range mapping {
				// check if source number is mapped, otherwise it corresponds to the same destination number
				if seedPath[i] >= m.Source && seedPath[i] < m.Source+m.Lenght {
					seedPath[i] = m.Destination + (seedPath[i] - m.Source)
					break
				}
			}
		}
	}

	// return minimum location number
	sort.Ints(seedPath)
	return seedPath[0]
}

func part2(input string) int {
	seedsAndMaps := parseInput(input)
	seeds, maps := parseSeedsAndMaps(seedsAndMaps)

	// treat seeds as seed + range combination
	var seedsWithInterval []int
	if len(seeds)%2 != 0 {
		panic("Number of seeds must be even")
	}
	for i := 0; i < len(seeds); i += 2 {
		start := seeds[i]
		length := seeds[i+1]
		for j := start; j < start+length; j++ {
			seedsWithInterval = append(seedsWithInterval, j)
		}
	}

	// create seedPath from seed to location number
	seedPath := make([]int, 0, len(seedsWithInterval))
	for _, seed := range seedsWithInterval {
		seedPath = append(seedPath, seed)
	}

	// find seedPath from seed to location number
	for _, mapping := range maps {
		for i, _ := range seedsWithInterval {
			for _, m := range mapping {
				// check if source number is mapped, otherwise it corresponds to the same destination number
				if seedPath[i] >= m.Source && seedPath[i] < m.Source+m.Lenght {
					seedPath[i] = m.Destination + (seedPath[i] - m.Source)
					break
				}
			}
		}
	}

	// return minimum location number
	sort.Ints(seedPath)
	return seedPath[0]
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
