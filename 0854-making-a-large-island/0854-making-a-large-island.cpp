
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
private:
    bool isValid(int r,int c,int n){
        return (r>=0&&r<n&&c>=0&&c<n);
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        DSU ds(n*n);
        int ct=0;
        int dir[]={-1,0,1,0,-1};
        for(int r=0;r<n;r++){
            for(int c=0;c<n;c++){
                if(!grid[r][c])continue;
                ct++;
                for(int t=0;t<4;t++){
                    int nr=r+dir[t];
                    int nc=c+dir[t+1];
                    if(isValid(nr,nc,n)&&grid[nr][nc]){
                        int curN=r*n+c;
                        int adjN=nr*n+nc;
                        ds.unionBySize(curN,adjN);
                    }

                }
                
            }
        }
        //
        int ans=0;
        for(int r=0;r<n;r++){
            for(int c=0;c<n;c++){
                if(grid[r][c])continue;
                set<int>comp;
                for(int t=0;t<4;t++){
                    int nr=r+dir[t];
                    int nc=c+dir[t+1];
                    if(isValid(nr,nc,n)&&grid[nr][nc]){
                        int curN=r*n+c;
                        int adjN=nr*n+nc;
                        comp.insert(ds.findUParent(adjN));
                    }
                    int size=1;
                    for(auto it:comp){
                        size+=ds.size[it];
                    }
                    ans=max(size,ans);

                }

                
            }
        }
        if(ct==n*n)return n*n;
        return ans;
        
    }
};