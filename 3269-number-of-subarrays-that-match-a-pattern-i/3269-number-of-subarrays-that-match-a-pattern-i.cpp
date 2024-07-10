class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n=nums.size();
        int m=pattern.size();
        int ct=0;

        for(int i=0;i<n-m;i++){
            bool c1=true,c2=true,c3=true;
            for(int j=0;j<m;j++){
                
                if(pattern[j]==1){
                    if(nums[i+j]>=nums[i+j+1])c1=false;
                }
                if(pattern[j]==0){
                    if(nums[i+j]!=nums[i+j+1])c2=false;
                }
                if(pattern[j]==-1){
                    if(nums[i+j]<=nums[i+j+1])c3=false;
                }
                
            }
            if(c1&&c2&&c3)ct++;
        }
        return ct;
    }
};