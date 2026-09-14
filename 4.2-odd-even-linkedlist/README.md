# Experiment 1.4.2 – Odd Even Linked List

## Aim
To implement a program that rearranges a singly linked list so that all nodes at odd positions appear first, followed by all nodes at even positions while maintaining their original relative order.

## Problem Statement
Given the head of a singly linked list, group all nodes at odd positions together followed by the nodes at even positions. The relative order of odd and even nodes should remain the same.

## Approach

### Optimal Approach
- Create two pointers:
  - **odd** → Points to nodes at odd positions.
  - **even** → Points to nodes at even positions.
- Store the head of the even list using **evenHead**.
- Traverse the list and connect all odd nodes together.
- Connect all even nodes together.
- Finally, attach the even list after the odd list.

## Algorithm

1. Check if the list is empty or has only one node.
2. Initialize:
   - odd = head
   - even = head->next
   - evenHead = even
3. Traverse the linked list:
   - Connect odd nodes.
   - Connect even nodes.
4. Attach the even list after the odd list.
5. Return the modified linked list.

## Time Complexity

| Approach | Time Complexity | Space Complexity |
|----------|-----------------|------------------|
| Optimal | O(n) | O(1) |

## Sample Input

```
Enter number of nodes: 5
Enter node values: 1 2 3 4 5
```

## Sample Output

```
Original List: 1 2 3 4 5
Odd Even List: 1 3 5 2 4
```

## Learning Outcomes

- Understand singly linked list traversal.
- Learn pointer manipulation in linked lists.
- Understand odd-even node grouping.
- Perform in-place linked list rearrangement.
- Analyze time and space complexity.

## Files Included

- OddEvenLinkedList.cpp
- Outputs/
