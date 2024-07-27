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
    set<int> del;

    void dfs(TreeNode* node, vector<TreeNode*>& ans, TreeNode* parent, bool isLeft) {
        if (!node) return;

        dfs(node->left, ans, node, true);
        dfs(node->right, ans, node, false);

        if (del.find(node->val) != del.end()) {
            if (node->left) ans.push_back(node->left);
            if (node->right) ans.push_back(node->right);
            
            if (parent) {
                if (isLeft) parent->left = NULL;
                else parent->right = NULL;
            }
        }
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& tod) {
        del.insert(tod.begin(), tod.end());
        vector<TreeNode*> ans;

        if (del.find(root->val) == del.end()) {
            ans.push_back(root);
        }

        dfs(root, ans, NULL, false);
        return ans;
    }
};
