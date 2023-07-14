class Solution {
public:
    string addBinary(string a, string b) {
        uint8_t flag = 0;
        int16_t i = a.size() - 1, j = b.size() - 1;
        string ans;
        
        while (i >= 0 && j >= 0) {
            if (a[i] == b[j]) {
                ans += (flag + '0');
                flag = a[i] - '0';
            }
            else {
                ans += ('1' - flag);
            }
            --i;
            --j;
        }

        while (i >= 0) {
            if (a[i] == '1' && flag) {
                ans += '0';
            }
            else {
                ans += (flag + a[i]);
                flag = 0;
            }
            i--;
        }

        while (j >= 0) {
            if (b[j] == '1' && flag) {
                ans += '0';
            }
            else {
                ans += (flag + b[j]);
                flag = 0;
            }
            j--;
        }

        if (flag) {
            ans += (flag + '0');
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};