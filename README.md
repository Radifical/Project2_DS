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

### Data Structures
- **Graph**: Unordered map representing word connections
- **Dictionary**: Vector and unordered set for efficient word storage/lookup
- **Queue**: For BFS (optimal path finding)
- **Stack**: For DFS (any path finding)
- **Hash Sets/Maps**: For tracking visited nodes and parent relationships

### Algorithms
- **Breadth-First Search (BFS)**: Finding the shortest transformation path
- **Depth-First Search (DFS)**: Finding any valid transformation path
- **Adjacent Word Finding**: O(L) comparison where L is word length

