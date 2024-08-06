class Solution {
public:
 vector<vector<int>> subsum(vector<int>&arr){
        
        int n=arr.size();
        vector<vector<int>>ans(n+1);
        for(int i=0;i<(1<<n);i++){
            int sum=0;int len=0;
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    sum+=arr[j];
                    len++;
                }
            }
            ans[len].push_back(sum);
        }
        return ans;
    }
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> a(nums.begin(), nums.begin() + n / 2);
        vector<int> b(nums.begin() + n / 2, nums.end());

        auto l = subsum(a);
        auto r = subsum(b);

        int maxi = 1e9;
        int tsum = accumulate(nums.begin(), nums.end(), 0);
        int goal = tsum / 2;

        for (int i = 0; i <= n / 2; i++) {
            sort(r[i].begin(), r[i].end());
        }

        for (int i = 0; i <= n / 2; i++) {
            for (auto ele : l[i]) {
                int req = goal - ele;
                int rem = n / 2 - i;
                if (rem < 0 || rem >= r.size()) continue;
                auto it = upper_bound(r[rem].begin(), r[rem].end(), req);
                if (it != r[rem].end()) {
                    maxi = min(maxi, abs(tsum - 2 * (*it + ele)));
                }
                if (it != r[rem].begin()) {
                    --it;
                    maxi = min(maxi, abs(tsum - 2 * (*it + ele)));
                }
            }
        }
        return maxi;
    }
};