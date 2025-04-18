# Word Transformation Program

A program that finds paths to transform one word into another by changing one letter at a time, ensuring each intermediate word is valid according to a dictionary.

## Description

Given a starting word and a target word of the same length, the program finds:
- Any valid transformation path (using DFS)
- The shortest transformation path (using BFS)

Example: `LEND` → `SEND`
```
LEND {L->S} SEND
Total steps: 1
```

## Data Structures & Algorithms

Algorithm Plan and Strategy
Sort and Deduplication
 Use Radix Sort (for fixed-length words) or std::sort.
 Use a queue for bucket sorting.
 Remove duplicates in a single pass post-sort.
Adjacent Word Generation
 For a given word, find all dictionary words that differ by one letter.
 Use isAdjacent(w1, w2) to check.
Find Any Path
 Use DFS with a stack to find any valid transformation path.
 Stop when the target word is found.
Find Optimal Path
 Use BFS with a queue to find the shortest path.
 Track parents to reconstruct the transformation.
Character Change Display
 Compare each word pair in the path and show the character change (e.g., lend {e->a} land).
 
Flowchart:
START
  ↓
INPUT: start word, target word
  ↓
Load dictionary into memory
  ↓
Filter dictionary by word length
  ↓
Sort dictionary (Radix or Lexicographic Sort)
  ↓
Remove duplicates
  ↓
Build word graph (edges = 1-letter difference)
  ↓
Find transformations:
     ↳ Any solution (DFS)
     ↳ Optimal solution (BFS)
  ↓
Print each step and changed letter
  ↓
END
