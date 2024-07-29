class Solution {
public:
    int n;
    
    bool ispos(int lo,int hi,string &s){
        while(lo<hi){
            if(s[lo]!=s[hi])return false;
            lo++;
            hi--;
        }
        return true;
    }
    int fun(int ind,string &s,vector<int>&dp){
        if(ind>=s.size()-1||ispos(ind,s.size()-1,s))return 0;
        if(dp[ind]!=-1)return dp[ind];
        int ans=1e9;
        for(int i=ind;i<s.size()-1;i++){   
            if(ispos(ind,i,s)){
                ans=min(ans,1+fun(i+1,s,dp));
            }
        }
        

        return dp[ind]=ans;

    }
    int minCut(string s) {
        n=s.size();
        vector<int>dp(n+1,-1);
        return fun(0,s,dp);
    }
};