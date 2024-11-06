# 1. Write a program non-recursive and recursive program to calculate Fibonacci numbers and analyze their time and space complexity.



### Fibonacci Sequence
The **Fibonacci sequence** is a series of numbers where each term is the sum of the two preceding terms, starting from 0 and 1. Mathematically, it’s defined as:
\[
F(n) = F(n-1) + F(n-2)
\]
with base cases \( F(0) = 0 \) and \( F(1) = 1 \).

### Iterative Approach
An **iterative approach** solves a problem by repeating a set of steps within a loop until a condition is met. In Fibonacci, the iterative method calculates each term in sequence without function calls, typically offering better performance and lower memory usage than recursion.

### Recursive Approach
A **recursive approach** solves a problem by breaking it down into smaller subproblems and calling the same function within itself. In Fibonacci, the recursive method calculates terms by calling the function for the previous two terms until reaching the base cases.

### Conceptual Questions

1. **What is the Fibonacci sequence, and how is it defined?**
   - *Expected Answer:* The Fibonacci sequence is a series where each number is the sum of the two preceding ones, starting with 0 and 1. Mathematically, it’s defined as \( F(n) = F(n-1) + F(n-2) \) with base cases \( F(0) = 0 \) and \( F(1) = 1 \).

2. **What is the difference between the iterative and recursive approaches for calculating Fibonacci numbers?**
   - *Expected Answer:* The iterative approach calculates Fibonacci numbers in a loop, which is efficient with \( O(n) \) time and \( O(1) \) space complexity. The recursive approach, however, uses multiple recursive calls leading to \( O(2^n) \) time complexity and \( O(n) \) space complexity due to call stack usage.

3. **Why does the recursive approach have such high time complexity?**
   - *Expected Answer:* Each recursive call makes two further recursive calls, leading to an exponential growth of calls. This exponential time complexity occurs because each Fibonacci number is recalculated many times.

4. **What are the base cases in the recursive Fibonacci function, and why are they important?**
   - *Expected Answer:* The base cases are \( F(0) = 0 \) and \( F(1) = 1 \). They stop the recursion from running infinitely and provide initial values to build the sequence correctly.

5. **What is the role of the `count` variable in this program?**
   - *Expected Answer:* The `count` variable keeps track of the number of steps or recursive calls made to compute the Fibonacci number, which is helpful to analyze the function's performance.

### Coding and Implementation Questions

6. **Explain the time and space complexity of both functions.**
   - *Expected Answer:* The iterative function has \( O(n) \) time complexity and \( O(1) \) space complexity. The recursive function has \( O(2^n) \) time complexity and \( O(n) \) space complexity due to the recursion stack depth.

7. **Why does the iterative function use two variables (`a` and `b`)?**
   - *Expected Answer:* The variables `a` and `b` represent the last two Fibonacci numbers in the sequence. This reduces memory usage and avoids recalculating previous Fibonacci values.

8. **How would you optimize the recursive function to avoid redundant calculations?**
   - *Expected Answer:* We could use *memoization* to store already calculated Fibonacci numbers, reducing the time complexity to \( O(n) \) by avoiding repeated calculations.

### Edge Cases and Testing Questions

9. **What edge cases should be considered for this Fibonacci program?**
   - *Expected Answer:* Edge cases include when \( n = 0 \) or \( n = 1 \), which are the smallest inputs and should return \( F(0) = 0 \) and \( F(1) = 1 \). Additionally, handling large values of \( n \) is important due to potential stack overflow in the recursive approach.

10. **How would you handle negative input values for `n`?**
    - *Expected Answer:* Since Fibonacci numbers are typically defined for non-negative integers, we could add a check to return an error or handle it appropriately if \( n \) is negative.

### Alternative Implementations

11. **Can you implement the Fibonacci sequence using dynamic programming?**
    - *Expected Answer:* Yes, by storing each Fibonacci number in an array as it’s computed, we can avoid redundant calculations and achieve \( O(n) \) time complexity and \( O(n) \) space complexity.

12. **What is the golden ratio, and how is it related to the Fibonacci sequence?**
    - *Expected Answer:* The ratio of successive Fibonacci numbers approaches the golden ratio (~1.618) as \( n \) becomes large. This ratio appears naturally in many mathematical and real-world phenomena.

These questions cover the algorithmic concepts, time-space analysis, and practical application considerations that could come up in an interview.