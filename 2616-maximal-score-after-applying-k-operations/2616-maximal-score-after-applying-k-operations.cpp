class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans=0;
        priority_queue<int> pq;
        for(auto it:nums){
            pq.push(it);
        }
        while(k--){
            int x=pq.top();
            ans+=pq.top();
            pq.pop();
            pq.push(ceil(x/3.0));

        }
        return ans;
        
    }
};