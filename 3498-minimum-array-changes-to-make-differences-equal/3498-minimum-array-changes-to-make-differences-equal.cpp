class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        map<int, vector<int>> diffMap;
        vector<int> maxValues;
        
        for (int i = 0; i < nums.size() / 2; ++i) {
            int a = nums[i];
            int b = nums[nums.size() - i - 1];
            int diff = abs(a - b);
            int maxValue = max({a, b, k - a, k - b});
            diffMap[diff].push_back(maxValue);
            maxValues.push_back(maxValue);
        }
        
        int ans = nums.size();
        sort(maxValues.begin(), maxValues.end());
        
        for (const auto& [diff, values] : diffMap) {
            int ct = lower_bound(maxValues.begin(), maxValues.end(), diff) - maxValues.begin();
            ct = ct * 2 + (nums.size() / 2 - ct);
            
            for (int maxValue : values) {
                ct -= (maxValue < diff) ? 2 : 1;
            }
            
            ans = min(ans, ct);
        }
        
        return ans;
    }
};