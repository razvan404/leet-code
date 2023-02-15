class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int16_t i = num.size() - 1;
        uint8_t flag = 0, sum;
        while (i >= 0 && k) {
            sum = num[i] + k % 10 + flag;
            flag = sum / 10;
            num[i] = sum % 10;
            k /= 10;
            i--;
        }
        while (k) {
            sum = (k % 10 + flag);
            num.insert(num.begin(), sum % 10);
            flag = sum / 10;
            k /= 10;
        }
        while (i >= 0 && flag) {
            sum = num[i] + flag;
            flag = sum / 10;
            num[i] = sum % 10;
            i--;
        }
        if (flag) {
            num.insert(num.begin(), flag);
        }

        return num;
    }
};