class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = (int)nums.size();

        if (n < 3) {
            return {};
        }
        
        sort(nums.begin(), nums.end());

        if (nums[n - 1] < 0) {
            return {};
        }

        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                return ans;
            }

            int low = i + 1, high = n - 1;
            while (low < high) {
                int sum = nums[i] + nums[low] + nums[high];
                if (sum > 0) {
                    --high;
                }
                else if (sum < 0) {
                    ++low;
                }
                else if (ans.size() == 0 || !(ans[ans.size() - 1][1] == nums[low] && ans[ans.size() - 1][2] == nums[high])) {
                    ans.push_back({ nums[i], nums[low], nums[high] });
                    ++low;
                    --high;
                }
                else {
                    ++low;
                    --high;
                }
            }

            while (i + 1 < n && nums[i] == nums[i + 1]) {
                i++;
            }
        }

        return ans;
    }
};