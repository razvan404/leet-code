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
public:
    int getMinimumDifference(TreeNode* root) {
        if (root == NULL) {
            return INT_MAX;
        }
        int minThisLevel = INT_MAX;
        if (root->left != NULL) {
            TreeNode* pred = root->left;
            while (pred->right != NULL) {
                pred = pred->right;
            }
            minThisLevel = min(minThisLevel, root->val - pred->val);
        }
        if (root->right != NULL) {
            TreeNode* succ = root->right;
            while (succ->left != NULL) {
                succ = succ->left;
            }
            minThisLevel = min(minThisLevel, succ->val - root->val);
        }
        return min(minThisLevel, min(getMinimumDifference(root->left), getMinimumDifference(root->right)));
    }
};