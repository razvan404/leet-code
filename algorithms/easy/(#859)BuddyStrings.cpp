class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.size() != goal.size() || s.size() < 2) {
            return false;
        }
        char different[2] = {'\0'};
        short state = 0;
        bool twoSame = false, occurencies['z' - 'a'] = {false};
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != goal[i]) {
                switch (state) {
                case 0:
                    different[0] = s[i];
                    different[1] = goal[i];
                    state = 1;
                    break;
                case 1:
                    if (goal[i] != different[0] || s[i] != different[1]) {
                        return false;
                    }
                    state = 2;
                    break;
                default:
                    return false;
                }
            }
            else if (!twoSame) {
                if (occurencies[s[i] - 'a']) {
                    twoSame = true;
                }
                else {
                    occurencies[s[i] - 'a'] = true;
                }
            }
        }
        return state == 2 || (state == 0 && twoSame);
    }
};