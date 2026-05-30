class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return {1};

        vector<int> pre_prod = nums;
        vector<int> suf_prod = nums;
        vector<int> ans;

        for (int i = 1; i < n; i++) {
            pre_prod[i] *= pre_prod[i - 1];
        }

        for (int i = n - 2; i >= 0; i--) {
            suf_prod[i] *= suf_prod[i + 1];
        }

        for (int i = 0; i < n; i++) {
            if (i == 0) {
                ans.push_back(suf_prod[i + 1]);
                continue;
            }
            if (i == n - 1) {
                ans.push_back(pre_prod[i - 1]);
                continue;
            }
            ans.push_back(pre_prod[i - 1] * suf_prod[i + 1]);
        }

        return ans;
    }
};