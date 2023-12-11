# push_swap

# Overview
Push_Swap is an algorithmic challenge designed to test the efficiency and optimization of sorting algorithms. The core concept revolves around sorting a set of numbers using two stacks, named a and b, with a specific set of allowed operations. The primary goal is to sort the stack a in ascending order with the least number of operations.

# How It Works
Initial Setup:

Stack a is initialized with a random set of integers provided as input.
Stack b starts empty.
Objective:

Sort the integers in stack a in ascending order.
Operations:

Various operations (sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr) are used to manipulate the stacks.
Running the Program
To run the program, compile the source files using the provided Makefile, and then execute push_swap with a list of integers:

bash
Copy code
$> ./push_swap 4 3 2 1
The program will output a series of operations that, when applied, will sort the numbers in stack a.

Error Handling
In case of invalid input (non-integers, duplicates, or numbers too large), the program outputs an "Error" message.

Evaluation and Testing
The program's output can be tested for correctness and efficiency using the checker_OS tool, which validates whether the list of operations successfully sorts the stack and complies with the operation limit.

