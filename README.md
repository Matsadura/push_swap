# push_swap 🗂➡️🗂

## Project Description

### Core Purpose
Push_swap is a sorting algorithm project where you must sort a stack of integers using two stacks (**a** and **b**) and a limited set of operations. The goal is to produce the shortest sequence of moves to sort the stack in ascending order.

### Key Technical Concepts
- **Stack manipulation**: LIFO (Last-In-First-Out) operations
- **Algorithm optimization**: Minimizing operations for efficiency
- **Sorting strategies**: Divide-and-conquer, pivot partitioning, and insertion sorting
- **Complexity analysis**: Balancing time and algorithmic efficiency

### Why This Project Matters
Push_swap is a cornerstone of 42's algorithm curriculum. It teaches students to:
- Work with strict constraints (limited operations)
- Optimize solutions under pressure
- Understand fundamental sorting mechanics used in larger systems

---

## Learning Objectives 🎯

### Key Programming Concepts
1. **Algorithm Design**: Implementing efficient sorting with limited operations
2. **Stack Management**: Manipulating two LIFO data structures
3. **Parsing/Validation**: Handling edge cases (duplicates, non-integer inputs)
4. **Performance Metrics**: Scoring systems based on operation count

### Skills Developed
- Advanced problem decomposition
- Algorithmic complexity analysis
- Debugging non-trivial recursive logic
- Performance benchmarking

### Technical Standards
```c
/* Example operation: Push from stack a to b (pb) */
void pb(t_stack **a, t_stack **b) {
    t_stack *top_a = *a;
    if (!top_a)
        return ;
    *a = top_a->next;
    top_a->next = *b;
    *b = top_a;
}
```
### Optimization Targets:
* ≤ 3 operations for 3 elements

* ≤ 12 operations for 5 elements

* ≤ 700 operations for 100 elements

* ≤ 5500 operations for 500 elements
