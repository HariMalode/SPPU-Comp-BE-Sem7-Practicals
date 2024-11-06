#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Comparison function to sort items by value-to-weight ratio in descending order
bool compareByRatio(pair<int, int> p1, pair<int, int> p2) {
    double v1 = (double)p1.first / p1.second;
    double v2 = (double)p2.first / p2.second;
    return v1 > v2;
}

// Comparison function to sort items by weight in ascending order
bool compareByWeight(pair<int, int> p1, pair<int, int> p2) {
    return p1.second < p2.second;
}

// Comparison function to sort items by value in descending order
bool compareByValue(pair<int, int> p1, pair<int, int> p2) {
    return p1.first > p2.first;
}

// Function to solve the fractional knapsack problem by value-to-weight ratio
double fractionalKnapsackByRatio(const vector<pair<int, int>>& items, int capacity) {
    vector<pair<int, int>> sortedItems = items;
    sort(sortedItems.begin(), sortedItems.end(), compareByRatio);
    
    double totalValue = 0.0;

    for (int i = 0; i < sortedItems.size(); i++) {
        int value = sortedItems[i].first;
        int weight = sortedItems[i].second;

        if (capacity >= weight) {
            totalValue += value;
            capacity -= weight;
        } else {
            totalValue += capacity * ((double)value / weight);
            break;
        }
    }
    return totalValue;
}

// Function to solve the fractional knapsack problem by weight (ascending order)
double fractionalKnapsackByWeight(const vector<pair<int, int>>& items, int capacity) {
    vector<pair<int, int>> sortedItems = items;
    sort(sortedItems.begin(), sortedItems.end(), compareByWeight);
    
    double totalValue = 0.0;

    for (int i = 0; i < sortedItems.size(); i++) {
        int value = sortedItems[i].first;
        int weight = sortedItems[i].second;

        if (capacity >= weight) {
            totalValue += value;
            capacity -= weight;
        } else {
            totalValue += capacity * ((double)value / weight);
            break;
        }
    }
    return totalValue;
}

// Function to solve the fractional knapsack problem by value (descending order)
double fractionalKnapsackByValue(const vector<pair<int, int>>& items, int capacity) {
    vector<pair<int, int>> sortedItems = items;
    sort(sortedItems.begin(), sortedItems.end(), compareByValue);
    
    double totalValue = 0.0;

    for (int i = 0; i < sortedItems.size(); i++) {
        int value = sortedItems[i].first;
        int weight = sortedItems[i].second;

        if (capacity >= weight) {
            totalValue += value;
            capacity -= weight;
        } else {
            totalValue += capacity * ((double)value / weight);
            break;
        }
    }
    return totalValue;
}

int main() {
    // List of items (value, weight)
    vector<pair<int, int>> items = {{60, 10}, {100, 20}, {120, 30}};
    int capacity = 50;  // Maximum weight capacity of the knapsack

    // Calculate the maximum value by each sorting method
    double maxValueRatio = fractionalKnapsackByRatio(items, capacity);
    double maxValueWeight = fractionalKnapsackByWeight(items, capacity);
    double maxValueValue = fractionalKnapsackByValue(items, capacity);

    // Display the results
    cout << "Maximum value by value/weight ratio: " << maxValueRatio << endl;
    cout << "Maximum value by weight: " << maxValueWeight << endl;
    cout << "Maximum value by value: " << maxValueValue << endl;

    return 0;
}
