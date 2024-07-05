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
    void fun(TreeNode *node,vector<int>&temp){
        if(!node)return ;
        fun(node->left,temp);
        temp.push_back(node->val);
        fun(node->right,temp);
    }
    bool isValidBST(TreeNode* root) {
        vector<int>temp;
        fun(root,temp);
        int len=temp.size();
        for(int i=1;i<len;i++){
            if(temp[i]<=temp[i-1])return false;
        }
        return true;
    }
};