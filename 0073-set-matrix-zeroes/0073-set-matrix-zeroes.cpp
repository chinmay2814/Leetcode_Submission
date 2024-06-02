class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

        set<int>sr,sc;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!matrix[i][j]){
                    sr.insert(i);
                    sc.insert(j);
                }
            }
        }    
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(sr.find(i)!=sr.end()||sc.find(j)!=sc.end()){
                    matrix[i][j]=0;
                }
            }
        } 
            
        
    }
};