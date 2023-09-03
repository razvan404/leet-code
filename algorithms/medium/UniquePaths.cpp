class Solution {
public:
    int uniquePaths(int m, int n) {
        long long ans = 1;
        int maxNum = max(m, n), minNum = min(m, n), curr = 2;
        for (int i = maxNum; i < maxNum + minNum - 1; ++i) {
            ans *= i;
            if (curr < minNum && ans % curr == 0) {
                ans /= curr++;
            }
        }
        for (int i = curr; i < minNum; ++i) {
            ans /= i;
        }
        return ans;
    }
};