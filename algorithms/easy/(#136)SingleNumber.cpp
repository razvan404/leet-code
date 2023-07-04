class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0;
        for (const auto& num : nums) {
            ones ^= num;
        }
        return ones;
    }
};