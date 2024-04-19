
class DSU
{
public:
    vector<int> rank, parent, size;
    DSU(int n)
    {
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }
    int findUParent(int node)
    {
        if (node == parent[node])
            return node;
        parent[node] = findUParent(parent[node]);
        return parent[node];
    }
    void unionByRank(int u, int v)
    {
        int ultp_u = findUParent(u);
        int ultp_v = findUParent(v);
        if (ultp_u == ultp_v)
            return;
        if (rank[ultp_u] > rank[ultp_v])
        {
            parent[ultp_v] = ultp_u;
        }
        else if (rank[ultp_v] > rank[ultp_u])
        {
            parent[ultp_u] = ultp_v;
        }
        else
        {
            parent[ultp_u] = ultp_v;
            rank[ultp_v]++;
        }
    }
    void unionBySize(int u, int v)
    {
        int ultp_u = findUParent(u);
        int ultp_v = findUParent(v);
        if (ultp_u == ultp_v)
            return;
        if (size[ultp_u] > size[ultp_v])
        {
            parent[ultp_v] = ultp_u;
            size[ultp_u] += size[ultp_v];
        }
        else
        {
            parent[ultp_u] = ultp_v;
            size[ultp_v] += size[ultp_u];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& edge) {
        DSU ds(n);
        int extra_edge=0;
        for(auto it:edge){
            int u=it[0];
            int v=it[1];
            if(ds.findUParent(u)==ds.findUParent(v)){
                extra_edge++;
            }else{
                ds.unionBySize(u,v);
            }
        }
        int tc=0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i)tc++;
        }
        if(tc-1<=extra_edge){
            return tc-1;
        }else return -1;

        
    }
};