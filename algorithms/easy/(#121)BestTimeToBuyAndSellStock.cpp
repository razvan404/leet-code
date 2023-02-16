class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int smallest = INT_MAX;
        int maxProfit = 0;
        for (auto& price : prices) {
            if (price < smallest) {
                smallest = price;
            }
            maxProfit = max(maxProfit, price - smallest);
        }
        return maxProfit;
    }
};