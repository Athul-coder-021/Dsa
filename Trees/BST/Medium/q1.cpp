// Kth smallest and Kth largest element optimal way

// Algorithm / Intuition
// A more efficient approach for finding the K-th smallest and K-th largest elements in a Binary Search Tree (BST) without using extra space would involve an optimised traversal technique directly targeting the K-th elements without storing all elements in an array. We use two traversal methods (inorder and reverse inorder) to find the Kth smallest and largest elements in the given BST. We maintain a counter variable to track the number of visited nodes, stopping when the Kth element is found in each traversal.

// Algorithm for Kth Smallest Element:

// Step 1: Perform inorder traversal from the root node. At every visited node, increment a counter variable to keep track of visited nodes. Inorder Traversal: Traverse the left subtree, then current node then right subtree.

// Step 2: When the counter reaches K, store the value of the current node as the Kth smallest.

// Step 3: Return this value as the Kth smallest.


// Algorithm for Kth Largest Element:

// Step 1: Perform reverse inorder traversal from the root node. At every visited node, increment a counter variable to keep track of visited nodes. Traverse the right subtree, then current node then left subtree.

// Step 2: When the counter reaches K, store the value of the current node as the Kth smallest.


// Step 3: Return this value as the Kth largest.







#include <iostream>
#include <vector>
#include <climits> 
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
    // Helper function to perform reverse inorder
    // traversal to find Kth largest element
    void reverseInorder(TreeNode* node, int& counter, int k, int& kLargest) {
        if (!node || counter >= k) return;

        // Traverse right subtree
        reverseInorder(node->right, counter, k, kLargest);

        // Increment counter after
        // visiting right subtree
        counter++;

        // Check if current node
        // is the Kth largest
        if (counter == k) {
            kLargest = node->val;
            return;
        }

        // Traverse left subtree if
        // Kth largest is not found yet
        reverseInorder(node->left, counter, k, kLargest);
    }

    // Helper function to perform inorder
    // traversal to find Kth smallest element
    void inorder(TreeNode* node, int& counter, int k, int& kSmallest) {
        if (!node || counter >= k) return;

        // Traverse left subtree
        inorder(node->left, counter, k, kSmallest);

        // Increment counter after visiting left subtree
        counter++;

        // Check if current node is the Kth smallest
        if (counter == k) {
            kSmallest = node->val;
            return;
        }

        // Traverse right subtree if
        // Kth smallest is not found yet
        inorder(node->right, counter, k, kSmallest);
    }

public:
    pair<int, int> findKth(TreeNode* root, int k) {
        int kSmallest = INT_MIN, kLargest = INT_MIN;
        // Counter to track visited nodes
        int counter = 0; 

        // Find Kth smallest element
        // (perform inorder traversal)
        inorder(root, counter, k, kSmallest);
        
        // Reset counter for Kth largest element
        counter = 0; 
        // Find Kth largest element
        // (perform reverse inorder traversal)
        reverseInorder(root, counter, k, kLargest);

        return make_pair(kSmallest, kLargest);
    }
};





// Function to perform an in-order traversal
// of a binary tree and print its nodes
void printInOrder(TreeNode* root) {
    // Check if the current node
    // is null (base case for recursion)
    if (root == nullptr) {
        // If null, return and
        // terminate the function
        return;
    }

    // Recursively call printInOrder
    // for the left subtree
    printInOrder(root->left);

    // Print the value of the current node
    cout << root->val << " ";

    // Recursively call printInOrder
    // for the right subtree
    printInOrder(root->right);
}

int main() {
    // Creating a BST
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(13);
    root->left->left = new TreeNode(3);
    root->left->left->left = new TreeNode(2);
    root->left->left->right = new TreeNode(4);
    root->left->right = new TreeNode(6);
    root->left->right->right = new TreeNode(9);
    root->right->left = new TreeNode(11);
    root->right->right = new TreeNode(14);
    
    cout << "Binary Search Tree: "<< endl;
    printInOrder(root);
    cout << endl;
    
  
    
    Solution solution;

    // Find the Kth smallest and largest elements
    int k = 3; 
    cout << "k: "<< k <<endl;
    pair<int, int> kthElements = solution.findKth(root, k);

    cout << "Kth smallest element: " << kthElements.first << endl;
    cout << "Kth largest element: " << kthElements.second << endl;

    return 0;
}
                                
                            