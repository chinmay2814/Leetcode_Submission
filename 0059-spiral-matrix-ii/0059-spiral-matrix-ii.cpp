class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
      

        int left=0,top=0;
        int right=n-1;
        int bottom =n-1;
        vector<vector<int>>matrix(n,vector<int>(n));
        int temp=1;
        while(top<=bottom&&left<=right){
        //right
        for(int i=left;i<=right;i++){
            matrix[top][i]=temp++;
        }
        top++;

        //down
        for(int i=top;i<=bottom;i++){
            matrix[i][right]=temp++;
        }
        right--;
        
        
        //left
        if(top<=bottom){
            for(int i=right;i>=left;i--){
                matrix[bottom][i]=temp++;
            }
            bottom--;
        }

        //up
        if(left<=right){
            for(int i=bottom;i>=top;i--){
                matrix[i][left]=temp++;
            }
            left++;
        }
        }
        return matrix;
    }
};