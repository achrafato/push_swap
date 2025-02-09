# Push Swap - Stack Sorting Algorithm

An implementation of a sorting algorithm using two stacks with a limited set of operations, featuring both Merge Sort and Turkish (Turk) algorithm implementations.

## 🎯 Project Overview

The program sorts a stack of integers using two stacks (stack A and stack B) with a limited set of operations, aiming to sort with the minimum number of moves.

## 🛠️ Algorithms Implemented

### Merge Sort Implementation
- Divides the stack into sorted chunks
- Efficiently merges sub-stacks
- Optimized for larger datasets

### Turkish (Turk) Algorithm
- Position-based sorting strategy
- Optimized for medium-sized datasets
- Efficient rotation calculations

## 📁 Files Structure

```
├── Makefile
├── push_swap.c          # Main program
├── push_swap.h          # Header file
├── checker_bonus        # Bonus checker program
├── quick_sort_chuncks.c # Chunking implementation
├── sort_three.c         # Small stack optimization
├── instructions_*.c     # Stack operations
└── utils_*.c           # Helper functions
```

## 💻 Available Operations

- `sa`: Swap first two elements of stack A
- `sb`: Swap first two elements of stack B
- `ss`: sa and sb at the same time
- `pa`: Push top element from stack B to stack A
- `pb`: Push top element from stack A to stack B
- `ra`: Rotate stack A up
- `rb`: Rotate stack B up
- `rr`: ra and rb at the same time
- `rra`: Rotate stack A down
- `rrb`: Rotate stack B down
- `rrr`: rra and rrb at the same time

## 🚀 Usage

### Compilation
```bash
make        # Compile push_swap
make bonus  # Compile checker
```

### Running
```bash
./push_swap 2 1 3 6 5 8
```

### Checker Usage
```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_bonus $ARG
```

## ⚙️ Implementation Details

### Merge Sort Features
- Efficient chunk creation
- Optimized merge strategy
- Adaptive to data size

### Turk Algorithm Features
- Position calculation
- Optimal rotation paths
- Cost-based move selection

### Optimizations
- Special cases for 2-3 numbers
- Chunk size optimization
- Rotation direction optimization
- Move combination optimization

## 🎯 Performance

### Small Sets (≤ 3)
- Optimized solutions
- Maximum 2-3 operations

### Medium Sets (≤ 100)
- Average: < 700 operations
- Uses Turk algorithm

### Large Sets (≤ 500)
- Average: < 5500 operations
- Uses Merge Sort implementation

## 🧪 Testing

```bash
# Random number test
ARG=$(ruby -e "puts (1..100).to_a.shuffle.join(' ')"); ./push_swap $ARG

# Checker test
ARG=$(ruby -e "puts (1..100).to_a.shuffle.join(' ')"); ./push_swap $ARG | ./checker_bonus $ARG

# Operation counter
ARG=$(ruby -e "puts (1..100).to_a.shuffle.join(' ')"); ./push_swap $ARG | wc -l
```

## 🐛 Error Handling

- Duplicate numbers
- Non-numeric input
- Integer overflow
- Memory management
- Invalid operations

## 📜 License

This project is part of the 42 curriculum and is provided as-is.
