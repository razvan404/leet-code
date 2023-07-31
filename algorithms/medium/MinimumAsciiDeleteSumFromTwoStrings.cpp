class Solution {
private:
    int sumFrom(string& s, int i) {
        int sum = 0;
        for (int j = i; j < s.size(); ++j) {
            sum += s[j];
        }
        return sum;
    }
    int backtracking(int i, int j, string& s1, string& s2, vector<vector<int>>& dp) {
        if (i == s1.size() && j == s2.size()) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (i == s1.size() && j < s2.size()) {
            return dp[i][j] = sumFrom(s2, j);
        }
        if (j == s2.size() && i < s1.size()) {
            return dp[i][j] = sumFrom(s1, i);
        }
        if (s1[i] == s2[j]) {
            return dp[i][j] = backtracking(i + 1, j + 1, s1, s2, dp);
        }
        return dp[i][j] = min(s1[i] + backtracking(i + 1, j, s1, s2, dp),
                            s2[j] + backtracking(i, j + 1, s1, s2, dp));
    }
public:
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, -1));
        return backtracking(0, 0, s1, s2, dp);
    }
};
