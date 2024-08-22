//  Validate Binary Search Tree

// Given the root of a binary tree, determine if it is a valid binary search tree (BST).

// A valid BST is defined as follows:

// The left 
// subtree
//  of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.


// THE RANGE APPROACH

// public:
//     bool isCheck(TreeNode* root, int mini, int maxi) {
//         if (root == NULL)
//             return true;
//         if (root->val >= maxi || root->val <= mini)
//             return false;
//         return isCheck(root->left, mini, root->val)
//         && isCheck(root->right, root->val, maxi);
//     }
//     bool isValidBST(TreeNode* root) { return isCheck(root, LLONG_MIN, LLONG_MAX); }