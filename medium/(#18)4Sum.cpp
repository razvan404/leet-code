class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        if (nums[n - 1] < target / 4) {
            return {};
        }

        int prev_i = INT_MAX, prev_j = INT_MAX;
        for (int i = 0; i < n - 3; ++i) {
            if (nums[i] > target / 4) {
                break;
            }
            if (nums[i] == prev_i) {
                continue;
            }
            prev_i = nums[i];
            prev_j = INT_MAX;

            for (int j = i + 1; j < n - 2; ++j) {
                if (nums[j] == prev_j) {
                    continue;
                }
                prev_j = nums[j];

                int left = j + 1, right = n - 1;
                long long target_sum = target * 1LL - nums[i] - nums[j];
                while (left < right) {
                    long long found_sum = nums[left] * 1LL + nums[right];
                    if (found_sum > target_sum) {
                        right--;
                    }
                    else if (found_sum < target_sum) {
                        left++;
                    }
                    else {
                        res.push_back({ nums[i], nums[j], nums[left], nums[right] });
                        left++;
                        while (nums[left] == nums[left - 1] && left < right) {
                            left++;
                        }
                        right--;
                    }
                }
            }
        }

        return res;
    }
};