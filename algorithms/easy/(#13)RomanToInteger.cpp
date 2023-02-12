class Solution {
public:
    int romanToInt(string s) {
        int value = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'I') {
                if (i + 1 < s.size() && s[i + 1] == 'V') {
                    i++;
                    value += 4;
                    continue;
                }
                if (i + 1 < s.size() && s[i + 1] == 'X') {
                    i++;
                    value += 9;
                    continue;
                }
                value += 1;
                continue;
            }
            if (s[i] == 'V') {
                value += 5;
                continue;
            }
            if (s[i] == 'X') {
                if (i + 1 < s.size() && s[i + 1] == 'L') {
                    i++;
                    value += 40;
                    continue;
                }
                if (i + 1 < s.size() && s[i + 1] == 'C') {
                    i++;
                    value += 90;
                    continue;
                }
                value += 10;
                continue;
            }
            if (s[i] == 'L') {
                value += 50;
                continue;
            }

            if (s[i] == 'C') {
                if (i + 1 < s.size() && s[i + 1] == 'D') {
                    i++;
                    value += 400;
                    continue;
                }
                if (i + 1 < s.size() && s[i + 1] == 'M') {
                    i++;
                    value += 900;
                    continue;
                }
                value += 100;
                continue;
            }
            if (s[i] == 'D') {
                value += 500;
                continue;
            }
            if (s[i] == 'M') {
                value += 1000;
                continue;
            }
        }
        return value;
    }
};