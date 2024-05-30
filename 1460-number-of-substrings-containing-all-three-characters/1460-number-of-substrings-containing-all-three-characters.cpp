class Solution {
public:
    int numberOfSubstrings(string s) {
        int hash[3]={0};
        int ans=0;
        for(int i=0;i<s.size();i++){
            hash[s[i]-'a']=i+1;
            int mini=min({hash[0],hash[1],hash[2]});
            if(mini==-1)continue;
            ans+=mini;
        }
        return ans;
    }
};