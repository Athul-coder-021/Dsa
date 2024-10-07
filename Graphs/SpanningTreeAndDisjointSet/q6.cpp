//  Swim in Rising Water

// You are given an n x n integer matrix grid where each value grid[i][j] represents the elevation at that point (i, j).

// The rain starts to fall. At time t, the depth of the water everywhere is t. You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both squares individually are at most t. You can swim infinite distances in zero time. Of course, you must stay within the boundaries of the grid during your swim.

// Return the least time until you can reach the bottom right square (n - 1, n - 1) if you start at the top left square (0, 0).

 

// Example 1:


// Input: grid = [[0,2],[1,3]]
// Output: 3
// Explanation:
// At time 0, you are in grid location (0, 0).
// You cannot go anywhere else because 4-directionally adjacent neighbors have a higher elevation than t = 0.
// You cannot reach point (1, 1) until time 3.
// When the depth of water is 3, we can swim anywhere inside the grid.
// Example 2:


// Input: grid = [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
// Output: 16
// Explanation: The final route is shown.
// We need to wait until time 16 so that (0, 0) and (4, 4) are connected.
 

// Constraints:

// n == grid.length
// n == grid[i].length
// 1 <= n <= 50
// 0 <= grid[i][j] < n2
// Each value grid[i][j] is unique.

//logic was mine coded by chatpgt
// what i am thinking is to apply disjoint set as at every instance the graph movement will be changing
// in this first each cell will be node a node of graph
// at every time t we will check what will be the ultimate parent of cell (n-1,m-1)
// if it matches 0,0 we stop and return t
// otherwise we will join the nodes according to 4 direction
// like
// in 2nd example
// node 1,2,3,4,5 will be connected to 0
// but at 6 it willbe alone
// then
// 7,8,9,10,11,12,13,14,15 will be connected to 6
// then 16 will join both domain
// then we get ultimate parent of 6 as 0
// or say of 0 as 6


// #include<bits/stdc++.h>
// using namespace std;
// class DisjointSet {
//     vector<int> parent, size; 
// public:
//     DisjointSet(int n) {
//         parent.resize(n + 1);
//         size.resize(n + 1);
//         for (int i = 0; i <= n; i++) {
//             parent[i] = i;
//             size[i] = 1;
//         }
//     }

//     int findUPar(int node) {
//         if (node == parent[node])
//             return node;
//         return parent[node] = findUPar(parent[node]);  // Path compression
//     }

//     void unionBySize(int u, int v) {
//         int ulp_u = findUPar(u);
//         int ulp_v = findUPar(v);
//         if (ulp_u == ulp_v) return;
//         if (size[ulp_u] < size[ulp_v]) {
//             parent[ulp_u] = ulp_v;
//             size[ulp_v] += size[ulp_u];
//         } else {
//             parent[ulp_v] = ulp_u;
//             size[ulp_u] += size[ulp_v];
//         }
//     }
// };
// class Solution{
//     public:
// int swimInWater(vector<vector<int>>& grid) {
//     int n = grid.size();
//     vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

//     // List of all cells (i, j) in the grid, sorted by their elevation values
//     vector<tuple<int, int, int>> cells;
//     for (int i = 0; i < n; ++i) {
//         for (int j = 0; j < n; ++j) {
//             cells.push_back({grid[i][j], i, j});
//         }
//     }
//     sort(cells.begin(), cells.end());  // Sort by elevation

//     // Initialize the disjoint set for n*n elements (1D mapping of grid)
//     DisjointSet ds(n * n);

//     // Lambda function to convert 2D coordinates to 1D index
//     auto index = [n](int x, int y) {
//         return x * n + y;
//     };

//     // Iterate through the sorted cells by their elevation
//     for (auto& [elevation, i, j] : cells) {
//         // Check all 4 possible neighbors and union the current cell with any neighbor
//         // that has already been "flooded" (i.e., its elevation <= current elevation)
//         for (auto& dir : directions) {
//             int ni = i + dir[0], nj = j + dir[1];
//             if (ni >= 0 && ni < n && nj >= 0 && nj < n && grid[ni][nj] <= elevation) {
//                 ds.unionBySize(index(i, j), index(ni, nj));
//             }
//         }

//         // After processing the current cell, check if the top-left (0, 0) is connected to the
//         // bottom-right (n - 1, n - 1)
//         if (ds.findUPar(index(0, 0)) == ds.findUPar(index(n - 1, n - 1))) {
//             return elevation;
//         }
//     }

//     return -1;  // Fallback (should not be reached)
// }
// };