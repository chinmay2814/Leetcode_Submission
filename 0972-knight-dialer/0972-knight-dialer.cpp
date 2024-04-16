class Solution {
public:
    vector<int>k[10];
    int dp[5005][10];
    const int M=1e9+7;
    int fun(int n,int jump){
        if(jump<=0){
            return 1;
        }
        if(dp[jump][n]!=-1)return dp[jump][n];
        int res=0;
        for(auto num:k[n]){
            res+=fun(num,jump-1);
            res=res%M;
        }
        return dp[jump][n]=res%M;
    }
    int knightDialer(int n) {
       // vector<int>k[10];
        k[0]={4,6};
        k[1]={6,8};
        k[2]={7,9};
        k[3]={4,8};
        k[4]={3,9,0};
        k[5]={};
        k[6]={1,7,0};
        k[7]={2,6};
        k[8]={1,3};
        k[9]={2,4};
        int ans=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<=9;i++){
            ans=(ans+fun(i,n-1))%M;
        }
        
        // for(auto i:k[0]){
        //     cout << i <<endl;
        // }
        return ans%M;
   
        
    }
};