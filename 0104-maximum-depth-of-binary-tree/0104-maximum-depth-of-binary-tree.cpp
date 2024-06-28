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
    int maxDepth(TreeNode* root) {
         if (root == NULL) return 0;
        queue<TreeNode*>st;
        st.push(root);
        int ct=0;
        while(st.size()){

            ct++;
            int size=st.size();
            for(int i=0;i<size;i++){
            TreeNode* temp=st.front();
            st.pop();
            

            if(temp->left) st.push(temp->left);
            if(temp->right)st.push(temp->right);}
            

        }
        return ct;
    }
};