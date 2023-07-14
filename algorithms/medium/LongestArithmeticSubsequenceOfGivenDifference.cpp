class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int longest = 0;
        unordered_map<int, int> heads;
        for (const int& num : arr) {
            longest = max(longest, heads[num] = heads[num - difference] + 1);
        }
        return longest;
    }
};
