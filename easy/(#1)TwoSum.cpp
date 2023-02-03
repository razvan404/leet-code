class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> dict;
        for (int i = 0; i < nums.size(); ++i) {
            if (dict[target - nums[i]]) {
                return { dict[target - nums[i]] - 1, i };
            }
            dict[nums[i]] = i + 1;
        }
        return {};
    }
};