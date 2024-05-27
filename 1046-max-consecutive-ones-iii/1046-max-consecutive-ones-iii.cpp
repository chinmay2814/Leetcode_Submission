class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int  l=0,r=0,maxi=0;
        int zero=0;
        while(r<nums.size()){
            if(nums[r]==0)zero++;

            while(zero>k){
                if(nums[l]==0){
                    zero--;
                }
                l++;
            }
            maxi=max(maxi,r-l+1);
            r++;
        }
        return maxi;
    }
};