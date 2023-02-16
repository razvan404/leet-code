class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, int> map;
        string copy;
        for (auto& str : strs) {
            copy = str;
            sort(copy.begin(), copy.end());
            if (!map[copy]) {
                ans.push_back({ str });
                map[copy] = ans.size();
            }
            else {
                ans[map[copy] - 1].push_back(str);
            }
        }
        return ans;
    }
};