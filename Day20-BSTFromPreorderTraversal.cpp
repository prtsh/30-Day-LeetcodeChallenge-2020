/*
    Return the root node of a binary search tree that matches the given preorder traversal.
    
    (Recall that a binary search tree is a binary tree where for every node, any descendant of node.left has a value < node.val, and any descendant of node.right has a value > node.val.  Also recall that a preorder traversal displays the value of the node first, then traverses node.left, then traverses node.right.)
    
     
    
    Example 1:
    
    Input: [8,5,1,7,10,12]
    Output: [8,5,10,1,7,null,12]
    
     
    
    Note: 
    
    1 <= preorder.length <= 100
    The values of preorder are distinct.
*/


TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size() == 0)
            return nullptr;
        idx = 0;
        return dfs(preorder, INT_MIN, INT_MAX);
        
}
    
TreeNode* dfs(vector<int> & preorder, int min, int max){
        if(idx > preorder.size()-1 || preorder[idx] < min || preorder[idx] > max)
            return nullptr;
        
        TreeNode* root = new TreeNode(preorder[idx]);
        idx++;
        root->left = dfs(preorder, min, root->val);
        root->right = dfs(preorder, root->val, max);
        return root;
       
}
