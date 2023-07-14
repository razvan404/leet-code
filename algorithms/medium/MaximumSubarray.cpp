class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentSum = nums[0] > 0 ? nums[0] : 0, maxSum = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            currentSum += nums[i];
            if (maxSum < currentSum) {
                maxSum = currentSum;
            }
            if (currentSum < 0) {
                currentSum = 0;
            }
        }
        return maxSum;
    }
};
