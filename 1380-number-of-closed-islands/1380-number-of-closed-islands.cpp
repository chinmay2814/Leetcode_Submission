class Solution {
public:
    int vis[101][101];

    void dfs(int i,int j,vector<vector<int>>& grid){
        grid[i][j]=-1;
        int n=grid.size();
        int m=grid[0].size();
        int d[]={-1,0,1,0,-1};
        for(int t=0;t<4;t++){
            int nr=i+d[t];
            int nc=j+d[t+1];
            if(nr>=0&&nc>=0&&nr<n&&nc<m&&grid[nr][nc]==0)dfs(nr,nc,grid);
        }
    }

    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0||j==0||i==n-1||j==m-1){
                    if(grid[i][j]==0)
                    dfs(i,j,grid);
                }
            }
        }
        int ct=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                    if(grid[i][j]==0){
                        ct++;
                    dfs(i,j,grid);}
                
            }
        }
        return ct;

        
    }
};