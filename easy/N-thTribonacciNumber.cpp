class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) {
            return 0;
        }

        if (n <= 2) {
            return 1;
        }

        int first = 0;
        int second = 1;
        int current = 1;

        for (int i = 3; i <= n; ++i) {
            int temp = current;
            current = current + second + first;
            first = second;
            second = temp;
        }

        return current;
    }
};