class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        unordered_map < int, int> same[60];
        int others[60] = {1};
        int dp[5010][60] = {1};
        
        for(int i = 0;i <= k;i ++){
            same[i][nums[0]] = 1;
            others[i] = 1;
        }
        for(int i = 1;i < nums.size();i ++){
            for(int j = k;j >= 0;j --){
                dp[i][j] = (j > 0) ? dp[i][j - 1] : 1;
                int val = same[j][nums[i]];
                if(j > 0 && others[j - 1] > val)
                    val = others[j - 1];
                dp[i][j] = max(dp[i][j], val + 1);
                same[j][nums[i]] = max(dp[i][j], same[j][nums[i]]);
                others[j] = max(others[j], dp[i][j]);
            }
        }
        int ans = 1;
        for(int i = 0;i < nums.size();i ++){
            ans = max(ans, dp[i][k]);
        }
        
        return ans;
    }
};