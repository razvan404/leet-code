class Solution {
private:
    bool backtracking(string& s, int idx, vector<string>& wordDict, vector<bool>& dp) {
        if (dp[idx]) {
            return false;
        }
        if (idx == s.size()) {
            return true;
        }
        dp[idx] = true;
        for (const string& word : wordDict) {
            if (word.size() > s.size() - idx) {
                continue;
            }
            bool contains = true;
            for (int j = 0; j < word.size(); ++j) {
                if (word[j] != s[idx + j]) {
                    contains = false;
                    break;
                }
            }
            if (!contains) {
                continue;
            }
            if (backtracking(s, idx + word.size(), wordDict, dp)) {
                return true;
            }
        }
        return false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size(), false);
        return backtracking(s, 0, wordDict, dp);
    }
};
