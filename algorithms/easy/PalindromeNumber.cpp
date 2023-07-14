class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int cop = x;
        long rv = 0;
        while (cop) {
            rv = rv * 10 + cop % 10;
            cop /= 10;
        }
        return rv == x;
    }
};