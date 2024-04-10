class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n, vector<int>());
    vector<int> degree(n, 0);
    for (auto &p: pre) {
        adj[p[1]].push_back(p[0]);
        degree[p[0]]++;
    }
    queue<int>q;
    for(int i=0;i<n;i++){
        if(!degree[i])q.push(i);
    }
    int ct=0;
    vector<int>ans;
    while(!q.empty()){
        int vertex=q.front();
        q.pop();
        ct++;
        ans.push_back(vertex);
        for(auto child:adj[vertex]){
            if(--degree[child]==0)q.push(child);
        }

    }
    for(auto i:ans){
        cout << i << " ";
    }
    vector<int>c;
    return (n==ct?ans:c);
        
    }
};