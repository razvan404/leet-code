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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        TreeNode* current = root;
        while (current) {
            if (current->left == NULL) {
                inorder.push_back(current->val);
                current = current->right;
            } else {
                TreeNode* pred = current->left;
                while (pred->right != current && pred->right != NULL) {
                    pred = pred->right;
                }
                if (pred->right == NULL) {
                    pred->right = current;
                    current = current->left;
                } else {
                    inorder.push_back(current->val);
                    pred->right = NULL;
                    current = current->right;
                }
            }
        }
        return inorder;
    }
};