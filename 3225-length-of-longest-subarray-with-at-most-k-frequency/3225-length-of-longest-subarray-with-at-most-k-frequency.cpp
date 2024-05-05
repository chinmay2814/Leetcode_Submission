class Solution {
public:
    int maxSubarrayLength(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        int n = arr.size();
        int l = 0, r = 0, cnt {};
        while(r < n)
        {
            int cur = arr[r++];
            mp[cur]++;
            while(l < r && mp[cur] > k)
            {
                mp[arr[l++]]--;
            }
            cnt = max(cnt, r - l);
        }
        return cnt;
    }
};