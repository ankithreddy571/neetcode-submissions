class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> subset;
        int sum = target;
        backtrack(nums,subset,0,sum);
        return ans;
    }
    void backtrack(vector<int> nums,vector<int> subset,
                    int index,int sum){
        if(sum == 0){
            ans.push_back(subset);
            return;
        }
        if(sum < 0 || index >= nums.size()){
            return;
        }
        subset.push_back(nums[index]);
        backtrack(nums,subset,index,sum-nums[index]);
        subset.pop_back();
        backtrack(nums,subset,index+1,sum);
    }
};
