class Solution {
public:
    int fun(vector<int>& nums, int goal){
        if(goal<0)return 0;
        int l=0,r=0,sum=0;
        int ct=0;
        while(r<nums.size()){
            sum+=nums[r];
            
          
            while(sum>goal){
                if(nums[l]==1)
                    sum--;
                l++;
            }
            ct+=r-l+1;
            
            r++;
            
        }
        return ct;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return fun(nums,goal)-fun(nums,goal-1);
    }
};