class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        createSubsets(nums,subset,0);
        return ans;
    }
    void createSubsets(vector<int> nums,vector<int>& subset,int index){
        if(index >= nums.size()){
            ans.push_back(subset);
            return;
        }
        subset.push_back(nums[index]);
        createSubsets(nums,subset,index+1);
        subset.pop_back();
        createSubsets(nums,subset,index+1);
    }
};
