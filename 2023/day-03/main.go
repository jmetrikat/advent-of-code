// Advent of Code 2023 - Day 3: Gear Ratios

package main

import (
	_ "embed"
	"fmt"
	"os"
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

// transform schema to matrix
func createMatrix(lines []string) [][]rune {
	matrix := make([][]rune, len(lines))
	for i, line := range lines {
		for _, char := range line {
			matrix[i] = append(matrix[i], char)
		}
	}
	return matrix
}

// get number from matrix
func getNumber(matrix [][]rune, i, j int) int {
	for j > 0 && unicode.IsDigit(matrix[i][j-1]) {
		j--
	}
	number := 0
	for k := j; k < len(matrix[0]); k++ {
		if !unicode.IsDigit(matrix[i][k]) {
			break
		}
		number = number*10 + int(matrix[i][k]-'0')
	}
	return number
}

// check if a '*' symbol connects two numbers
func checkAdjacent(matrix [][]rune, i, j int) (nums []int) {
	nums = make([]int, 0, 2)
	for l := i - 1; l <= i+1; l++ {
		prevWasDigit := false
		for k := j - 1; k <= j+1; k++ {
			if k < 0 || l < 0 || k >= len(matrix[0]) || l >= len(matrix) || (l == i && k == j) || !unicode.IsDigit(matrix[l][k]) {
				prevWasDigit = false
				continue
			} else if unicode.IsDigit(matrix[l][k]) && !prevWasDigit {
				prevWasDigit = true
				nums = append(nums, getNumber(matrix, l, k))
			}
		}
	}
	return nums
}

func part1(input string) int {
	lines := parseInput(input)
	matrix := createMatrix(lines)
	ans := 0

	// find all numbers adjacent to a symbol
	for i, line := range lines {
		for j, char := range line {
			if char != '.' && !unicode.IsDigit(char) {
				nums := checkAdjacent(matrix, i, j)
				for _, num := range nums {
					ans += num
				}
			}
		}
	}

	return ans
}

func part2(input string) int {
	lines := parseInput(input)
	matrix := createMatrix(lines)
	ans := 0

	// find all numbers adjacent to a '*'
	for i, line := range lines {
		for j, char := range line {
			if char == '*' {
				nums := checkAdjacent(matrix, i, j)
				if len(nums) == 2 {
					ans += nums[0] * nums[1]
				}
			}
		}
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
