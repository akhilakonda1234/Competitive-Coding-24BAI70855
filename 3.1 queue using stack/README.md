# 3.1 Queue Using  Stack

## Aim
To implement a Queue using a single Stack in C++.

## Problem Statement
Implement a First In First Out (FIFO) Queue using only one stack. The queue should support the following operations:
- Push
- Pop
- Front
- Empty

## Algorithm
1. Create one stack.
2. Push operation inserts an element into the stack.
3. Pop operation uses recursion to remove the bottom-most element.
4. Front operation uses recursion to access the bottom-most element without removing it.
5. Empty checks whether the stack is empty.

## Operations
- Push(x) → Insert element into queue.
- Pop() → Remove front element.
- Front() → Display front element.
- Empty() → Check whether queue is empty.

## Time Complexity

| Operation | Time Complexity |
|-----------|-----------------|
| Push | O(1) |
| Pop | O(n) |
| Front | O(n) |
| Empty | O(1) |

## Space Complexity

- O(n) (Recursive Call Stack)

## Output
The output screenshots are available in the **Outputs** folder.
