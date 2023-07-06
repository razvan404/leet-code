class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int prev = 0, currentSum = 0, minLen = INT_MAX;
        for (int i = 0; i < nums.size(); ++i) {
            currentSum += nums[i];
            if (currentSum >= target) {
                while (currentSum >= target) {
                    currentSum -= nums[prev];
                    prev++;
                }
                minLen = min(minLen, i - prev + 2);
            }
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
};