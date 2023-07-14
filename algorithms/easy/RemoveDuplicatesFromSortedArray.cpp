class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unsigned j = nums.size() > 0;
        for (unsigned i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                nums[j] = nums[i];
                j++;
            }
        }
        return j;
    }
};