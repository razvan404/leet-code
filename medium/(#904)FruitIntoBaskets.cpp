class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int ans = 0, current_max = 0, types = 0, start = 0, n = fruits.size();
        vector<int> counts(n);

        for (int i = 0; i < n; ++i) {
            if (!counts[fruits[i]]) {
                ++types;
            }
            ++counts[fruits[i]];
            ++current_max;

            while (types > 2 && start < i) {
                --counts[fruits[start]];
                if (!counts[fruits[start]]) {
                    --types;
                }
                --current_max;
                ++start;
            }

            ans = max(ans, current_max);
        }

        return ans;
    }
};