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

## Implementation Details

### Data Structures
- **Graph**: Unordered map for word connections (adjacency list)
- **Dictionary**: Vector + unordered set for O(1) word lookup
- **Queue**: BFS implementation for optimal paths
- **Stack**: DFS implementation for any valid path
- **Hash Maps**: Parent tracking for path reconstruction

### Algorithm Strategy

1. **Dictionary Processing**
   - Load dictionary and filter by word length
   - Sort words (using std::sort)
   - Remove duplicates in single pass

2. **Word Graph Construction**
   - For each word, find adjacent words (1-letter difference)
   - Build adjacency list representation
   - Use efficient isAdjacent() comparison

3. **Path Finding**
   - **Any Path (DFS)**
     - Use stack for depth-first exploration
     - Track visited words
     - Stop at first valid path
   - **Optimal Path (BFS)**
     - Use queue for breadth-first search
     - Track parent words
     - Find shortest transformation

4. **Path Display**
   - Reconstruct path from parent tracking
   - Show character changes between words

## Program Flow
```
START
  ↓
INPUT (start word, target word)
  ↓
Load & Process Dictionary
  ↓
Build Word Graph
  ↓
Find Transformations
  ├─→ Any Path (DFS)
  └─→ Optimal Path (BFS)
  ↓
Display Results
  ↓
END
```

