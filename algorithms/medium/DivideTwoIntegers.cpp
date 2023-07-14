class Solution {
public:
    int divide(int dividend, int divisor) {
        bool isPositive = (dividend < 0 == divisor < 0);
        uint32_t a = dividend < 0 ? -1U * dividend : dividend;
        uint32_t b = divisor < 0 ? -1U * divisor : divisor;
        uint32_t ans = 0;
        if (a == b) {
            return isPositive ? 1 : -1;
        }
        while (a >= b) {
            uint16_t quot = 0;
            while (a > (b << (quot + 1))) {
                quot++;
            }
            ans += (1 << quot);
            a -= b << quot;
        }
        if (ans == -1U * INT_MIN && isPositive) {
            return INT_MAX;
        }
        return isPositive ? ans : -1 * ans;
    }
};