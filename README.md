# push_swap

An optimized stack-based sorting algorithm implemented in C.

## Overview

**push_swap** is a project that consists of sorting a list of integers using two stacks (`a` and `b`) and a limited set of allowed operations.

The goal is to sort the stack with the **minimum number of operations possible**, focusing on algorithmic efficiency and problem-solving under constraints.

## Rules & Constraints

- Only two stacks are allowed: `a` and `b`
- A restricted set of operations can be used:
  - swap
  - push
  - rotate
  - reverse rotate
- The program must output the list of operations needed to sort the stack
- The input must be sorted in ascending order in stack `a`

## Approach

The project focuses on:
- Choosing efficient sorting strategies depending on input size
- Reducing the total number of operations
- Handling edge cases and input validation

## Usage

```bash
make
./push_swap 4 67 3 87 23
