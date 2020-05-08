/*
In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

Return true if and only if the nodes corresponding to the values x and y are cousins.

 

Example 1:


Input: root = [1,2,3,4], x = 4, y = 3
Output: false
Example 2:


Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true
Example 3:



Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false
 

Note:

The number of nodes in the tree will be between 2 and 100.
Each node has a unique integer value from 1 to 100.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
     
        //check height of x and y and parent of x and y
        cout<<findheight(root, x, 0)<<" "<<findheight(root, y, 0)<<endl;
        cout<<parent(root, x, y);
        
        if(findheight(root, x, 0) == findheight(root, y, 0))
            if(parent(root, x, y) == false)
                return true;
        
        return false;
    }
    
    int findheight(TreeNode* root, int x, int height ){
        if(root == nullptr)
            return 0;
        
        if(root->val == x)
            return height;
        
        int left = findheight(root->left,  x, height+1);
        if(left)
            return left;
        else
            return findheight(root->right, x, height+1);
        
    }
    
    
    bool parent(TreeNode* root, int x, int y){
        if(root == nullptr)
            return false;
        
        if(root->left && root->right)
            if((root->left->val == x && root->right->val == y)
               ||(root->right->val == x && root->left->val == y))
                return true;
        
        return parent(root->left, x, y) || parent(root->right,x ,y);
    }
};
