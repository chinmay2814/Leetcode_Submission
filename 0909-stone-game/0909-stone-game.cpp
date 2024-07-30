class Solution {
private:
    int dp[505][505];
public:

    int fun(int lyt,int ryt,int flag,vector<int>&p){
        if(lyt>ryt)return 0;
        if(lyt==ryt)return p[lyt];
        if(dp[lyt][ryt]!=-1)return dp[lyt][ryt];
        int ans;
        if(flag){
             ans=max(p[lyt]+fun(lyt+1,ryt,!flag,p),p[ryt]+fun(lyt,ryt-1,!flag,p));
        }else{
            ans=min(-p[lyt]+fun(lyt+1,ryt,!flag,p),-p[ryt]+fun(lyt,ryt-1,!flag,p));

        }

        return dp[lyt][ryt]=ans;


    }

    bool stoneGame(vector<int>& p) {
        int n=p.size();
        memset(dp,-1,sizeof(dp));
        return fun(0,n-1,1,p);
    }
};