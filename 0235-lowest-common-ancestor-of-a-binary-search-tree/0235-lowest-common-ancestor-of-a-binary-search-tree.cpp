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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pa, pb;
        TreeNode *node = root;

        // Find the path to node p
        while (node != NULL) {
            pa.push_back(node);
            if (node->val > p->val) {
                node = node->left;
            } else if (node->val < p->val) {
                node = node->right;
            } else {
                break;
            }
        }

        // Find the path to node q
        node = root;
        while (node != NULL) {
            pb.push_back(node);
            if (node->val > q->val) {
                node = node->left;
            } else if (node->val < q->val) {
                node = node->right;
            } else {
                break;
            }
        }
        TreeNode *ans = NULL;
        for (int i = 0; i < min(pa.size(), pb.size()); ++i) {
            if (pa[i] == pb[i]) {
                ans = pa[i];
            } else {
                break;
            }
        }

        return ans;
        
    }
};