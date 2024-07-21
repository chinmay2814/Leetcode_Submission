class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int ans = -1;
        int time = 0;
        vector<int> vis(edges.size(), 0);

        for (int cur = 0; cur < edges.size(); ++cur) {
            if (vis[cur] > 0)
                continue;
             int startTime = time;
            int u = cur;
            while (u != -1 && vis[u] == 0) {
                vis[u] = time++;
                u = edges[u];
            }
            if (u != -1 && vis[u] >= startTime)
                ans = max(ans, time - vis[u]);
        }

        return ans;
    }
};