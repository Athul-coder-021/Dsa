// All Nodes Distance K in Binary Tree

// Given the root of a binary tree, the value of a target node target, and an integer k, 
// return an array of the values of all nodes that have a distance k from the target node.

// You can return the answer in any order.

#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

// Maximum Width of Binary Tree


// TreeNode structure
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


// point 1 mark parents
// point 2 move radially outward by 1 step each time and add to queue and visited ds
class Solution {
    void markParents(TreeNode*root,unordered_map<TreeNode*,TreeNode*>&parent_track,TreeNode* target)
    {
        //same as level order traversal here just before pushing to queue we are pushing parent to map
        queue<TreeNode*>queue;
        queue.push(root);
        while(!queue.empty())
        {
            TreeNode* current = queue.front();
            queue.pop();
            if(current->left)
            {
                parent_track[current->left] = current;
                queue.push(current->left);
            }
            if(current->right)
            {
                parent_track[current->right]=current;
                queue.push(current->right);
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>parent_track;//node->parent
        markParents(root,parent_track,target);

        unordered_map<TreeNode*,bool>visited;
        queue<TreeNode*>queue;
        queue.push(target);
        visited[target] = true;

        int curr_level =0;
        while(!queue.empty())
        {
            int size = queue.size();
            if(curr_level++ == k)
            {
                break;
            }

            for(int i =0;i<size;i++)//Take all together from queue
            {
                TreeNode* current = queue.front();
                queue.pop();
                //radially expand 1 unit
                if(current->left && !visited[current->left])
                {
                    queue.push(current->left);
                    visited[current->left]=true;
                }
                if(current->right && !visited[current->right])
                {
                    queue.push(current->right);
                    visited[current->right]=true;
                }
                if(parent_track[current] && !visited[parent_track[current]])
                {
                    queue.push(parent_track[current]);
                    visited[parent_track[current]]=true;
                }
            }
        }
        vector<int>result;
        while(!queue.empty())
        {
            TreeNode* current = queue.front();
            queue.pop();
            result.push_back(current->val);
        }
         return result;
    }
};