# NSUEM-PDS_HW

* Русская версия документации README_RUS.md

## Lecture 1

### Project Description

This repository contains the implementation of abstract data structures in C++: stack, queue, list, and set. All data structures are implemented using arrays and support basic operations.

### Stack

The stack is implemented using an array and includes the following operations:

* `push(value)` - adds an element to the top of the stack.
* `pop()` - removes the element from the top of the stack.
* `last()` - returns the element at the top of the stack without removing it.
* `isEmpty()` - checks if the stack is empty.
* `print()` - prints the contents of the stack.

### Queue

The queue is implemented using an array with element shifting. Supported operations:

* `enqueue(value)` - adds an element to the end of the queue.
* `dequeue()` - removes the element from the beginning of the queue.
* `first()` - returns the first element of the queue without removing it.
* `isEmpty()` - checks if the queue is empty.
* `print()` - prints the contents of the queue.

### List

The list is implemented using an array and supports adding and removing elements with shifting:

* `add(value)` - adds an element to the list.
* `remove(index)` - removes the element at the specified index.
* `print()` - prints the contents of the list.

### Set

The set is implemented using an array with element marking. Basic operations:

* `add(value)` - adds an element to the set (if it doesn't exist).
* `remove(value)` - removes the element from the set (if it exists).
* `contains(value)` - checks if the element is in the set.
* `print()` - prints the contents of the set.

## Lecture 2

* `linear_search.h`: implementation of linear search in an array.
* `binary_search.h`: implementation of binary search in an array.
* `search_comparison.h`: implementation of search algorithm comparison.
* `main.cpp`: main program that demonstrates the search algorithms.

## Algorithm Description

* **Linear Search**: this algorithm works by sequentially scanning the elements of the array and comparing each element with the target value. If the element is found, the algorithm returns the index of the element.
* **Binary Search**: this algorithm works by dividing the array into two parts and comparing the middle element with the target value. If the middle element is equal to the target value, the algorithm returns the index of the element. If the middle element is less than the target value, the algorithm repeats for the right part of the array. If the middle element is greater than the target value, the algorithm repeats for the left part of the array.

## Lecture 3

* **Performance Measurement and Visualization**

This section of the code is designed to measure the performance of various algorithms for checking if a number is prime and for computing the greatest common divisor (GCD). The results are then visualized using colored backgrounds to indicate the relative performance of each algorithm.

## lecture 4

* **Recursive Functions**

This is a program that demonstrates the use of recursive functions in various scenarios. The program includes tests for different recursive functions, as well as timing tests to compare the performance of recursive and iterative functions.

* **Recursive Functions**

The program includes three packages with recursive functions:

* `RecursiveFunc`: This package contains recursive functions for calculating the sum of digits of a number, the sum of numbers from 0 to a given number, the Fibonacci number at a given position, and the factorial of a number.
* `RecursiveProc`: This package contains recursive procedures for printing numbers from 1 to a given number, from a given number to 1, and from -a given number to a given number.
* `RecursiveFromTwoArgs`: This package contains recursive functions for calculating the Euclidean algorithm, the power of a number, and the factorial of a number.

* **Timing Tests**

The program includes timing tests to compare the performance of recursive and iterative functions. The tests measure the time it takes to calculate the Fibonacci number at a given position using different approaches:

* `Fibonacci`: Recursive function without optimization
* `FibonacciMemoized`: Recursive function with caching
* `FibonacciIterativeArray`: Iterative function with a temporary array
* `FibonacciIterativeOnTheFly`: Iterative function with on-the-fly calculation

## Installation

1. Clone the repository:

   ```bash
   git clone https://github.com/freeeakn/NSUEM-PDS_HW
   cd NSUEM-PDS_HW
   ```

2. Compile the project:

      ```bash
      make
      ```

## Usage

Example usage of each data structure can be found in the `main.cpp` file.

## Author

This program was developed by Arthur Pechenkin, a third-year student, as part of the "Programming of Discrete Structures" course, in C++.

Contact information:

* Arthur [@machinee](https://github.com/freeeakn)

## License

This project is licensed under the MIT License. Please see the LICENSE file for more information.

---

## Note

* ***Make sure you have a C++ compiler (e.g., g++) installed to compile and run the project.***
* ***Make sure you have a golang compiler (go) installed to run the project.***
