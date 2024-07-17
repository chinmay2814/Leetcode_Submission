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
private:
    map<string,int>m;
    vector<TreeNode*>ans;
public:
    string dfs(TreeNode* root){
        if(!root)return "NULL";

        string curr=to_string(root->val)+"@"+dfs(root->left)+"@"+dfs(root->right);
        if(m[curr]==1)ans.push_back(root);
        m[curr]++;
        return curr;

    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return ans;
    }
};