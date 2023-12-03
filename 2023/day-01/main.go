// Advent of Code 2023 - Day 1: Trebuchet?!

package main

import (
	_ "embed"
	"fmt"
	"os"
	"strconv"
	"strings"
	"unicode"
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

func part1(input string) int {
	lines := parseInput(input)
	sum := 0

	for _, line := range lines {
		calibrationValue := ""
		for _, char := range line {
			if unicode.IsDigit(char) {
				calibrationValue += string(char)
				break
			}
		}
		for i := len(line) - 1; i >= 0; i-- {
			if unicode.IsDigit(rune(line[i])) {
				calibrationValue += string(line[i])
				break
			}
		}

		value, err := strconv.Atoi(calibrationValue)
		if err != nil {
			panic(err)
		}

		sum += value
	}

	return sum
}

func part2(input string) int {
	lines := parseInput(input)
	writtenToNumber := map[string]string{
		"one":   "o1e",
		"two":   "t2o",
		"three": "th3ee",
		"four":  "fo4r",
		"five":  "f5ve",
		"six":   "s6x",
		"seven": "se7en",
		"eight": "ei8ht",
		"nine":  "n9ne",
	}

	for i, line := range lines {
		for word, number := range writtenToNumber {
			line = strings.ReplaceAll(line, word, number)
			lines[i] = line
		}
	}

	return part1(strings.Join(lines, "\n"))
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
