class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        long long sum=0;
        int ct=0;
        vector<long long>pre(n),suf(n);
        pre[0]=nums[0];
        suf[n-1]=nums[n-1];
        for(long long i=0;i<n;i++){
            sum+=nums[i];
            if(i!=0)pre[i]=pre[i-1]+nums[i];
          

        }
        for(long long i=0;i<n-1;i++){
            cout << pre[i]<< " ";
            if(pre[i]>=sum-pre[i])ct++;

        }
        return ct;
    }
};