class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> subset;
        vector<bool> visited(nums.size(),false);
        backtrack(nums,subset,visited);
        return res;
    }
    void backtrack(vector<int>& nums,vector<int>& subset,
                vector<bool>& visited){
        if(subset.size() == nums.size()){
            res.push_back(subset);
            return;
        }
        for(int i = 0;i < nums.size();i++){
            if(!visited[i]){
                subset.push_back(nums[i]);
                visited[i] = true;
                backtrack(nums,subset,visited);
                subset.pop_back();
                visited[i] = false;
            }
        }
    }
};
