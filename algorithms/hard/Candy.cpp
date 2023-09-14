class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candies(ratings.size(), 0);
        int totalCandy = ratings.size();
        for (int i = 1; i < ratings.size(); ++i) {
            if (ratings[i] > ratings[i - 1]) {
                totalCandy += candies[i - 1] + 1;
                candies[i] = candies[i - 1] + 1;
            }
        }
        for (int i = ratings.size() - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1] && candies[i] <= candies[i + 1]) {
                totalCandy += candies[i + 1] - candies[i] + 1;
                candies[i] = candies[i + 1] + 1;
            }
        }
        return totalCandy;
    }
};
