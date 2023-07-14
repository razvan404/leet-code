class Solution {
    bool isTheClosure(char s1, char s2) {
        switch (s1) {
        case '(':
            return s2 == ')';
        case '[':
            return s2 == ']';
        case '{':
            return s2 == '}';
        default:
            return false;
        }
    }
public:
    bool isValid(string s) {
        vector<char> buffer;
        char out;

        for (auto chr : s) {
            if (chr == '(' || chr == '[' || chr == '{') {
                buffer.push_back(chr);
            }
            else {
                if (buffer.empty()) {
                    return false;
                }
                out = buffer.back();
                buffer.pop_back();
                if (!isTheClosure(out, chr)) {
                    return false;
                }
            }
        }
        return buffer.empty();
    }
};