package main

import (
	"testing"
	"time"
)

func TestPart1(t *testing.T) {
	tests := []struct {
		name  string
		input string
		want  int
	}{
		{
			name:  "actual",
			input: input,
			want:  2679,
		},
	}
	t.Parallel()

	done := make(chan bool, 1)
	go func() {
		defer close(done)
		for _, tt := range tests {
			t.Run(tt.name, func(t *testing.T) {
				if got := part1(tt.input); got != tt.want {
					t.Errorf("part1() = %v, want %v", got, tt.want)
				}
			})
		}
	}()

	select {
	case <-done:
	case <-time.After(5 * time.Second):
		t.Fatal("test timed out")
	}
}

func TestPart2(t *testing.T) {
	tests := []struct {
		name  string
		input string
		want  int
	}{
		{
			name:  "actual",
			input: input,
			want:  77607,
		},
	}
	t.Parallel()

	done := make(chan bool, 1)
	go func() {
		defer close(done)
		for _, tt := range tests {
			t.Run(tt.name, func(t *testing.T) {
				if got := part2(tt.input); got != tt.want {
					t.Errorf("part2() = %v, want %v", got, tt.want)
				}
			})
		}
	}()

	select {
	case <-done:
	case <-time.After(5 * time.Second):
		t.Fatal("test timed out")
	}
}
