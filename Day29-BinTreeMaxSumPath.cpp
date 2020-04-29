/*
Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

Example 1:

Input: [1,2,3]

       1
      / \
     2   3

Output: 6
Example 2:

Input: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

Output: 42
*/


class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int max_sum = INT_MIN;
        maxsum(root, max_sum);   
        return max_sum;
    }
    
    
    int maxsum(TreeNode* root, int &max_sum){
        if(root == nullptr)
            return 0;
        
        // Path sum with current node included in the path, from left side of current node
        // Path sum with current node inclded in the path, from right subtree of current node
        int sum_left = maxsum(root->left, max_sum);
        int sum_right = maxsum(root->right, max_sum);
        
        int sum_root =  root->val + sum_left + sum_right;
       
        sum_left += root->val;   
        sum_right += root->val;
       
        max_sum = max(max_sum, max(sum_root, max(sum_left, sum_right)));
        max_sum = max(root->val, max_sum);
        
        //return to the parent node, maximum of "root->val, left->sum, right->sum" 
        return max(root->val, max(sum_left, sum_right));
    }
};
