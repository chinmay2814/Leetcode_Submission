class Solution {
public:

    int fun(int i,int j,vector<int>& nums,vector<vector<int>> &dp){
        if(i>j)return 0;
        int maxi=-1;
        if(dp[i][j]!=-1)return dp[i][j];
        for(int k=i;k<=j;k++){
            int coins=nums[i-1]*nums[k]*nums[j+1]+fun(i,k-1,nums,dp)+fun(k+1,j,nums,dp);
            maxi=max(maxi,coins);
        }

        return dp[i][j]=maxi;
    }


    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>> dp(nums.size()+3,vector<int>(nums.size()+3,-1));
        return fun(1,nums.size()-2,nums,dp);
    }
};