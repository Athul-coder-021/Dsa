// Recover Binary Search Tree

// You are given the root of a binary search tree (BST),
//  where the values of exactly two nodes of the tree were swapped 
// by mistake. Recover the tree without changing its structure.

#include <iostream>
#include <vector>
#include <climits> 
#include<bits/stdc++.h>
using namespace std;

// Definition of TreeNode structure
// for a binary tree node
struct TreeNode {
    // Value of the node
    int val;
    
    // Pointer to the left child node
    TreeNode* left;
    
    // Pointer to the right child node
    TreeNode* right;

    // Constructor to initialize the node with a
    // value and set left and right pointers to null
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution {
private:
    TreeNode* first;
    TreeNode* prev;
    TreeNode* middle;
    TreeNode* last;

void inorder(TreeNode*root)
{
    if(root==NULL)return;

    inorder(root->left);

    if(prev!=NULL && (root->val<prev->val))
    {
        //If this is first violation mark these two node as
        //'first' and 'middle'
        if(first==NULL)
        {
            first = prev;
            middle = root;
        }
        //If this is second violation mark this node as last
        else
        {
            last = root;
        }
    }
    //Mark this node as previous
    prev = root;

    inorder(root->right);
}
public:
    void recoverTree(TreeNode* root) {
        first = middle = last =NULL;
        prev = new TreeNode(INT_MIN);
        inorder(root);
        if(first && last )swap(first->val,last->val);
        else if(first && middle)swap(first->val,middle->val);
    }
};