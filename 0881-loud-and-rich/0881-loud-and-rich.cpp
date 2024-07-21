class Solution {
public:
    int vis[501];
    void dfs(int ind,int node,vector<vector<int>>&adj,vector<int>& quiet, vector<int>&ans){
        if(vis[node])return;
        vis[node]=1;
        for(auto child:adj[node]){
            if(quiet[ans[child]]<quiet[ans[ind]]){
                ans[ind]=ans[child];
            }
            dfs(ind,child,adj,quiet,ans);
        }


    }


    
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n=quiet.size();
        vector<vector<int>>adj(n);
        for(auto it:richer){
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int>ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = i;
        }
        for(int i=0;i<n;i++){
            memset(vis,0,sizeof(vis));
            dfs(i,i,adj,quiet,ans);
        }
        return ans;

        
    }
};