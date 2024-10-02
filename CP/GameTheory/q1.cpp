//DP solution
// https://codeforces.com/contest/2005/problem/E1

#include <iostream>
#include <vector>
using namespace std;

// Recursive function with memoization
auto solve = [&](int i, int j, int k, auto &&F, const vector<vector<int>>& g, const vector<int>& arr, vector<vector<vector<int>>>& dp, int n, int m, int l) -> int {
    // Base case: if we reach the last row or column, or the end of the array
    if (i == n || j == m || k == l) return 0;

    // If we already computed this state, return it
    if (dp[i][j][k] != -1) return dp[i][j][k];

    // Case 1: Not taking the current element, moving either right or down
    int notTake = max(F(i + 1, j, k, F, g, arr, dp, n, m, l), F(i, j + 1, k, F, g, arr, dp, n, m, l));

    // Case 2: Taking the current element, moving diagonally if it matches
    int take = (g[i][j] == arr[k]) * (!F(i + 1, j + 1, k + 1, F, g, arr, dp, n, m, l));

    // Memoize the result
    return dp[i][j][k] = (notTake || take);
};

int main() {
    int tt; // Number of test cases
    cin >> tt;
    
    while (tt--) {
        int l, n, m; // Length of array, number of rows, and number of columns
        cin >> l >> n >> m;
        
        vector<int> arr(l); // Array to search for
        for (auto &i : arr) cin >> i;
        
        vector<vector<int>> g(n, vector<int>(m)); // Matrix of integers
        for (auto &i : g) {
            for (auto &j : i) cin >> j;
        }
        
        // DP table for memoization, initialized to -1 (meaning "uncomputed")
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(l, -1)));
        
        // Use lambda to pass recursive function
        auto F = solve; 
        
        // Start searching from top-left (0, 0) and first element of array (0)
        bool result = F(0, 0, 0, F, g, arr, dp, n, m, l);
        
        // Output the result: "T" if Tsovak wins, "N" if Narek wins
        if (result) {
            cout << "T" << endl;
        } else {
            cout << "N" << endl;
        }
    }

    return 0;
}
