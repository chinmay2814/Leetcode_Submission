class Solution {
private:
    
public:
    const int x=1005;
    
    vector<vector<int>>adj;
    bool dfs(vector<vector<int>>&g,vector<int>&vis,int cur,int par){
        if(vis[cur])return true;
        vis[cur]=1;
        for(auto child:g[cur]){
            if(child==par)continue;
            if(dfs(g,vis,child,cur))return true;
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int>ans;
        int n=edges.size();
        vector<int>vis(n+1,0);
        
        
        vector<vector<int>>g(n+1);

        for(auto ele:edges){
            fill(vis.begin(), vis.end(), 0); 
            g[ele[0]].push_back(ele[1]);
            g[ele[1]].push_back(ele[0]);
            if(dfs(g,vis,ele[0],-1))return ele;


        }
        return ans;

        
        
    }
};