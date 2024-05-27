class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,r=0;
        int maxi=0;
        vector<int>m(128,0);
        //m[s[0]]++;
        while(r<s.size()){
           if (m[s[r]] == 0) {
                m[s[r]]++;
                maxi = max(maxi, r - l + 1);
                r++;
            } else {
                m[s[l]]--;
                l++;
            }
        }
        return maxi;
    }
};