class Solution {
private:
    vector<vector<int>>adj;
public:
    int dfs(int node,int par,vector<bool>&ha){
        int time=0;
        for(auto &child:adj[node]){
            if(child==par)continue;
            int timec=dfs(child,node,ha);
            if(timec>0||ha[child]){
                time+=timec+2;
            }
        }
        return time;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& ha) {
        adj.resize(n);
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        return dfs(0,-1,ha);

        
    }
};