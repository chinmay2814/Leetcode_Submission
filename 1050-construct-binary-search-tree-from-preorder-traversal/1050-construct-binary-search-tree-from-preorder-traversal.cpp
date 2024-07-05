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
    TreeNode* bu(vector<int>& preorder,int &ind,int maxi){
        if(ind>=preorder.size()||preorder[ind]>maxi)return NULL;

        TreeNode *root = new TreeNode(preorder[ind++]);
        root->left=bu(preorder,ind,root->val);
        root->right=bu(preorder,ind,maxi);
        return root;

    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int ind=0;
        return bu(preorder,ind,INT_MAX);
    }
};