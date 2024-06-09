class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        vector<int>ans(n,1);
        int mod=1e9+7;
        while(k--){
            for(int i=1;i<n;i++){
                ans[i]+=ans[i-1];
                ans[i]%=mod;
            }
        }
        return ans[n-1];
    }
};