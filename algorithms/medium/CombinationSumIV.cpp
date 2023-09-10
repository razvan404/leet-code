class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> cache(target + 1, 0);
        sort(nums.begin(), nums.end());
        cache[0] = 1;
        for (int i = 1; i <= target; ++i) {
            for (const auto& num : nums) {
                if (i - num >= 0) {
                    cache[i] += cache[i - num];
                } else {
                    break;
                }
            }
        }
        return cache.back();
    }
};