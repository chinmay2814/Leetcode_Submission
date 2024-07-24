class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        stack<int>st;
        int n=nums.size();
        vector<int>ans;
        int req=n-k;
        for(int i=0;i<n;i++){
            while(st.size()&&nums[i]<st.top()&&req){
                st.pop();
                req--;
            }
            
            st.push(nums[i]);
        }
        while(st.size()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        ans.resize(k);


        return ans;
    }
};