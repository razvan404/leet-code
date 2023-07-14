class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int prevArrayLen = 0, maxArrayLen = 0;
        for (int i = 0; i < nums.size(); i++) {
            int j = i;
            if (nums[j] == 1) {
                do {
                    j++;
                } while (j < nums.size() && nums[j] == 1);
                if (i > 2 && nums[i - 2] == 1) {
                    maxArrayLen = max(maxArrayLen, prevArrayLen + j - i);
                } else if (i == 0 && j == nums.size()) {
                    maxArrayLen = nums.size() - 1;
                } else {
                    maxArrayLen = max(maxArrayLen, j - i);
                }
                prevArrayLen = j - i;
                i = j;
            }
        }
        return maxArrayLen;
    }
};