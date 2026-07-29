class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> isVisited(nums.size(),false);
        vector<int> subset;
        backtrack(nums,isVisited,subset);
        return result;
    }
    void backtrack(vector<int>& nums,vector<bool>& isVisited,vector<int>& subset){
        if(subset.size() == nums.size()){
            result.push_back(subset);
            return;
        }
        for(int i = 0;i < nums.size();i++){
            if(!isVisited[i]){
                subset.push_back(nums[i]);
                isVisited[i] = true;
                backtrack(nums,isVisited,subset);
                subset.pop_back();
                isVisited[i] = false;
            }
        }
    }
};
