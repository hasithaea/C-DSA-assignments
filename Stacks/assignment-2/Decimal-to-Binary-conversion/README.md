# Decimal to Binary Conversion Using an Array-Based Stack

## Description

This program converts a decimal number entered by the user into its binary equivalent using an array-based stack implementation in C.

The conversion process repeatedly divides the decimal number by 2 and stores the remainders in a stack. Since a stack follows the **Last In First Out (LIFO)** principle, displaying the stack from top to bottom produces the binary representation in the correct order.

## Concepts Used

* Arrays
* Structures (`struct`)
* Stack Data Structure
* Push Operation
* Pop Operation
* Decimal to Binary Conversion
* Stack Overflow and Underflow Checks

## Stack Operations Implemented

* `init()` – Initializes the stack.
* `push()` – Inserts an element onto the stack.
* `pop()` – Removes and returns the top element.
* `top()` – Returns the top element without removing it.
* `isEmpty()` – Checks whether the stack is empty.
* `isFull()` – Checks whether the stack is full.
* `display()` – Displays the contents of the stack.

## Algorithm

1. Initialize an empty stack.
2. Read a decimal number from the user.
3. Repeat until the number becomes 0:

   * Compute the remainder when divided by 2.
   * Push the remainder onto the stack.
   * Divide the number by 2.
4. Display the stack from top to bottom.
5. The displayed digits form the binary equivalent of the decimal number.

## Sample Input

```text
Enter a decimal number: 13
```

## Sample Output

```text
Binary Number of 13 is
1101
```

## Example Conversion

For the decimal number 13:

| Division | Quotient | Remainder |
| -------- | -------- | --------- |
| 13 ÷ 2   | 6        | 1         |
| 6 ÷ 2    | 3        | 0         |
| 3 ÷ 2    | 1        | 1         |
| 1 ÷ 2    | 0        | 1         |

Remainders are pushed in the order:

```text
1, 0, 1, 1
```

Displaying the stack from top to bottom gives:

```text
1101
```

## Academic Context

This program was developed as part of the **CSC1223 – Data Structures and Algorithms** course in the **Bachelor of Computer Science** degree program at the University of Ruhuna, Sri Lanka.
