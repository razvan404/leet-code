class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 0), countJ(nums.size(), 1);
        dp[0] = 1;
        int maxLength = 1, count = 1;
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    if (dp[i] < dp[j]) {
                        countJ[i] = countJ[j];
                        dp[i] = dp[j];
                    }
                    else if (dp[i] == dp[j]) {
                        countJ[i] += countJ[j];
                    }
                }
            }
            ++dp[i];
            if (dp[i] > maxLength) {
                count = countJ[i];
                maxLength = dp[i];
            }
            else if (dp[i] == maxLength) {
                count += countJ[i];
            }
        }
        return count;
    }
};
