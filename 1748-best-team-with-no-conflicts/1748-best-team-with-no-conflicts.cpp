class Solution {
public:
    int dp[1005][1005];
    int fun(int ind, int prev, vector<pair<int,int>>& arr){
        if(ind==arr.size()){
            return 0;
        }
        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
        int npick=fun(ind+1,prev,arr);
        int pick=-1e9;
        if(prev==-1||arr[prev].first>=arr[ind].first||arr[prev].second<=arr[ind].second){
            pick=arr[ind].second+fun(ind+1,ind,arr);
        }
        return dp[ind][prev+1]=max(pick,npick);
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>> arr;
        int n=ages.size();
        for(int i=0;i<n;i++){
            arr.push_back({ages[i],scores[i]});
        }
        sort(arr.begin(),arr.end());
        memset(dp,-1,sizeof(dp));
        return fun(0,-1,arr);
    }
};
