class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int all_product = 1, poz0 = -1, n = nums.size();
        vector<int> ans(n, 0);
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                if (poz0 == -1) {
                    poz0 = i;
                }
                else {
                    return ans;
                }
            }
            else {
                all_product *= nums[i];
            }
        }
        if (poz0 != -1) {
            ans[poz0] = all_product;
        }
        else {
            for (int i = 0; i < n; ++i) {
                ans[i] = all_product / nums[i];
            }
        }
        return ans;
    }
};