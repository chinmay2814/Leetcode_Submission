class Solution {
public:
    int closestToTarget(vector<int>& nums, int k) {
        set<int>curr;
        int ans=INT_MAX;

        for(int i=0;i<nums.size();i++){
            set<int>next;
            for(auto it:curr){
                next.insert(it&nums[i]);
                
            }
            next.insert(nums[i]);

            for(auto it:next){
                ans=min(ans,abs(k-it));
            }

            curr=next;
        }
        return ans;
    }
};