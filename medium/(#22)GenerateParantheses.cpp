class Solution {
    void generatorHelper(vector<string>& generated, string& current, int toCloseParanthesis, int openedParanthesis) {
        if (toCloseParanthesis == 0) {
            generated.push_back(current);
            return;
        }
        if (openedParanthesis < toCloseParanthesis) {
            current.push_back('(');
            generatorHelper(generated, current, toCloseParanthesis, openedParanthesis + 1);
            current.pop_back();
        }
        if (openedParanthesis > 0) {
            current.push_back(')');
            generatorHelper(generated, current, toCloseParanthesis - 1, openedParanthesis - 1);
            current.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string current = "";
        generatorHelper(ans, current, n, 0);
        return ans;
    }
};