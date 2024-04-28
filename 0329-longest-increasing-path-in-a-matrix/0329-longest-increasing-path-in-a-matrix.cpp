class Solution {
public:
    int dp[205][205];
    int fun(int i,int j,vector<vector<int>>& matrix){
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=1;
        int d[]={-1,0,1,0,-1};
        //if(dp[i][j]!=-1)return dp[i][j];
        for (int t=0;t<4;t++){
            int nr=i+d[t];
            int nc=j+d[t+1];
            if(nr>=0&&nc>=0&&nr<matrix.size()&&nc<matrix[0].size()){
                if(matrix[i][j]>=matrix[nr][nc])continue;
                int pick=1+fun(nr,nc,matrix);
                    ans=max(ans,pick);
                    
                
            }
        }
        return dp[i][j]=ans;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int res=1;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                res=max(res,fun(i,j,matrix));
            }
        }
        return res;
        
    }
};