// Advent of Code 2023 - Day 7: Camel Cards

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

var handTypes = map[string]int{
	"fiveOfAKind":  7, // AAAAA
	"fourOfAKind":  6, // AAAAB
	"fullHouse":    5, // AAABB
	"threeOfAKind": 4, // AAABC
	"twoPair":      3, // AABBC
	"onePair":      2, // AABCD
	"highCard":     1, // ABCDE
}

type CamelCardEntry struct {
	Hand string
	Bid  int
	Type int
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

// extract hands and bids from input
func parseCamelCardEntries(lines []string, part int) (ans []CamelCardEntry) {
	ans = make([]CamelCardEntry, len(lines))
	re := regexp.MustCompile(`^([A-Z0-9]+) (\d+)$`)

	for i, line := range lines {
		matches := re.FindStringSubmatch(line)
		if len(matches) != 3 {
			panic("Invalid input")
		}

		ans[i].Hand = matches[1]
		ans[i].Bid, _ = strconv.Atoi(matches[2])
		ans[i].Type = getHandType(ans[i].Hand, part)
	}

	return ans
}

// categorize hand by type
func getHandType(hand string, part int) int {
	cardOccurrences := make(map[rune]int)
	jokerCount := strings.Count(hand, "J")

	// count occurrences of each card
	for _, char := range hand {
		if part == 2 && char == 'J' {
			continue
		}
		cardOccurrences[char]++
	}

	// order cards of the hand by occurrences
	orderedByOccurrences := make([]int, 0, len(cardOccurrences))
	for _, card := range cardOccurrences {
		orderedByOccurrences = append(orderedByOccurrences, card)
	}
	sort.Slice(orderedByOccurrences, func(i, j int) bool {
		return orderedByOccurrences[i] > orderedByOccurrences[j]
	})

	// which card occurs most often?
	highestOccurrence := 0
	if len(orderedByOccurrences) > 0 {
		// hand contains at least one non-joker card
		if part == 2 {
			highestOccurrence = orderedByOccurrences[0] + jokerCount
		} else {
			highestOccurrence = orderedByOccurrences[0]
		}
	} else {
		// only jokers in the hand
		highestOccurrence = jokerCount
	}

	// which card occurs second most often? - relevant for full house and two pair
	secondHighestOccurrence := 0
	if len(orderedByOccurrences) > 1 {
		secondHighestOccurrence = orderedByOccurrences[1]
	}

	// categorize based on occurrences
	switch highestOccurrence {
	case 5:
		return handTypes["fiveOfAKind"]
	case 4:
		return handTypes["fourOfAKind"]
	case 3:
		if secondHighestOccurrence == 2 {
			return handTypes["fullHouse"]
		}
		return handTypes["threeOfAKind"]
	case 2:
		if secondHighestOccurrence == 2 {
			return handTypes["twoPair"]
		}
		return handTypes["onePair"]
	default:
		return handTypes["highCard"]
	}
}

// apply second ordering rule - joker is the weakest card in part 2
func compareHandsByStrength(a, b rune, part int) bool {
	cardStrengthOrders := map[int]string{
		1: "23456789TJQKA",
		2: "J23456789TQKA",
	}

	return strings.Index(cardStrengthOrders[part], string(a)) < strings.Index(cardStrengthOrders[part], string(b))
}

// order hands by type while taking second ordering rules into account
func compareHandsByOrderingRules(a, b CamelCardEntry, part int) bool {
	// first ordering rule
	if a.Type != b.Type {
		return a.Type < b.Type
	}

	// second ordering rule
	for i := 0; i < len(a.Hand); i++ {
		if a.Hand[i] != b.Hand[i] {
			return compareHandsByStrength(rune(a.Hand[i]), rune(b.Hand[i]), part)
		}
	}

	return false
}

func part1(input string) int {
	lines := parseInput(input)
	entries := parseCamelCardEntries(lines, 1)
	ans := 0

	// order hands by type while taking second ordering rules into account
	sort.Slice(entries, func(i, j int) bool {
		return compareHandsByOrderingRules(entries[i], entries[j], 1)
	})

	// calculate score
	for i, entry := range entries {
		ans += entry.Bid * (i + 1)
	}

	return ans
}

func part2(input string) int {
	lines := parseInput(input)
	entries := parseCamelCardEntries(lines, 2)
	ans := 0

	// order hands by type while taking second ordering rules into account
	sort.Slice(entries, func(i, j int) bool {
		return compareHandsByOrderingRules(entries[i], entries[j], 2)
	})

	// calculate score
	for i, entry := range entries {
		ans += entry.Bid * (i + 1)
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
