# Queue Implementation in C – Operations Demonstration

## Overview

This program demonstrates the practical usage of a **Linear Queue implemented using arrays in C**. The queue follows the **FIFO (First In First Out)** principle.

The queue has a fixed size of **10 elements**, and supports basic operations such as insertion, deletion, and display.

## Objective

Using the previously implemented queue structure and functions, the program performs a sequence of operations to demonstrate how a queue behaves during insertion and deletion.

## Queue Operations Performed

### Step-by-step Tasks:

1. Create a queue of size 10.
2. Insert 6 elements into the queue.
3. Display the current queue.
4. Remove 3 elements from the queue.
5. Display the queue again.
6. Insert 5 additional elements into the queue.
7. Display the final state of the queue.

## Functions Used

* `init()` → Initializes the queue
* `isEmpty()` → Checks if queue is empty
* `isFull()` → Checks if queue is full
* `enqueue()` → Inserts an element into the queue
* `dequeue()` → Removes an element from the queue
* `getFront()` → Retrieves the front element
* `display()` → Displays queue contents

## Data Structure

```c
typedef struct
{
    int size;
    int front;
    int rear;
    int data[SIZE];
} queue;
```

## Important Observation

This implementation uses a **linear queue**.
After multiple insertions and deletions, unused spaces at the front are not reused, which may lead to inefficiency or overflow in some cases.

## Example Flow

```
Insert 6 items → Queue fills partially
Display
Remove 3 items → Front moves forward
Display
Insert 5 items → Rear moves forward
Display
```

