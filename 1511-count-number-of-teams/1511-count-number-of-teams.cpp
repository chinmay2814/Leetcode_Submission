class Solution {
public:
    int numTeams(vector<int>& r) {
        int n=r.size();

        vector<vector<int>>nxt(n),pre(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(r[j]>r[i])nxt[i].push_back(j);
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=i-1;j>=0;j--){
                if(r[j]>r[i])pre[i].push_back(j);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(auto ele:nxt[i]){
                ans+=(nxt[ele].size());
            }
        }
        for(int i=n-1;i>=0;i--){
            for(auto ele:pre[i]){
                ans+=(pre[ele].size());
            }
        }
        return ans;
    }
};