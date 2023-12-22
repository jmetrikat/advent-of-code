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

// check if symbol is adjacent to a digit
func checkAdjacent(matrix [][]rune, i, start, end int) bool {
	for l := i - 1; l <= i+1; l++ {
		for k := start - 1; k <= end+1; k++ {
			if k < 0 || l < 0 || k >= len(matrix[0]) || l >= len(matrix) || (l == i && (start <= k && k <= end)) {
				continue
			}
			if matrix[l][k] != '.' && !unicode.IsDigit(matrix[l][k]) {
				return true
			}
		}
	}
	return false
}

// check if a '*' symbol connects two numbers
func checkAdjacentNumbers(matrix [][]rune, i, j int) (num1, num2 int) {
	for l := i - 1; l <= i+1; l++ {
		prevWasDigit := false
		for k := j - 1; k <= j+1; k++ {
			if k < 0 || l < 0 || k >= len(matrix[0]) || l >= len(matrix) || (l == i && k == j) {
				prevWasDigit = false
				continue
			}
			if unicode.IsDigit(matrix[l][k]) && !prevWasDigit {
				prevWasDigit = true
				if num1 == 0 {
					num1 = getNumber(matrix, l, k)
				} else {
					num2 = getNumber(matrix, l, k)
				}
			} else if !unicode.IsDigit(matrix[l][k]) {
				prevWasDigit = false
			}
		}
	}
	return num1, num2
}

func part1(input string) int {
	lines := parseInput(input)
	matrix := createMatrix(lines)
	ans := 0

	// check all numbers for adjacent symbols
	for i, line := range matrix {
		prevWasDigit := false
		number := 0
		start := 0
		for j, char := range line {
			if unicode.IsDigit(char) {
				if prevWasDigit {
					number = number*10 + int(char-'0')
				} else {
					start = j
					prevWasDigit = true
					number = int(char - '0')
				}
			}
			if (!unicode.IsDigit(char) && prevWasDigit) || j == len(line)-1 {
				if checkAdjacent(matrix, i, start, j-1) {
					ans += number
				}
				prevWasDigit = false
				number = 0
			}
		}
	}

	return ans
}

func part2(input string) int {
	lines := parseInput(input)
	matrix := createMatrix(lines)
	ans := 0

	for i, line := range lines {
		for j, char := range line {
			if char == '*' {
				num1, num2 := checkAdjacentNumbers(matrix, i, j)
				if num1 != 0 && num2 != 0 {
					fmt.Printf("[%d, %d]\n", num1, num2)
					ans += num1 * num2
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
