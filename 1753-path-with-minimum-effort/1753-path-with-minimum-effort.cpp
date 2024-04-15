class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& h) {
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        int n=h.size();
        int m=h[0].size();
        int dis[n][m];
        for( int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dis[i][j]=1e9;
            }
        }
        pq.push({0,{0,0}});
        dis[0][0]=0;
        int dir[]={-1,0,1,0,-1};
        while(!pq.empty()){
            auto it=pq.top();
            int diff=it.first;
            int i=it.second.first;
            int j=it.second.second;

            pq.pop();
            if(i==n-1&&j==m-1)return diff;
            for(int t=0;t<4;t++){
                int nr=i+dir[t];
                int nc=j+dir[t+1];
                
                if(nr>=0&&nc>=0&&nr<n&&nc<m){
                    int newdiff=max(diff,abs(h[nr][nc]-h[i][j]));
                    if(newdiff<dis[nr][nc]){
                        dis[nr][nc]=newdiff;
                        pq.push({newdiff,{nr,nc}});
                    }
                }
            }


        }
          return 0;
    }
};