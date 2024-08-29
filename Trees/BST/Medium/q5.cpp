// Two Sum IV - Input is a BST

// Given the root of a binary search tree and an integer k,
//  return true if there exist two elements in the BST such that their 
// sum is equal to k, or false otherwise.

// Example 1:
// Input: root = [5,3,6,2,4,null,7], k = 9
// Output: true

// Example 2:
// Input: root = [5,3,6,2,4,null,7], k = 28
// Output: false
 

// Constraints:

// The number of nodes in the tree is in the range [1, 104].
// -10^4 <= Node.val <= 10^4
// root is guaranteed to be a valid binary search tree.
// -10^5 <= k <= 10^5

// In this we have used BST Iterator for next() (l)  and 
// reverse BST Iterator for before (r)
// Once l and r got then normal 2 sum.

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

class BSTIterator{
    stack<TreeNode*>myStack;
    //if reverse true then before(reverse inorder)
    //if reverse false then next(inorder)

    bool reverse = true;
public:
    BSTIterator(TreeNode*root,bool isReverse)
    {
        reverse = isReverse;
        pushAll(root);
    }
    bool hasNext()
    {
        return !myStack.empty();
    }

    int next()
    {
        TreeNode*tempNode = myStack.top();
        myStack.pop();
        if(!reverse)pushAll(tempNode->right);
        else pushAll(tempNode->left);
        return tempNode->val;
    }

private:
    void pushAll(TreeNode*node)
    {
        for(;node!=NULL;)
        {
            myStack.push(node);
            if(reverse == true)
            {
                node = node->right;
            }
            else
            node = node->left;
        }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root)return false;
        //for next
        BSTIterator l(root,false);
        //for before
        BSTIterator r(root,true);

        int i = l.next();
        int j = r.next();//before
        //simple 2 sum
        while(i<j)
        {
            if(i+j ==k)return true;
            else if(i+j<k)i = l.next();
            else j = r.next();//before
        }
        return false;
    }
};