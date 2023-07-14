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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) {
            return ans;
        }
        queue<TreeNode*> queue;
        int level = 0;

        queue.push(root);
        while (!queue.empty()) {
            int n = queue.size();
            vector<int> arr(n);

            for (int i = 0; i < n; ++i) {
                TreeNode* top = queue.front();
                queue.pop();

                if (level % 2) {
                    arr[n - i - 1] = top->val;
                }
                else {
                    arr[i] = top->val;
                }

                if (top->left != nullptr) {
                    queue.push(top->left);
                }
                if (top->right != nullptr) {
                    queue.push(top->right);
                }
            }

            ans.push_back(arr);
            ++level;
        }

        return ans;
    }
};