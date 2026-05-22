class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, int> mp;
        vector<vector<string>> ans;

        int cnt = 0;

        for (string str : strs) {
            string tmp = str;
            sort(tmp.begin(), tmp.end());

            if (mp.find(tmp) == mp.end()) {
                mp[tmp] = cnt++;
                ans.push_back({});
            }

            ans[mp[tmp]].push_back(str);
        }

        return ans;
    }
};