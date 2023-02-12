class Solution {
public:
    int reverse(int x) {
        int cop = x, rv = 0, limit;
        while (cop) {
            if (rv > INT_MAX / 10 || rv < INT_MIN / 10) {
                return 0;
            }
            rv = rv * 10 + (cop % 10);
            cop /= 10;
        }
        return rv;
    }
};