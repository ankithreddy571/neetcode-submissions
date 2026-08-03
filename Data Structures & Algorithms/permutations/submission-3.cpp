class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> subset;
        vector<bool> visited(nums.size(),false);
        backtrack(nums,subset,visited);
        return ans;
    }
    void backtrack(vector<int>& nums,vector<int>& subset,vector<bool>& vis){
        if(subset.size() == nums.size()){
            ans.push_back(subset);
            return;
        }
        for(int i = 0;i < nums.size();i++){
            if(!vis[i]){
                subset.push_back(nums[i]);
                vis[i] = true;
                backtrack(nums,subset,vis);
                subset.pop_back();
                vis[i] = false;
            }
        }
    }
};
