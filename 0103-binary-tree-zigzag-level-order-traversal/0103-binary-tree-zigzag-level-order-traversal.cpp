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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
         vector<vector<int>>ans;
         if(!root)return ans;
        bool flag=false;
        queue<TreeNode*>q;
        q.push(root);

        while(q.size()){
            int sz=q.size();
            vector<int>temp;
            vector<TreeNode*>store;
            for(int i=0;i<sz;i++){
                TreeNode* ele=q.front();
                q.pop();
                store.push_back(ele);
                
                temp.push_back(ele->val);
                if(ele->left)q.push(ele->left);
                if(ele->right)q.push(ele->right);
            }
            if(flag){
                reverse(temp.begin(),temp.end());
            }
            flag=!flag;
            ans.push_back(temp);
            for(auto ele:store){
               
            }

        }

        return ans;

    }
};