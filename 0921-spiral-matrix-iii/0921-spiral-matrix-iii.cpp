class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        vector<vector<int>> dir =  {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; 
         vector<vector<int>> res;  
        int len = 0, d = 0; 
        res.push_back({r0, c0});
        while (res.size() < R * C) {
            if (d == 0 || d == 2) len++; 
            for (int i = 0; i < len; i++) {
                r0 += dir[d][0];
                c0 += dir[d][1];
                if (r0 >= 0 && r0 < R && c0 >= 0 && c0 < C) 
                    res.push_back({r0, c0});
            }
            d = (d +1) % 4; 
        }
        return res;
    }
};