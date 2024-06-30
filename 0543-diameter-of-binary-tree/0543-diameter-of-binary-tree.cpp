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
    int fun(TreeNode* node,int &ans){
        if(node == NULL)return 0;

        int lh=fun(node->left,ans);
        int rh=fun(node->right,ans);
        ans=max(ans,lh+rh);
        return 1+max(rh,lh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        fun(root,ans);
        return ans;
    }
};