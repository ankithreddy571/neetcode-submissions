class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        backtrack(nums,subset,0);
        return ans;
    }

    void backtrack(vector<int>& nums,vector<int>& subset,int index){
        if(index == nums.size()){
            ans.push_back(subset);
            return;
        }
        subset.push_back(nums[index]);
        backtrack(nums,subset,index+1);
        subset.pop_back();
        backtrack(nums,subset,index+1);
    }
};
