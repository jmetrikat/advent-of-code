// Advent of Code 2023 - Day 8: Haunted Wasteland

package main

import (
	_ "embed"
	"fmt"
	"os"
	"regexp"
	"strings"
)

//go:embed input.txt
var input string

type NeighborElements struct {
	Left  string
	Right string
}

func gcd(a, b int) int {
	for b != 0 {
		a, b = b, a%b
	}
	return a
}

func lcm(a, b int) int {
	return a * b / gcd(a, b)
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

// extract instructions and nodes from input
func parseInstructionsForNodes(input []string) (instructions []string, nodes []string, nodeNeighbors map[string]NeighborElements) {
	// parse left / right instructions
	instructions = make([]string, 0, len(input[0]))
	instructions = append(instructions, strings.Split(input[0], "")...)

	// parse node network with left / right neighbors
	nodes = make([]string, 0, len(input[1]))
	nodeNeighbors = make(map[string]NeighborElements)

	for _, line := range input[2:] {
		re := regexp.MustCompile(`^([A-Z0-9]+) = \(([A-Z0-9]+), ([A-Z0-9]+)\)$`) // AAA = (BBB, CCC)
		matches := re.FindStringSubmatch(line)
		if len(matches) != 4 {
			panic("Invalid input")
		}
		nodes = append(nodes, matches[1])
		nodeNeighbors[matches[1]] = NeighborElements{matches[2], matches[3]}
	}

	return instructions, nodes, nodeNeighbors
}

// find start nodes and end nodes
func getStartNodes(nodes []string, part int) (start []string) {
	start = make([]string, 0)

	switch part {
	case 1:
		// start node is AAA, end node is ZZZ
		start = append(start, "AAA")
	case 2:
		// start nodes are nodes ending with A
		for _, node := range nodes {
			if strings.HasSuffix(node, "A") {
				start = append(start, node)
			}
		}
	}

	return start
}

// get next element based on instruction
func getNextElement(instruction string, neighbors NeighborElements) string {
	if instruction == "L" {
		return neighbors.Left
	} else if instruction == "R" {
		return neighbors.Right
	} else {
		panic("Invalid instruction")
	}
}

func part1(input string) int {
	lines := parseInput(input)
	instructions, nodes, nodeNeighbors := parseInstructionsForNodes(lines)
	ans := 0

	// start node is AAA, end node is ZZZ
	start := getStartNodes(nodes, 1)
	nextElement := start[0]
	end := "ZZZ"

	// run path search based on instructions
	for nextElement != end {
		for _, instruction := range instructions {
			nextElement = getNextElement(instruction, nodeNeighbors[nextElement])
			ans++
		}
	}

	return ans
}

func part2(input string) int {
	lines := parseInput(input)
	instructions, nodes, nodeNeighbors := parseInstructionsForNodes(lines)
	ans := 0

	// start nodes are nodes ending with A,end nodes are nodes ending with Z
	starts := getStartNodes(nodes, 2)
	stepsTillEnd := make([]int, len(starts))
	nextElements := append([]string(nil), starts...)

	// run simultaneous path for all start nodes based on instructions
	for allPathsHaveFinished := false; !allPathsHaveFinished; {
		for _, instruction := range instructions {
			for i, element := range nextElements {
				nextElements[i] = getNextElement(instruction, nodeNeighbors[element])
			}
			ans++

			// check if all paths have arrived at the end
			for i, element := range nextElements {
				if strings.HasSuffix(element, "Z") {
					stepsTillEnd[i] = ans
				}
			}

			// check if all paths found the end in non-zero steps
			noOfFinishedPaths := 0
			for _, steps := range stepsTillEnd {
				if steps != 0 {
					noOfFinishedPaths++
				}
			}

			// if all paths have arrived at the end, calculate the LCM of all steps
			if noOfFinishedPaths == len(stepsTillEnd) {
				ans = stepsTillEnd[0]
				for _, steps := range stepsTillEnd[1:] {
					ans = lcm(ans, steps)
				}
				allPathsHaveFinished = true
				break
			}
		}
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
