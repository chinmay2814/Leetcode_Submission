class Solution {
public:
    int dp[1005];
    int fun(int ind, vector<pair<int,int>>& arr){
        if(dp[ind]!=-1) return dp[ind];
        int ans=arr[ind].second;
        for(int i=0;i<ind;i++){
            if(arr[i].second<=arr[ind].second){
                ans=max(ans,arr[ind].second+fun(i,arr));
            }
        }
        return dp[ind]=ans;
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>> arr;
        int n=ages.size();
        for(int i=0;i<n;i++){
            arr.push_back({ages[i],scores[i]});
        }
        sort(arr.begin(),arr.end());
        memset(dp,-1,sizeof(dp));
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,fun(i,arr));
        }
        return ans;
    }
};
