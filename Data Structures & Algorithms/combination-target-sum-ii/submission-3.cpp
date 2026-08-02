class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> subset;
        sort(candidates.begin(),candidates.end());
        backtrack(candidates,target,subset,0);
        return ans;
    }
    void backtrack(vector<int>& nums,int remaining,vector<int>& subset,int index){
        if(remaining == 0){
            ans.push_back(subset);
            return;
        }
        if(remaining < 0 || index >= nums.size()){
            return;
        }
        subset.push_back(nums[index]);
        backtrack(nums,remaining-nums[index],subset,index+1);
        subset.pop_back();
        while(index < nums.size()-1 && nums[index] == nums[index+1]){
            index++;
        }
        backtrack(nums,remaining,subset,index+1);
    }
};
