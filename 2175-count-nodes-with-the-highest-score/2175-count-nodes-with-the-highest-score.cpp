class Solution {
public:
    vector<int> adj[100005];
    long long res[100005];
    int ans = 0;
    int n;

    int dfs(int node) {
        int size=1;
        long long ans=1;
        for(auto child:adj[node]){
            int sub=dfs(child);
            size+=sub;
            ans*=sub;

        }
        if(size!=n){
            ans*=(n-size);
        }
        res[node]=ans;
        return size;
        
    }

    int countHighestScoreNodes(vector<int>& p) {
        n = p.size();
        for (int i = 1; i < n; i++) {
            adj[p[i]].push_back(i);
        }

        dfs(0);

        long long maxi = 0;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, res[i]);
        }

        int ct = 0;
        for (int i = 0; i < n; i++) {
            if (maxi == res[i]) ct++;
        }

        return ct;
    }
};
