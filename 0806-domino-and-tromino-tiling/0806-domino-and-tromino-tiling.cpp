class Solution {

public:
    int mod=1000000007;
    int numTilings(int n) {
        long long int f[n+1],g[n+1];
        f[0]=1;
        g[0]=0;
        f[1]=1;
        g[1]=1;
        for(int i=2;i<=n;i++){
            f[i]=f[i-1]+f[i-2]+(2*g[i-2]);
            f[i]%=mod;
            g[i]=g[i-1]+f[i-1];
            g[i]%=mod;
        }
        return f[n]%mod;
    }
};