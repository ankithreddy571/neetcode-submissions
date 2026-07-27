class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> curr;
        sort(candidates.begin(),candidates.end());
        backtrack(curr,candidates,target,0);
        return ans;
    }
    void backtrack(vector<int>& curr,vector<int>& nums,
                int sum,int index){
        if(sum == 0){
            ans.push_back(curr);
            return;
        }
        if(sum < 0 || index >= nums.size()){
            return;
        }
        curr.push_back(nums[index]);
        backtrack(curr,nums,sum - nums[index],index+1);
        while(index + 1 < nums.size() && 
            nums[index+1] == nums[index]){
                index++;
        }
        curr.pop_back();
        backtrack(curr,nums,sum,index+1);
    }
};
