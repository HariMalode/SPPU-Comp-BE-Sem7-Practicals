# 3.Write a program to solve a fractional Knapsack problem using a greedy method.

Sure! Here are concise definitions:

### Greedy Technique
The **greedy technique** is an algorithmic approach that makes the locally optimal choice at each step to achieve the best overall solution. It’s often used in optimization problems where making immediate, best choices leads to an optimal or near-optimal solution. Ex, Huffman Coding, Dijkstra’s Algorithm.

### Knapsack Problem (knapsack -bag)
The **knapsack problem** is an optimization problem where, given a set of items with specific weights and values, the goal is to maximize the total value in a knapsack with a weight capacity. There are two main types: the **0/1 knapsack** (items can’t be split) and the **fractional knapsack** (items can be divided).
Ratio = profit/weight

### Conceptual Questions

1. **Explain the difference between the 0/1 knapsack and the fractional knapsack problem.**
   - *Expected Answer:* In the 0/1 knapsack problem, you cannot take fractions of items; each item can either be fully included or excluded. In contrast, the fractional knapsack problem allows taking fractions of items to maximize the knapsack’s total value.

2. **Why do we use a greedy algorithm for the fractional knapsack problem?**
   - *Expected Answer:* A greedy algorithm works well for the fractional knapsack problem because we can achieve an optimal solution by always taking the item with the highest value-to-weight ratio first. This strategy guarantees the highest value as long as we can take fractions of items.

3. **Why are we sorting items in different ways in each function? What’s the impact of each sorting strategy?**
   - *Expected Answer:* Sorting by value-to-weight ratio maximizes the value we get per unit of weight, which is generally optimal for fractional knapsack. Sorting by weight prioritizes lighter items, which may fill the knapsack faster but not necessarily with maximum value. Sorting by value maximizes the total value added but may fill the knapsack with heavier items.

### Coding and Implementation Questions

4. **What is the time complexity of each function? Why?**
   - *Expected Answer:* The time complexity of each function is \(O(n \log n)\) because sorting the items takes \(O(n \log n)\), and iterating through the items afterward takes \(O(n)\).

5. **What is the purpose of the comparison functions, and how does `sort` use them?**
   - *Expected Answer:* The comparison functions define the sorting criteria for the `sort` function. For example, `compareByRatio` sorts items by value-to-weight ratio in descending order. The `sort` function uses these custom comparison functions to order items as specified.

6. **Why do you use `double` for total value but `int` for capacity and weights?**
   - *Expected Answer:* The total value can have fractional values because we take fractions of items, so we use `double` to capture the precise value. Capacity and weights are generally whole numbers, so `int` is sufficient for them.

7. **What would happen if you didn’t break out of the loop after adding a fractional item?**
   - *Expected Answer:* If we don’t break the loop after adding a fractional item, the code would incorrectly add values from subsequent items, leading to an incorrect result.

### Optimization and Edge Cases

8. **How would the algorithm behave if all items have the same value-to-weight ratio?**
   - *Expected Answer:* If all items have the same ratio, the sorting order won’t impact the result, and we can add items in any order until the knapsack is full.

9. **What edge cases should be considered in this problem?**
   - *Expected Answer:* Some edge cases include:
     - The knapsack has a capacity of 0.
     - There are no items to add.
     - All items have a weight greater than the knapsack's capacity.
     - All items have a very low or very high value-to-weight ratio.

10. **Could you modify the code to handle negative values or weights? Why or why not?**
    - *Expected Answer:* In general, values and weights are non-negative in knapsack problems. Negative weights could lead to infinite capacity issues, and negative values don’t make sense as we aim to maximize value.

Being prepared for these questions will help you showcase both the technical understanding of the code and your knowledge of the greedy algorithm and knapsack problem nuances. Good luck!