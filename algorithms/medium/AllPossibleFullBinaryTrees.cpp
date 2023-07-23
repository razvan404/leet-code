/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    unordered_map<int, vector<TreeNode*>> cachedFBT;

    vector<TreeNode*> allPossibleFBTRecursive(int n) {
        if (n == 1) {
            return { new TreeNode(0) };
        }
        vector<TreeNode*> trees;
        for (int i = 1; i <= n / 2; i += 2) {
            vector<TreeNode*> trees1, trees2;
            unordered_map<int, vector<TreeNode*>>::iterator iter;
            if ((iter = cachedFBT.find(i)) != cachedFBT.end()) {
                trees1 = iter->second;
            } else {
                trees1 = allPossibleFBTRecursive(i);
                cachedFBT.insert({ i, trees1 });
            }
            if ((iter = cachedFBT.find(n - i - 1)) != cachedFBT.end()) {
                trees2 = iter->second;
            } else {
                trees2 = allPossibleFBTRecursive(n - i - 1);
                cachedFBT.insert({ n - i - 1, trees2 });
            }
            for (const auto& tree1 : trees1) {
                for (const auto& tree2 : trees2) {
                    trees.push_back(new TreeNode(0, tree1, tree2));
                    if (2 * i + 1 != n) {
                        trees.push_back(new TreeNode(0, tree2, tree1));
                    }
                }
            }
        }
        return trees;
    }
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        if (n % 2 != 1) {
            return {};
        }
        return allPossibleFBTRecursive(n);
    }
};
