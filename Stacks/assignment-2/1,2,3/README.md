# Stack Implementation in C

## Overview

This program implements a **Stack data structure using arrays in C**. The stack follows the **LIFO (Last In First Out)** principle, where the last inserted element is the first one removed.

The stack has a fixed size of **5 elements**.


## Objective

To implement a stack and perform basic stack operations such as insertion, deletion, and display, while demonstrating stack behavior through a simple test program.


## Stack Structure

The stack is defined as:

```c
typedef struct
{
    int data[SIZE];     // Array to store stack elements
    int top;       // Index of the top element 
} stack;
```

## Functions Implemented

### 1. initialize()

Initializes the stack by setting:

* `top = -1`


### 2. push()

Inserts an element into the stack.


### 3. pop()

Removes and returns the top element.


### 4. top()

Returns the current top element without removing it.


### 5. isEmpty()

Checks whether the stack is empty.


### 6. isFull()

Checks whether the stack is full.


### 7. display()

Displays all elements in the stack from top to bottom.


## Stack Operations Demonstration

The program performs the following steps:

1. Initialize the stack
2. Check if stack is empty or full
3. Push one element
4. Check again
5. Push two more elements
6. Display stack contents
7. Pop one element
8. Display stack contents again


## Example Flow

```text
Push: 1
Push: 2
Push: 3

Stack: 3 2 1

Pop: removes 3

Stack: 2 1
```

## Important Concepts

* Stack follows **LIFO (Last In First Out)** order
* `top = -1` means the stack is empty
* `top = SIZE - 1` means the stack is full
* Overflow and underflow conditions are handled using `isFull()` and `isEmpty()`
