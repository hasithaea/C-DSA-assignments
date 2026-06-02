# Reverse a Word Using an Array-Based Stack

## Description

This program reads a word from the user and prints its characters in reverse order using an array-based stack implementation in C.

The stack follows the **Last In First Out (LIFO)** principle. Each character of the word is pushed onto the stack, and when the stack is displayed from top to bottom, the characters appear in reverse order.

## Concepts Used

* Arrays
* Structures (`struct`)
* Stack Data Structure
* Push Operation
* Pop Operation
* Stack Overflow and Underflow Checks
* String Handling

## Stack Operations Implemented

* `init()` – Initializes the stack.
* `push()` – Inserts a character onto the stack.
* `pop()` – Removes and returns the top character.
* `top()` – Returns the top element without removing it.
* `isEmpty()` – Checks whether the stack is empty.
* `isFull()` – Checks whether the stack is full.
* `display()` – Displays the stack contents from top to bottom.

## Algorithm

1. Initialize an empty stack.
2. Read a word from the user.
3. Push each character of the word onto the stack.
4. Display the stack from top to bottom.
5. The displayed output represents the word in reverse order.

## Sample Input

```
Enter a word : hello
```

## Sample Output

```
Display stack
====================
o l l e h
```

## Academic Context

This program was developed as part of the **CSC1223 – Data Structures and Algorithms** course in the **Bachelor of Computer Science** degree program at the University of Ruhuna, Sri Lanka.
