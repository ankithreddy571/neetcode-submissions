/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int res = 0;
        dfs(root,res);
        return res;
    }
private:
    int dfs(TreeNode* root,int& res){
        if(!root) return 0;
        int leftHeight = dfs(root->left,res);
        int rightHeight = dfs(root->right,res);
        res = max(res,leftHeight + rightHeight);
        return 1 + max(leftHeight,rightHeight);
    }
};

// Algorithm
// 1. We first call dfs function on root.
// 2. Now we will write base condition to 
//    return value if does not meet requirement
// 3. Now we will run dfs on left and right to get height of both
// 4. Now we got height of both left and right which combinely gives us the 
//      diameter here and store it in result
// 5. Now return the max height we gained at that particular node
// 6. After running all recursive calls we will get our highest diameter
//      stored in result
