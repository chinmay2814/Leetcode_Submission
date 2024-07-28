class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> adj(n + 1);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 1});
        
        vector<int> first(n + 1, 1e9);  // Store the shortest distance
        vector<int> second(n + 1, 1e9); // Store the second shortest distance
        
        first[1] = 0;
        
        while (!pq.empty()) {
            auto [curr_time, node] = pq.top();
            pq.pop();
            
            // Adjust for the red light if necessary
            if ((curr_time / change) % 2 != 0) {
                curr_time = (curr_time / change + 1) * change;
            }
            
            for (int neighbor : adj[node]) {
                int new_time = curr_time + time;
                
                if (new_time < first[neighbor]) {
                    second[neighbor] = first[neighbor];
                    first[neighbor] = new_time;
                    pq.push({new_time, neighbor});
                } else if (new_time > first[neighbor] && new_time < second[neighbor]) {
                    second[neighbor] = new_time;
                    pq.push({new_time, neighbor});
                }
            }
        }
        
        return second[n];
    }
};
