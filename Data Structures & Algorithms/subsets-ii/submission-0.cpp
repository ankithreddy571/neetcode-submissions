class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> subset;
        sort(nums.begin(),nums.end());
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
        while(index+1 < nums.size() && nums[index] == nums[index+1]){
            index++;
        }
        subset.pop_back();
        backtrack(nums,subset,index+1);

    }
};
