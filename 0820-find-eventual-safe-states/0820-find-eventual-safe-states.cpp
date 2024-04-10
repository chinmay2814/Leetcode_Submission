class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& pre) {
        int n = pre.size();
        vector<vector<int>> adj(n, vector<int>());
        vector<int> degree(n, 0);
        for (int i = 0; i < n; i++) {
            for (auto p : pre[i]) {
                adj[p].push_back(i);
                degree[i]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 0) {
                q.push(i);
            }
        }
        vector<int> ans;
        while (!q.empty()) {
            int vertex = q.front();
            q.pop();
            ans.push_back(vertex);
            for (auto child : adj[vertex]) {
                if (--degree[child] == 0) {
                    q.push(child);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
