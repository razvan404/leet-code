class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = (int)nums.size();

        if (n < 3) {
            return 0;
        }

        sort(nums.begin(), nums.end());

        int minDiff = INT_MAX;
        int minSum = 0;

        for (int i = 0; i < n; i++) {
            int low = i + 1, high = n - 1;
            while (low < high) {
                int sum = nums[i] + nums[low] + nums[high];

                if (abs(sum - target) < minDiff) {
                    minDiff = abs(sum - target);
                    minSum = sum;
                }

                if (minDiff == 0) {
                    return minSum;
                }

                if (sum > target) {
                    --high;
                }
                else {
                    ++low;
                }
            }

            while (i + 1 < n && nums[i] == nums[i + 1]) {
                i++;
            }
        }

        return minSum;
    }
};