/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        int left=0,top=0;
        int right=n-1;
        int bottom =m-1;
        vector<vector<int>>matrix(m,vector<int>(n,-1));
        int temp=1;
        while(top<=bottom&&left<=right&&head){
        //right
        for(int i=left;i<=right&&head;i++){
            matrix[top][i]=head->val;head=head->next;
        }
        top++;

        //down
        for(int i=top;i<=bottom&&head;i++){
            matrix[i][right]=head->val;head=head->next;
        }
        right--;
        
        
        //left
        if(top<=bottom){
            for(int i=right;i>=left&&head;i--){
                matrix[bottom][i]=head->val;head=head->next;
            }
            bottom--;
        }

        //up
        if(left<=right){
            for(int i=bottom;i>=top&&head;i--){
                matrix[i][left]=head->val;head=head->next;
            }
            left++;
        }
        }
        return matrix;
    }
};