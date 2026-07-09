class Solution {
private:
    int heightOfTree(TreeNode* root){
        if(!root) return 0;
        return 1 + max(heightOfTree(root->left),
                        heightOfTree(root->right));
     }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int leftHeight = heightOfTree(root->left);
        int rightHeight = heightOfTree(root->right);
        int diameter = leftHeight + rightHeight;
        int diameterOfSubTrees = max(diameterOfBinaryTree(root->left),
                        diameterOfBinaryTree(root->right));
        return max(diameter,diameterOfSubTrees);
    }
};
