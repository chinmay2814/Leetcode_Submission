class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size(), index = -1;bool flag=false;
        for(int i=n-1;i>0;i--){
            if(nums[i]>nums[i-1]){
                flag=true;
                index = i-1;
                // swap(nums[i-1],nums[n-1]);
                // reverse(nums.begin()+i,nums.end());
                break;
            }
        }
         for(int i=n-1; i>=index && index != -1; i--){
            if(nums[i] > nums[index]){
                swap(nums[i], nums[index]);
                break;
            }
        }
        reverse(nums.begin() + index + 1, nums.end());
       // if(!flag)reverse(nums.begin(),nums.end());
    }
};