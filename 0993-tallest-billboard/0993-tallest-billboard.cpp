class Solution {
public:
    int dp[21][10005];
    int fun(int ind,int diff,vector<int>& rods){
        if(ind>=rods.size()){
            if(!diff)return 0;
            else return -1e9;
        }
        if(dp[ind][diff+5000]!=-1)return dp[ind][diff+5000];
        
        
        int a=fun(ind+1,diff,rods);
        int b=rods[ind]+fun(ind+1,diff+rods[ind],rods);
        int c=rods[ind]+fun(ind+1,diff-rods[ind],rods);

        return dp[ind][diff+5000]= max({a,b,c});
    }
    int tallestBillboard(vector<int>& rods) {
        memset(dp,-1,sizeof(dp));
        return fun(0,0,rods)/2;
    }
};