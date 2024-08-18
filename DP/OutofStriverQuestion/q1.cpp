// Maximum Number of Points with Cost
// You are given an m x n integer matrix points (0-indexed).
// Starting with 0 points, you want to maximize the number of points you can get from the matrix.

// To gain points, you must pick one cell in each row. 
// Picking the cell at coordinates (r, c) will add points[r][c] to your score.

// However, you will lose points if you pick a cell too far from the cell that you picked in the previous row.
// For every two adjacent rows r and r + 1 (where 0 <= r < m - 1), 
// picking cells at coordinates (r, c1) and (r + 1, c2) will subtract abs(c1 - c2) from your score.

// Return the maximum number of points you can achieve.

// abs(x) is defined as:

// x for x >= 0.
// -x for x < 0.


//Good DP question - tabulation ( here we are doing double tabulation)

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size();
        int n = points[0].size();

        // DP table to store the maximum points for each cell
        vector<vector<long long>> dp(m, vector<long long>(n, 0));

        // Initialize the first row of the DP table
        for (int c = 0; c < n; c++) {
            dp[0][c] = points[0][c];
        }

        // Fill the DP table row by row
        for (int r = 1; r < m; r++) {
            // Create a temporary array for the current row to store the best values
            vector<long long> left_max(n, 0), right_max(n, 0);

            // Fill left_max array: best value we can get moving from left to right
            left_max[0] = dp[r - 1][0];
            for (int c = 1; c < n; c++) {
                left_max[c] = max(left_max[c - 1] - 1, dp[r - 1][c]);
            }

            // Fill right_max array: best value we can get moving from right to left
            right_max[n - 1] = dp[r - 1][n - 1];
            for (int c = n - 2; c >= 0; c--) {
                right_max[c] = max(right_max[c + 1] - 1, dp[r - 1][c]);
            }

            // Fill the current row of the DP table using left_max and right_max
            for (int c = 0; c < n; c++) {
                dp[r][c] = points[r][c] + max(left_max[c], right_max[c]);
            }
        }

        // The maximum points will be the maximum value in the last row
        return *max_element(dp[m - 1].begin(), dp[m - 1].end());
    }
};