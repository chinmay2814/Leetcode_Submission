class Solution {
public:
    int dp[105];
    int fun(int ind,string s){
        if(ind==s.size()){
            return 1;
        };
        

        int a=0,b=0;
        if(s[ind]=='0'){
            return 0;
        }
        if(dp[ind]!=-1)return dp[ind];
         a=fun(ind+1,s);

        if(ind+1<s.size()&&stoi(s.substr(ind,2))<=26){
            b=fun(ind+2,s);
        }

        return dp[ind]=(a+b);
    }

    int numDecodings(string s) {
        memset(dp,-1,sizeof(dp));
        return fun(0,s);
    }
};