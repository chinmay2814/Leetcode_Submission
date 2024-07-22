class Solution {
private:
    int vis[51][51];
    int dir[5]={-1,0,1,0,-1};
    int n,m;
    int ans=0;
    int isValid(int nr,int nc){
        return nr<n&&nr>=0&&nc<m&&nc>=0;
    }
    void dfs(int i,int j,vector<vector<int>>& grid,int &temp){
        if(vis[i][j])return ;
        vis[i][j]=1;
        temp++;
        for(int t=0;t<4;t++){
            int nr=i+dir[t];
            int nc=j+dir[t+1];
            if(isValid(nr,nc)&&grid[nr][nc]){
                
                dfs(nr,nc,grid,temp);
            }
        }
        ans=max(temp,ans);


    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]||grid[i][j]==0)continue;
                int temp=0;
                dfs(i,j,grid,temp);
            }
        }
        return ans;
        
    }
};