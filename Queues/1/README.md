# Queue Implementation in C

## Overview

This **Linear Queue** is implemented using arrays in the C programming language and follows the First In, **First Out (FIFO)** principle, where the first element inserted is the first one removed.

The implementation uses a fixed-size array with a capacity of **10 elements**.

## Features

The following queue operations are implemented:

* `init()` – Initialize the queue.
* `isEmpty()` – Check whether the queue is empty.
* `isFull()` – Check whether the queue is full.
* `enqueue()` – Insert an element into the queue.
* `dequeue()` – Remove and return the front element.
* `getFront()` – Return the front element without removing it.
* `display()` – Display all elements currently stored in the queue.

## Data Structure

```c
typedef struct
{
    int size;   // Current number of elements in queue
    int front;  // Index of the front element 
    int rear;   // Index of the rear element
    int data[SIZE];    // Array used to store queue elements
} queue;
```

## Queue Operations

### Enqueue

Adds a new element to the rear of the queue.

```text
Before: 10 20 30
Insert: 40

After: 10 20 30 40
```

### Dequeue

Removes the element at the front of the queue.

```text
Before: 10 20 30 40

Removed: 10

After: 20 30 40
```

### FIFO Principle

```text
Insert Order : 10 → 20 → 30

Remove Order : 10 → 20 → 30
```

## Notes

* Queue size is fixed at 10 elements.
* This implementation is a **Linear Queue**.
* Overflow and underflow conditions are handled using `isFull()` and `isEmpty()` checks.

## Concept Used

* Arrays
* Structures in C
* Queue (FIFO)
* Basic pointer manipulation
