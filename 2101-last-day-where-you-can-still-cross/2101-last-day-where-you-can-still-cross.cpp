class Solution {
private:
    int n,m;
    int dir[5]={-1,0,1,0,-1};
public:
    bool isValid(int nr,int nc){
        return nr>=1&&nr<=m&&nc<=n&&nc>=1;
    }
    bool isPos(int day,vector<vector<int>>& cells){
        vector<vector<int>>grid(m+1,vector<int>(n+1,0));
        int ct=0;
        for (int i = 0; i < day; i++) {
            grid[cells[i][0]][cells[i][1]] = 1; 
        }
        queue<pair<int,int>>q;
        for(int i=1;i<=n;i++){
            if(grid[1][i]==0){
                q.push({1,i});
                grid[1][i]=1;
            }
        }
        while(q.size()){
            auto temp=q.front();
            int r=temp.first,c=temp.second;
            q.pop();
            for(int t=0;t<4;t++){
                int nr=r+dir[t];
                int nc=c+dir[t+1];
                if(isValid(nr,nc)&&grid[nr][nc]==0){
                    
                    if(nr==m)return true;
                    q.push({nr,nc});
                    grid[nr][nc]=1;

                }
            }
        }
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int lo=0;int hi=row*col;
        m=row;
        n=col;
        while(hi>=lo){
            int mid=(hi+lo)/2;
            if(isPos(mid,cells))lo=mid+1;
            else hi=mid-1;
        }
        return hi;
    }
};