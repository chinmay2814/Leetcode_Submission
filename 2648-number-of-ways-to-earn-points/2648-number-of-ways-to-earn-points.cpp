class Solution {
public:
    const int M=1e9+7;
    int dp[51][1005][51];
    int fun(int ind,int cur,int tar, vector<vector<int>>& types){
        //cout << "ys"<<endl;
        
        if(tar<0||ind>=types.size()||cur>types[ind][0]){
            return 0;
        }
        if(tar==0)return 1;
        if(dp[ind][tar][cur]!=-1)return dp[ind][tar][cur];
        int pick=0;
        pick+=fun(ind,cur+1,tar-types[ind][1],types)%M;
        pick+=fun(ind+1,0,tar,types)%M;
        return dp[ind][tar][cur]=pick%M;

    }
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        int n=types.size();
        memset(dp,-1,sizeof(dp));
        return fun(0,0,target,types)%M;
        
    }
};