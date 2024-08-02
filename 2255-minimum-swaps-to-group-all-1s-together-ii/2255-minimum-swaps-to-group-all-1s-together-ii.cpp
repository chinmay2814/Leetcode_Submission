class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int one=0;
        for(auto &it:nums){
            one+=it;
        }
        int n=nums.size();
        int ct=0,maxi;
        for(int i=0;i<one;i++){
            ct+=nums[i];
        }
        maxi=ct;
        for(int i=one;i<n+one;i++){
            if(nums[i%n])ct++;
            if(nums[i-one])ct--;
            maxi=max(maxi,ct);
        }
        return one-maxi;
    }
};