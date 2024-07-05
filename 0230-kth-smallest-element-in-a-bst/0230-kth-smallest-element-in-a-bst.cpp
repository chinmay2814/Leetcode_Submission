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
    
    void fun(TreeNode* root, int k,int &ans,int &ct){
        if(!root)return ;

        fun(root->left,k,ans,ct);
        ct++;
        if(ct==k){
            ans=root->val;
            return;
        }
        fun(root->right,k,ans,ct);
    }

    int kthSmallest(TreeNode* root, int k) {
        int ct=0;
        int ans;
        fun(root,k,ans,ct);
        return ans;
    }
};