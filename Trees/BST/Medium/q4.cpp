// Binary Search Tree Iterator



// Implement the BSTIterator class that represents an iterator over the in-order traversal of a binary search tree (BST):

// BSTIterator(TreeNode root) Initializes an object of the BSTIterator class.
//  The root of the BST is given as part of the constructor. 
// The pointer should be initialized to a non-existent number smaller than any element in the BST.
// boolean hasNext() Returns true if there exists a number in the traversal to the right of the pointer, otherwise returns false.
// int next() Moves the pointer to the right, then returns the number at the pointer.
// Notice that by initializing the pointer to a non-existent smallest number, the first call to next() will return the smallest element in the BST.

// You may assume that next() calls will always be valid.
//  That is, there will be at least a next number in the in-order traversal when next() is called.

//Approach 1 : do inorder traversal of the tree and store it in a vector.
//  Then do the functions
// TC: O(1)
// SC: O(n)

//Approach 2 : do inorder traversal of the tree towards left at a time and store in stack and whenever do next() go for next left branches
// TC: O(1)
// SC: O(H) H: height of BT.

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

class BSTIterator {
private:
    stack<TreeNode*> myStack;
    void pushAll(TreeNode* root)
    {
        while(root!=NULL)
        {
            myStack.push(root);
            root = root->left;
        }
    }
public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode * tempNode = myStack.top();
        myStack.pop();
        pushAll(tempNode->right);
        return tempNode->val;
    }
    
    bool hasNext() {
        return !myStack.empty();
    }
};

