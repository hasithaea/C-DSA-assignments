# Circular Queue Implementation in C

> **Assignment 4 | Question 3**

## Overview

This program implements a **Circular Queue** using a fixed-size array in C. Unlike a linear queue, a circular queue connects the last position back to the first position, effectively overcoming memory wastage caused by simple incrementing pointers.

The implementation maintains a capacity of **10 elements** (`SIZE = 10`) and utilizes a circular increment helper function to wrap indices around when they reach array boundaries.

## Features

The following circular queue operations are implemented:

* `init()` – Initializes the circular queue structure.
* `isEmpty()` – Checks whether the queue contains zero elements (`size == 0`).
* `isFull()` – Checks whether the queue has reached max capacity (`size == SIZE`).
* `increment()` – Helper function to circularly increment array indices using modulo/wrap logic.
* `enqueue()` – Inserts an element at the circularly updated `rear` position.
* `dequeue()` – Removes and returns an element from the circularly updated `front` position.
* `getFront()` – Retrieves the front element without dequeuing.
* `display()` – Displays all stored elements from `front` to `rear`.

## Data Structure

```c
typedef struct {
    int size;       // Tracks current number of elements
    int front;      // Index pointing to the front of the queue
    int rear;       // Index pointing to the rear of the queue
    int data[SIZE]; // Fixed-size array (SIZE = 10)
} queue;
```

## Queue Operations

### Circular Insertion (Enqueue)

When `rear` reaches the end of the array, the `increment()` function wraps it back to index `0` if space is available (`size < SIZE`).

```text
Before: [ 10 | 20 | 30 | 40 | 50 | 60 | 70 | 80 | 90 | 100 ]
Dequeued: 3 items (front advances)
Insert: 110 (wraps around to index 0)

After:  [ 110 | 20 | 30 | 40 | 50 | 60 | 70 | 80 | 90 | 100 ]
```

### FIFO Principle in Circular Structure

```text
Logical View:  (front) [40] → [50] → ... → [100] → [110] (rear)
Physical Array: Wrap-around enables reusing freed slots at index 0..2
```

## Program Flow / Test Trace

1. **Initialization**: Queue is initialized with `front = 0`, `rear = -1`, `size = 0`.
2. **Fill Queue**: Inserts 10 elements into the queue to make it full.
3. **Display**: Prints all 10 elements.
4. **Dequeue (3 items)**: Removes 3 elements from the front, advancing `front` to index 3 and freeing space at indices 0, 1, and 2.
5. **Display**: Displays remaining 7 elements.
6. **Re-enqueue**: Inserts new elements that wrap around to occupy the newly freed positions at indices 0, 1, and 2 without linear overflow errors.

## Notes

* Unlike linear queues, `isFull()` evaluates `size == SIZE` rather than `rear == SIZE - 1`.
* The `increment()` function wraps around when `x + 1 == SIZE` by setting index back to `0`.
* Circular queues optimize space utilization by reusing indices freed by dequeue operations.

## Concepts Used

* Arrays & Index Wrap-around Logic
* Structures (`struct`)
* Enumerations (`enum`) for custom boolean flags
* Circular Queue Data Structure (FIFO)
* Pointer Manipulation in C

## Academic Context

This program was developed as part of the **CSC1223 – Data Structures and Algorithms** course in the **Bachelor of Computer Science** degree program at the University of Ruhuna, Sri Lanka.