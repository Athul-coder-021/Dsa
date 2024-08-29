// Largest BST
// Given a binary tree. Find the size of its largest subtree which is a Binary Search Tree.
// Note: Here Size equals the number of nodes in the subtree.

// class NodeValue{
//     public:
//     int maxNode,minNode,maxSize;
    
//     NodeValue(int minNode,int maxNode,int maxSize)
//     {
//         this->maxNode = maxNode;
//         this->minNode = minNode;
//         this->maxSize = maxSize;
//     }
    
// };
// class Solution{
//     private:
//     NodeValue largestBSTSubtreeHelper(Node*root)
//     {
//         //An empty tree is a BST of size 0
//         if(!root)
//         {
//             return NodeValue(INT_MAX,INT_MIN,0);
//         }
        
//         //Post order traversal
//         //Get values from left and right subtree
//         auto left =largestBSTSubtreeHelper(root->left);
//         auto right =  largestBSTSubtreeHelper(root->right);
        
//         //Current node is greater than max in left and smaller than min in right
//         if(left.maxNode<root->data && root->data<right.minNode)
//         {   
//             return NodeValue(min(root->data,left.minNode),max(root->data,
//             right.maxNode),left.maxSize+right.maxSize+1);
//         }
        
//         //Otherwise return [-inf,inf] so that parent can't be a valid BST
//         return NodeValue(INT_MIN,INT_MAX,max(left.maxSize,right.maxSize));
//     }
//     public:
//     /*You are required to complete this method */
//     // Return the size of the largest sub-tree which is also a BST
//     int largestBst(Node *root)
//     {
//         return largestBSTSubtreeHelper(root).maxSize;
//     }
// };