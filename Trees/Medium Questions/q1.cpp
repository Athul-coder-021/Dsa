// ------------Top View of Binary Tree-------------

// It uses Concept of "Vertical Order Traversal of a Binary Tree"

// Given below is a binary tree. The task is to print the top view of binary tree.
//  Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. For the given below tree

//        1
//     /     \
//    2       3
//   /  \    /   \
// 4    5  6       7

// Top view will be: 4 2 1 3 7
// Note: Return nodes from leftmost node to rightmost node.
// Also if 2 nodes are outside the shadow of the tree and are at same position then consider the left ones only(i.e. leftmost).
// For ex - 1 2 3 N 4 5 N 6 N 7 N 8 N 9 N N N N N will give 8 2 1 3 as answer. Here 8 and 9 are on the same position but 9 will get shadowed.

// Solution Code

#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node() : data(0), left(nullptr), right(nullptr) {}
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
};

class Solution
{
public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        // Your code here
        vector<int> ans;
        if (root == NULL)
        {
            return ans;
        }
        map<int, int> mp;           // store only one node from one level
        queue<pair<Node *, int>> q; // BFS
        q.push({root, 0});

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            Node *node = it.first;
            int line = it.second;

            if (mp.find(line) == mp.end())
            {
                mp[line] = node->data;
            }
            if (node->left != NULL)
            {
                q.push({node->left, line - 1});
            }
            if (node->right != NULL)
            {
                q.push({node->right, line + 1});
            }
        }

        for (auto it : mp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};