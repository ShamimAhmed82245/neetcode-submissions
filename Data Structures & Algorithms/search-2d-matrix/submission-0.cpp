class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int> nums;
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                nums.push_back(matrix[i][j]);
            }
        }
        int left = 0;
        int right = nums.size()-1;
        int mid;
        while(left<right){
            mid = (left+right)/2;
            if(nums[mid]>=target) right=mid;
            else left = mid+1;
        }
        if(nums[left]==target) return true;
        if(nums[right]==target) return true;
        return false;
    }
};
