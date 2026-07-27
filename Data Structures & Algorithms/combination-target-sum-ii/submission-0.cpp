class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum2(vector<int>& candidates, 
                    int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> subset;
        backtrack(candidates,target,subset,0);
        return ans;
    }
    void backtrack(vector<int> nums,
            int sum,vector<int>& subset,int index){
        if(sum == 0){
            ans.push_back(subset);
            return;
        }
        if(sum < 0 || index >= nums.size()){
            return;
        }    
        subset.push_back(nums[index]);
        backtrack(nums,sum-nums[index],subset,index+1);
        while(index + 1 < nums.size() && nums[index] == nums[index+1]){
            index++;
        }
        subset.pop_back();
        backtrack(nums,sum,subset,index+1);
    }
};
