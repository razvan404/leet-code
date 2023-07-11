/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    struct TreeNodeProps {
        TreeNode* parent;
        bool visited = false;
        TreeNodeProps(TreeNode* parent, bool visited) : parent(parent), visited(visited) {}
    };
    
    unordered_map<TreeNode*, TreeNodeProps> props;
    void initPropsMap(TreeNode* prev, TreeNode* crt) {
        if (crt == NULL) {
            return;
        }
        props.insert({ crt, { prev, false } });
        initPropsMap(crt, crt->left);
        initPropsMap(crt, crt->right);
    }

    void initDistanceVector(TreeNode* crt, int crtDist, vector<int>& distanceVec) {
        if (crtDist == 0) {
            distanceVec.push_back(crt->val);
        }
        props.at(crt).visited = true;
        if (!props.at(crt->left).visited) {
            initDistanceVector(crt->left, crtDist - 1, distanceVec);
        }
        if (!props.at(crt->right).visited) {
            initDistanceVector(crt->right, crtDist - 1, distanceVec);
        }
        if (!props.at(props.at(crt).parent).visited) {
            initDistanceVector(props.at(crt).parent, crtDist - 1, distanceVec);
        }
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        initPropsMap(NULL, root);
        props.insert({ NULL, { NULL, true } });
        vector<int> distanceVec;
        initDistanceVector(target, k, distanceVec);
        return distanceVec;
    }
};