class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();

        double ans=INT_MIN;
        double pre=0,suf=0;

        for(int i=0;i<n;i++){
            if(pre==0)pre=1;
            if(suf==0)suf=1;

            pre*=nums[i];
            suf*=nums[n-i-1];

            ans=max({ans,pre,suf});

        }
        return ans;
    }
};