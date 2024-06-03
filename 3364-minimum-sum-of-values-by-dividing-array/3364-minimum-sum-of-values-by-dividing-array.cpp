class Solution {
public:
    vector<vector<unordered_map<int,int>>>dp;

    int fun(int i,int j,int curAND,vector<int>& nums, vector<int>& andValues){
        if(i>=nums.size()){
            if(j>=andValues.size())return 0;
            else return 1e7;
        }else if(j>=andValues.size()){
            return 1e7;
        }
        if(dp[i][j].find(curAND)!=dp[i][j].end())return dp[i][j][curAND]; 
        int pick=1e7;
        if((nums[i]&curAND)==andValues[j]){
            pick=nums[i]+fun(i+1,j+1,(1<<20)-1,nums,andValues);
        }
        int keep=fun(i+1,j,nums[i]&curAND,nums,andValues);
       
        return dp[i][j][curAND]=min(pick,keep);

    }
    int minimumValueSum(vector<int>& nums, vector<int>& andValues) {
        dp.resize(nums.size(),vector<unordered_map<int,int>>(10));

//1<<20 -1 as AND decresing fun hai aur max possible value hai 1<<18
        int ans= fun(0,0,(1<<20)-1,nums,andValues);
        return (ans==1e7?-1:ans);
    }
};