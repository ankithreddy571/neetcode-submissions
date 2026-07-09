class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;
        while(!q.empty()){
            int n = q.size();
            for(int i = 0;i < n;i++){
                TreeNode* x = q.front();
                q.pop();
                if(x->left != nullptr) q.push(x->left);
                if(x->right != nullptr) q.push(x->right);
            }
            depth++;
        }
        return depth;
    }
};
