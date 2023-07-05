class Solution {
public:
    int climbStairs(int n) {
        if (n < 2) {
            return 1;
        }
        int prev = 1, curr = 2;
        n -= 2;
        while (n) {
            int aux = prev + curr;
            prev = curr;
            curr = aux;
            --n;
        }
        return curr;
    }
};