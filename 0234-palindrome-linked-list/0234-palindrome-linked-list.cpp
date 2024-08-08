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
    bool isPalindrome(ListNode* head) {
        ListNode *temp =head;
        int ct=0;

        while(temp){
            temp=temp->next;
            ct++;

        }
        temp=head;
        stack<int>st;
        int k=0;
        while(k<ct/2){
            st.push(temp->val);
            temp=temp->next;
            k++;


        }
        if(ct&1)temp=temp->next;
        while(temp){
            if(temp->val!=st.top())return false;
            st.pop();
            temp=temp->next;
        }
        return true;
    }
};