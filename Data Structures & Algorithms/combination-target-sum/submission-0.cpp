class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> subset;
        int sum = 0;
        createSubset(sum,nums,target,subset,0);
        return ans;
    }

    void createSubset(int sum,vector<int> nums,int target,vector<int>& subset,int index){
        if(sum > target || index >= nums.size()){
            return;
        }
        if(sum == target){
            ans.push_back(subset);
            return;
        }
        subset.push_back(nums[index]);
        createSubset(sum+nums[index],nums,target,subset,index);
        subset.pop_back();
        createSubset(sum,nums,target,subset,index+1);
    }
};
