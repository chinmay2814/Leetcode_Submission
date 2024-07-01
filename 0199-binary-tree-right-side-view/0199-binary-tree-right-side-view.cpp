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
    void fun(TreeNode* node,int level,vector<int>&ans){
        if(!node)return ;
        
        if(ans.size()==level)ans.push_back(node->val);

        if(node->right)fun(node->right,level+1,ans);
        if(node->left)fun(node->left,level+1,ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans; 
        fun(root,0,ans);
        return ans;
    }
};