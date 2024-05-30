class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int>m;
        m[0]=1;
        int presum;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            presum+=nums[i];
            ans+=m[presum-k];
            m[presum]++;

        }
        return ans;
    }
};