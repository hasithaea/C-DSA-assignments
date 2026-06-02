# Palindrome Checker Using Stack (Array-Based Implementation)

## Description

This program checks whether a given word is a **palindrome** using an array-based stack in C.

A palindrome is a sequence that reads the same forward and backward (e.g., *level*, *madam*). The program pushes each character of the word onto a stack and then pops them to form the reversed string. If the original word and reversed word are the same, the word is a palindrome.

## Concepts Used

* Arrays
* Structures (`struct`)
* Stack Data Structure
* Push and Pop operations
* String handling (`strcmp`, `strlen`)
* Palindrome logic

## Stack Operations Implemented

* `init()` – Initializes the stack.
* `push()` – Inserts a character onto the stack.
* `pop()` – Removes and returns the top character.
* `isEmpty()` – Checks if the stack is empty.
* `isFull()` – Checks if the stack is full.

## Algorithm

1. Initialize an empty stack.
2. Read a word from the user.
3. Traverse the word and push each character into the stack.
4. Pop all characters from the stack and store them in a new string.
5. Compare the original word with the reversed string using `strcmp()`.
6. If both are equal → the word is a palindrome.
   Otherwise → it is not a palindrome.

## Sample Input

```text
Enter a word to check palindrome or not : madam
```

## Sample Output

```text 
madam is a palindrome
```

## Example Explanation

For the input **"madam"**:

### Step 1: Push into stack

```
m → a → d → a → m
```

### Step 2: Pop from stack

```
m a d a m
```

Reversed string matches the original string.

## Academic Context

This program was developed as part of the **CSC1223 – Data Structures and Algorithms** course in the **Bachelor of Computer Science** degree program at the University of Ruhuna, Sri Lanka.
