#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to solve the 0-1 Knapsack problem using dynamic programming
int knapsack(int W, const vector<int>& weights, const vector<int>& values, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= W; ++w) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {
    int W = 50; // Maximum weight of knapsack
    vector<int> weights = {10, 20, 30}; // Weights of items
    vector<int> values = {60, 100, 120}; // Values of items
    int n = weights.size(); // Number of items

    cout << "Maximum value in Knapsack = " << knapsack(W, weights, values, n) << endl;

    return 0;
}