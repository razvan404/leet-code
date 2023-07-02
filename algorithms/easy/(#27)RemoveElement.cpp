class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int j = nums.size() - 1;
        while (j >= 0 && nums[j] == val) {
            --j;
        }
        for (int i = 0; i < j; ++i) {
            if (nums[i] == val) {
                swap(nums[i], nums[j]);
                do {
                    j--;
                } while (nums[j] == val);
            }
        }
        return j + 1;
    }
};