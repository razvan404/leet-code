class Solution {
    string getChars(char digit) {
        switch (digit) {
        case '2':
            return "abc";
        case '3':
            return "def";
        case '4':
            return "ghi";
        case '5':
            return "jkl";
        case '6':
            return "mno";
        case '7':
            return "pqrs";
        case '8':
            return "tuv";
        case '9':
            return "wxyz";
        default:
            return NULL;
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if (digits == "") {
            return {};
        }

        if (digits.size() == 1) {
            vector<string> ans;
            for (auto chr : getChars(digits[0])) {
                ans.push_back(string(1, chr));
            }
            return ans;
        }

        vector<string> ans;
        string chars = getChars(digits[0]);
        for (auto str : letterCombinations(digits.substr(1, digits.size() - 1))) {
            for (auto chr : chars) {
                ans.push_back(string(1, chr) + str);
            }
        }

        return ans;
    }
};