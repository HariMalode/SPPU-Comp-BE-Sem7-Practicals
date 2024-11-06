// Write a program non-recursive and recursive program to calculate Fibonacci numbers and
// analyze their time and space complexity.

#include <iostream>
using namespace std;

// Iterative function to calculate Fibonacci number and count steps
int fibonacciIterative(int n, int &count) {
    if (n <= 1) {
        count = 0;  // No steps needed for n = 0 or n = 1
        return n;
    }

    int a = 0, b = 1;
    count = 0;

    for (int i = 2; i <= n; i++) {
        int temp = a + b;
        a = b;
        b = temp;
        count++;  // Increment step count in each iteration
    }
    
    return b;  // Return the nth Fibonacci number
}

// Recursive function to calculate Fibonacci number and count steps
int fibonacciRecursive(int n, int &count) {
    count++;  // Increment step count for each recursive call

    if (n <= 1) {
        return n;
    } else {
        return fibonacciRecursive(n - 1, count) + fibonacciRecursive(n - 2, count);  // Recursive calls
    }
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    int countIterative = 0;
    int fibIterative = fibonacciIterative(n, countIterative);
    cout << "Fibonacci number (iterative): " << fibIterative << endl;
    cout << "Step count (iterative): " << countIterative << endl;

    int countRecursive = 0;
    int fibRecursive = fibonacciRecursive(n, countRecursive);
    cout << "Fibonacci number (recursive): " << fibRecursive << endl;
    cout << "Step count (recursive): " << countRecursive << endl;

    return 0;
}

/*
### Explanation of the Program

This code calculates Fibonacci numbers and step counts using both iterative and recursive methods without using `pair`.

1. **fibonacciIterative(int n, int &count)**:
   - Uses an iterative approach to calculate the Fibonacci number.
   - The `count` variable, passed by reference, keeps track of the steps.
   - Returns the nth Fibonacci number, with the step count recorded in `count`.
   - **Time Complexity**: \(O(n)\)
   - **Space Complexity**: \(O(1)\)

2. **fibonacciRecursive(int n, int &count)**:
   - Uses a recursive approach to calculate the Fibonacci number.
   - `count` is incremented with each recursive call to track the step count.
   - Returns the nth Fibonacci number, with the step count recorded in `count`.
   - **Time Complexity**: \(O(2^n)\)
   - **Space Complexity**: \(O(n)\)

3. **Main Execution**:
   - Takes user input for `n`.
   - Calls `fibonacciIterative()` and `fibonacciRecursive()`.
   - Prints the Fibonacci numbers and step counts for both methods.

This demonstrates how to calculate Fibonacci numbers without `pair`, instead using separate variables for each result.



The Fibonacci series (or Fibonacci sequence) is a sequence of numbers in which each number is the sum of the two preceding ones, usually starting with 0 and 1. Mathematically, the Fibonacci series is defined as:

\[
F(n) = F(n-1) + F(n-2)
\]

where:
- \( F(0) = 0 \)
- \( F(1) = 1 \)

Using this definition, the first few terms of the Fibonacci series are:

\[
0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, \dots
\]

In this series:
- **0 and 1** are the first two numbers.
- Each subsequent number is obtained by adding the previous two numbers.

### Examples
1. \( F(2) = F(1) + F(0) = 1 + 0 = 1 \)
2. \( F(3) = F(2) + F(1) = 1 + 1 = 2 \)
3. \( F(4) = F(3) + F(2) = 2 + 1 = 3 \)
4. \( F(5) = F(4) + F(3) = 3 + 2 = 5 \)

### Properties
- **Applications**: Fibonacci numbers appear in natural phenomena such as the arrangement of leaves, branching of trees, the arrangement of seeds, and in mathematical concepts such as the Golden Ratio.
- **Growth**: The Fibonacci series grows exponentially, and the ratio of successive terms approaches the Golden Ratio (approximately 1.618) as the numbers get larger.

*/