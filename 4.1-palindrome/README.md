# Experiment 1.4.1 – Palindrome Linked List

## Aim
To implement a program to check whether a singly linked list is a palindrome or not.

## Problem Statement
Given the head of a singly linked list, return **true** if the linked list is a palindrome; otherwise return **false**.

## Approaches

### 1. Brute Force
- Store all node values in a vector.
- Compare elements from the beginning and the end.
- If all values match, the linked list is a palindrome.

### 2. Optimal Approach
- Find the middle of the linked list using slow and fast pointers.
- Reverse the second half of the linked list.
- Compare the first half with the reversed second half.
- If all values are equal, return **true**; otherwise return **false**.

## Algorithm

1. Read the linked list.
2. Find the middle node using slow and fast pointers.
3. Reverse the second half of the list.
4. Compare both halves.
5. If all corresponding nodes are equal, print **True**.
6. Otherwise, print **False**.

## Time Complexity

| Approach | Time Complexity | Space Complexity |
|----------|-----------------|------------------|
| Brute Force | O(n) | O(n) |
| Optimal | O(n) | O(1) |

## Sample Input

```
Enter number of nodes: 5
Enter node values: 1 2 3 2 1
```

## Sample Output

```
Output: True
```

## Learning Outcomes

- Understand singly linked list traversal.
- Learn palindrome checking in a linked list.
- Learn slow and fast pointer technique.
- Learn in-place linked list reversal.
- Analyze time and space complexity.

## Files Included

- BruteForce.cpp
- Optimal.cpp
- Outputs/
