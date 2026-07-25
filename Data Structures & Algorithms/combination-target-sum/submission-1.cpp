class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> curr;
        int sum = 0;
        backtrack(curr,nums,target,0);
        return ans;
    }

    void backtrack(vector<int>& curr,vector<int> nums,int sum,int index){
        if(sum < 0 || index >= nums.size())
            return;
        if(sum == 0){
            ans.push_back(curr);
            return;
        }
        curr.push_back(nums[index]);
        backtrack(curr,nums,sum-nums[index],index);
        curr.pop_back();
        backtrack(curr,nums,sum,index+1);
    }
};
