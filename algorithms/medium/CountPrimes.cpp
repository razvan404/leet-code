class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) {
            return 0;
        }
        vector<bool> notPrime(n);
        notPrime[0] = true;
        notPrime[1] = true;
        for (int i = 2; i * i < n; ++i) {
            if (!notPrime[i]) {
                for (int j = i * i; j < n; j += i) {
                    notPrime[j] = true;
                }                
            }
        }
        int count = 0;
        for (int i = 2; i < n; ++i) {
            if (!notPrime[i]) {
                ++count;
            }
        }
        return count;
    }
};
