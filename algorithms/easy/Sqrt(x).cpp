class Solution {
public:
    int mySqrt(int x) {
        if (x < 4) {
            return x != 0;
        }
        int left = 0, right = min(46340, x);
        while (left <= right) {
            int mid = (left + right) / 2;
            if (mid * mid == x) {
                return mid;
            } else if (mid * mid > x) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return right;
    }
};