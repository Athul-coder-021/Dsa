// ----------------Vertical Order Traversal of a Binary Tree----------------------

// Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

// For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).

// The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from 
// the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. 
// In such a case, sort these nodes by their values.

// Return the vertical order traversal of the binary tree.



// Solution code:

#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    // Function to perform vertical order traversal
    // and return a 2D vector of node values
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        // Map to store nodes based on
        // vertical and level information
        map<int, map<int, multiset<int>>> nodes;

        // Queue for BFS traversal, each
        // element is a pair containing node
        // and its vertical and level information
        queue<pair<TreeNode *, pair<int, int>>> todo;

        // Push the root node with initial vertical
        // and level values (0, 0)
        todo.push({root, {0, 0}});

        // BFS traversal
        while (!todo.empty())
        {
            // Retrieve the node and its vertical
            // and level information from
            // the front of the queue
            auto p = todo.front();
            todo.pop();
            TreeNode *temp = p.first;

            // Extract the vertical and level information
            // x -> vertical
            int x = p.second.first;
            // y -> level
            int y = p.second.second;

            // Insert the node value into the
            // corresponding vertical and level
            // in the map
            nodes[x][y].insert(temp->val);

            // Process left child
            if (temp->left)
            {
                todo.push({temp->left,
                           {// Move left in
                            // terms of vertical
                            x - 1,
                            // Move down in
                            // terms of level
                            y + 1}});
            }

            // Process right child
            if (temp->right)
            {
                todo.push({temp->right,
                           {// Move right in
                            // terms of vertical
                            x + 1,
                            // Move down in
                            // terms of level
                            y + 1}});
            }
        }

        // Prepare the final result vector
        // by combining values from the map
        vector<vector<int>> ans;
        for (auto p : nodes)
        {
            vector<int> col;
            for (auto q : p.second)
            {
                // Insert node values
                // into the column vector
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            // Add the column vector
            // to the final result
            ans.push_back(col);
        }
        return ans;
    }
};