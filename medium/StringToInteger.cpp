class Solution {
public:
    int myAtoi(string s) {
        int ans = 0;
        bool sgn = true, started = false;
        for (char c : s) {
            if (c == ' ' && !started) {
                continue;
            }
            else if (c == '+' && !started) {
                started = true;
            }
            else if (c == '-' && !started) {
                sgn = false;
                started = true;
            }
            else if (c >= '0' && c <= '9') {
                started = true;
                if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && (c - '0') >= (sgn == -1 ? 8 : 7))) {
                    return sgn ? INT_MAX : INT_MIN;
                }
                ans = ans * 10 + (c - '0');
            }
            else {
                return sgn ? ans : ans * -1;
            }
        }
        return sgn ? ans : ans * -1;
    }
};