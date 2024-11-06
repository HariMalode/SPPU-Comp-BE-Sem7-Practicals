#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to solve the 0-1 Knapsack problem using dynamic programming
int knapsackDP(int n, const vector<int>& values, const vector<int>& weights, int W) {
    // DP table to store maximum value for each item and weight
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Fill the DP table
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            // If current item weight is less than or equal to the current capacity
            if (weights[i - 1] <= w) {
                // Include the item or exclude it, take the maximum
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            } else {
                // Exclude the item
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // The last cell contains the maximum value we can achieve
    return dp[n][W];
}

// Recursive function to solve the 0-1 Knapsack problem
int recursive(int index, int n, int bagWeight, int profits[], int weights[]) {   
    // Base Case: if the index is 0
    if (index == 0) {
        if (bagWeight >= weights[index]) return profits[index];
        else return 0;
    }

    // Case 1: Skip the item
    int notPick = 0 + recursive(index - 1, n, bagWeight, profits, weights); 
    
    // Case 2: Pick the item, if it fits in the bag
    int pick = -1000000; // Initialize with a large negative value
    if (bagWeight >= weights[index]) {
        pick = profits[index] + recursive(index - 1, n, bagWeight - weights[index], profits, weights);
    }

    // Return the maximum value of picking or not picking the item
    return max(pick, notPick);
}

int main() {
    int n = 3; // Number of items
    vector<int> values = {60, 100, 120};  // Values of items
    vector<int> weights = {10, 20, 30};   // Weights of items
    int W = 50;  // Knapsack capacity

    // Solve the knapsack problem using dynamic programming
    int max_value_dp = knapsackDP(n, values, weights, W);
    cout << "Maximum value (DP approach): " << max_value_dp << endl;

    // Solve the knapsack problem using recursive approach
    int profits[] = {60, 100, 120};  // Values of items
    int weightsArr[] = {10, 20, 30}; // Weights of items
    int max_value_recursive = recursive(n - 1, n, W, profits, weightsArr);
    cout << "Maximum value (Recursive approach): " << max_value_recursive << endl;

    return 0;
}
