class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
    vector<int> subset;
    backtrack(nums,subset,target,0);
    return ans;
    }

    void backtrack(vector<int>& nums,vector<int>& subset,
                int remaining,int index){
        if(remaining == 0){
            ans.push_back(subset);
            return;
        }
        if(remaining < 0 || index >= nums.size()){
            return;
        }
        subset.push_back(nums[index]);
        backtrack(nums,subset,remaining-nums[index],index);
        subset.pop_back();
        backtrack(nums,subset,remaining,index+1);
    }
};
