# Stack Using Queue

## Aim
To implement a Stack (LIFO) using Queue data structure.

## Problem Statement
Implement a stack using queue(s) that supports the following operations:
- Push
- Pop
- Top
- Empty

## Algorithm

1. Create queue(s).
2. For **Push**, insert the new element into the queue.
3. Rearrange the queue so that the newly inserted element comes to the front.
4. For **Pop**, remove the front element of the queue.
5. For **Top**, return the front element without removing it.
6. For **Empty**, check whether the queue is empty.

## Operations

### Push(x)
- Inserts an element into the stack.

### Pop()
- Removes and returns the top element.

### Top()
- Returns the top element without removing it.

### Empty()
- Returns **true** if the stack is empty; otherwise **false**.

## Time Complexity

| Operation | Complexity |
|-----------|------------|
| Push | O(n) |
| Pop | O(1) |
| Top | O(1) |
| Empty | O(1) |

## Space Complexity

- **O(n)**

## Sample Input

```
1
10
1
20
3
2
4
5
```

## Sample Output

```
1. Push
2. Pop
3. Top
4. Empty
5. Exit

Enter Choice: 1
Enter Element: 10
Element Pushed Successfully!

Enter Choice: 1
Enter Element: 20
Element Pushed Successfully!

Enter Choice: 3
Top Element: 20

Enter Choice: 2
Popped Element: 20

Enter Choice: 4
Stack is Not Empty

Enter Choice: 5
Program Ended
```

## Learning Outcomes

- Understand the implementation of Stack using Queue.
- Learn the LIFO (Last In First Out) principle.
- Understand queue manipulation techniques.
- Analyze time and space complexity of stack operations.
