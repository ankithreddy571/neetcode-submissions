class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> curr;
        backtrack(nums,target,curr,0);
        return ans;
    }
    void backtrack(vector<int> nums,int sum,vector<int> curr,int index){
        if(sum == 0){
            ans.push_back(curr);
            return;
        }
        if(sum < 0 || index >= nums.size()){
            return;
        }
        curr.push_back(nums[index]);
        backtrack(nums,sum-nums[index],curr,index);
        curr.pop_back();
        backtrack(nums,sum,curr,index+1);
    }
};
