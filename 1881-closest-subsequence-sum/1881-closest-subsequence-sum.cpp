class Solution {
public:
    vector<int> subsum(vector<int>&arr){
        vector<int>ans;
        int n=arr.size();
        for(int i=0;i<(1<<n);i++){
            int sum=0;
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    sum+=arr[j];
                }
            }
            ans.push_back(sum);
        }
        return ans;
    }
    int minAbsDifference(vector<int>& nums, int goal) {
        int n=nums.size();
        vector<int>a;
        vector<int>b;
        for(int i=0;i<(n+1)/2;i++){
            a.push_back(nums[i]);
        }
         for(int i=(n+1)/2;i<n;i++){
            b.push_back(nums[i]);
        }
        a=subsum(a);
        b=subsum(b);
        sort(b.begin(),b.end());
        int maxi=1e9;
        for(auto ele:a){
             int upper = upper_bound(b.begin(), b.end(), goal - ele) - b.begin();
            
            if (upper < b.size()) {
                maxi = min(maxi, abs(goal - ele - b[upper]));
            }
            if (upper > 0) {
                maxi = min(maxi, abs(goal - ele - b[upper - 1]));
            }
        }
        return maxi;
    }
};