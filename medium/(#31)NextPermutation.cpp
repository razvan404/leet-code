class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int toSwap = INT_MIN, swapper = INT_MIN;
        for (int i = nums.size() - 1; i > 0; --i) {
            if (nums[i] > nums[i - 1]) {
                toSwap = i - 1;
                break;
            }
        }
        if (toSwap == INT_MIN) {
            reverse(nums.begin(), nums.end());
            return;
        }
        for (int i = nums.size() - 1; i > toSwap; --i) {
            if (nums[i] > nums[toSwap]) {
                swapper = i;
                break;
            }
        }
        swap(nums[toSwap], nums[swapper]);
        reverse(nums.begin() + toSwap + 1, nums.end());
    }
};