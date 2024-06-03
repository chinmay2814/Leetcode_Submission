class Solution {
    
public:
    
    //int dp[2005][2005];
     unordered_map<int, unordered_map<int, int>> dp;
    int fun(int ind,int prev,vector<int>& arr1, vector<int>& arr2){
        if(ind>=arr1.size())return 0;
        if (dp[ind].count(prev)) return dp[ind][prev];
        //if(dp[ind][prev+1]!=-1)return dp[ind][prev+1];

        int ub=upper_bound(arr2.begin(),arr2.end(),prev)-arr2.begin();

        
        int nchange=1e9,change=1e9;
        if(ub<arr2.size()){
            change=1+fun(ind+1,arr2[ub],arr1,arr2);
        }
        if(arr1[ind]>prev){
            nchange=fun(ind+1,arr1[ind],arr1,arr2);
        }
        return dp[ind][prev]=min(change,nchange);

    }

    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(),arr2.end());
        //memset(dp,-1,sizeof(dp));
         dp.clear();

        int ans= fun(0,-1,arr1,arr2);
        return ans>=1e9?-1:ans;
    }
};