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
    void fun(int &ans,TreeNode* root){
        if(!root)return;
        if(root->val%2==0){
            if(root->left&&root->left->left)ans+=root->left->left->val;
            if(root->left&&root->left->right)ans+=root->left->right->val;
            if(root->right&&root->right->right)ans+=root->right->right->val;
            if(root->right&&root->right->left)ans+=root->right->left->val;
            
        }
        if(root->left)fun(ans,root->left);
        if(root->right)fun(ans,root->right);
    }
    int sumEvenGrandparent(TreeNode* root) {
        int ans=0;
        fun(ans,root);
        return ans;
    }
};