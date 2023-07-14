class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProduct = INT_MIN, currentProduct = 1, currentProductReverse = 1, nums_len = nums.size();
        for (int i = 0; i < nums_len; ++i) {
            currentProduct *= nums[i];
            currentProductReverse *= nums[nums_len - i - 1];
            maxProduct = max(maxProduct, currentProduct);
            maxProduct = max(maxProduct, currentProductReverse);
            if (currentProduct == 0) {
                currentProduct = 1;
            }
            if (currentProductReverse == 0) {
                currentProductReverse = 1;
            }
        }
        return maxProduct;

    }
};