class Solution {
public:
    vector<int> dx = {1,-1,0,0};
    vector<int> dy = {0,0,1,-1};
    int dp[1001][1001];
    int mod = 1e9 + 7;
    bool isValid(int i,int j,int m,int n){
        return i>=0 && i<m && j>=0 && j<n;
    }
    int dfs(int i,int j,int m,int n,vector<vector<int>>& grid){
        int ans = 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        for(int k=0;k<4;k++){
            int adj_i = dx[k] + i,adj_j = dy[k] + j;
            if(isValid(adj_i,adj_j,m,n) && grid[i][j] < grid[adj_i][adj_j])
                ans = (ans + dfs(adj_i,adj_j,m,n,grid)) % mod;
        }
        return dp[i][j] = 1 + ans;
    }
    int countPaths(vector<vector<int>>& grid) {
        int m = grid.size(),n = grid[0].size(),ans = 0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
                ans = (ans + dfs(i,j,m,n,grid)) % mod;
        }
        return ans;
    }
};