
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
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        DSU ds(n);
         for(int i=0; i<n-1; ++i){
            for(int j=i+1; j<n; ++j){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) ds.unionBySize(i,j);
            }
        }

        //no of component
        //har ek component se ek delete nahi kar sakte
        int cnt=0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i)cnt++;
        }
        return n-cnt;
    }
};