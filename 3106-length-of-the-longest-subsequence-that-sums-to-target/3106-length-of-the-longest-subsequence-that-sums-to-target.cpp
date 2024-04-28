class Solution {
public:
    int dp[1005][1005];
    int fun(int ind, int tar,vector<int>& nums){
        if(tar==0)return 0;
        if(ind>=nums.size()||tar<0){
            return -1e9;
        }
        if(dp[ind][tar]!=-1)return dp[ind][tar];
        //int pick=-1e9;
        int npick=fun(ind+1,tar,nums);
        
            int pick=1+fun(ind+1,tar-nums[ind],nums);
        
        return dp[ind][tar]=max(npick,pick);

    }

    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        int ans=fun(0,target,nums);
        return (ans>0)?ans:-1;
    }
};