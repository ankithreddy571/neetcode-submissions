class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> vis(nums.size(),false);
        vector<int> subset;
        permute(nums,vis,subset);
        return ans;
    }
    void permute(vector<int>& nums,vector<bool>& vis,vector<int> subset){
        if(subset.size() == nums.size()){
            ans.push_back(subset);
            return;
        }
        for(int i = 0;i < nums.size();i++){
            if(!vis[i]){
                subset.push_back(nums[i]);
                vis[i] = true;
                permute(nums,vis,subset);
                subset.pop_back();
                vis[i] = false;
            }
        }
    }
};
