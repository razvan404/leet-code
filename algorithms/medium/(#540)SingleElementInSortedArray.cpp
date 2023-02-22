class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (mid % 2 == 1) {
                if (mid > 0 && nums[mid] == nums[mid - 1]) {
                    left = mid + 1;
                }
                else if (mid < nums.size() - 1 && nums[mid] == nums[mid + 1]) {
                    right = mid - 1;
                }
                else {
                    return nums[mid];
                }
            }
            else {
                if (mid > 0 && nums[mid] == nums[mid - 1]) {
                    right = mid - 1;
                }
                else if (mid < nums.size() - 1 && nums[mid] == nums[mid + 1]){
                    left = mid + 1;
                }
                else {
                    return nums[mid];
                }
            }
        }
        return -1;
    }
};