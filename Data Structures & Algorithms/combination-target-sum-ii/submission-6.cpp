class Solution {
public:
    vector<vector<int>> res;
    unordered_map<int, int>count;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        //sort(candidates.begin(), candidates.end());
        vector<int> cur;
        vector<int> A;
        for(auto i:candidates){
            if(count[i]==0){
                A.push_back(i);
            }
            count[i]++;
        }
        generateSubsets(A, target, 0, cur, 0);
        return res;
    }

private:
    void generateSubsets(vector<int>& candidates, int target, int i, vector<int>& cur, int total) {
        if (total == target) {
            res.push_back(cur);
            return;
        }
        if (total > target || i == candidates.size()) {
            return;
        }

        if(count[candidates[i]]){
            cur.push_back(candidates[i]);
            count[candidates[i]]--;
            generateSubsets(candidates, target, i, cur, total + candidates[i]);
            count[candidates[i]]++;
            cur.pop_back();
        }

        generateSubsets(candidates, target, i + 1, cur, total);
    }
};