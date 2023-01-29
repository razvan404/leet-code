class Solution {
    void putFirst(string& s, char c) {
        s.insert(s.begin(), c);
    }
    void putFirst(string& s, string str) {
        s.insert(s.begin(), str.begin(), str.end());
    }
    void insertBasedOnDigit(string& ans, int digit, char unit, char five, char ten) {
        string four{ unit, five };
        string nine{ unit, ten };

        if (digit < 5) {
            if (digit == 4) {
                putFirst(ans, four);
            }
            else {
                for (int i = 0; i < digit; ++i) {
                    putFirst(ans, unit);
                }
            }
        }
        else {
            if (digit == 9) {
                putFirst(ans, nine);
            }
            else {
                digit -= 5;
                for (int i = 0; i < digit; ++i) {
                    putFirst(ans, unit);
                }
                putFirst(ans, five);
            }
        }
    }
    
public:
    string intToRoman(int num) {
        string ans = "";

        insertBasedOnDigit(ans, num % 10, 'I', 'V', 'X');
        num /= 10;
        insertBasedOnDigit(ans, num % 10, 'X', 'L', 'C');
        num /= 10;
        insertBasedOnDigit(ans, num % 10, 'C', 'D', 'M');
        num /= 10;

        for (int i = 0; i < num; i++) {
            putFirst(ans, 'M');
        }

        return ans;
    }
};