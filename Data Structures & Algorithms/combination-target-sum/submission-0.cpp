class Solution {
public:
    void dfs(vector<vector<int>>& ans, vector<int>& subset, vector<int>& nums,int target, int i, int sum){
        if (sum == target) {
            ans.push_back(subset);
            return;
        }

        if (sum > target) {
            return;
        }

        if (i >= nums.size()) {
            return;
        }
        sum+=nums[i];
        subset.push_back(nums[i]);
        dfs(ans, subset, nums, target, i,sum);
        sum-=nums[i];
        subset.pop_back();
        dfs(ans, subset, nums, target, i+1,sum);
        
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> subset;
        vector<vector<int>> ans;
        dfs(ans, subset, nums, target, 0,0);
        return ans;
    }
};
