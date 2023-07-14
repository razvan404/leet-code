class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0) {
            return 0;
        }
        if (n < 0) {
            x = 1 / x;
        }
        double ans = 1;
        long num = n < 0 ? -1L * n : n;
        while (num > 0) {
            if (num % 2) {
                ans *= x;
            }
            x *= x;
            num /= 2;
        }
        return ans;
    }
};
