class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<long long,long long>>adj[n];
        long long mod=1e9+7;
        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<long long, long long>,
                    vector<pair<long long, long long>>, 
                    greater<pair<long long,long long>>> pq;
        
        vector<long long>dist(n,LONG_MAX),dp(n,0);
        pq.push({0,0});
        dist[0]=0;
        dp[0]=1;
        while(!pq.empty()){
            long long len=pq.top().first;
            long long node=pq.top().second;
            pq.pop();

            for(auto child:adj[node]){
                long long adjnode=child.first;
                long long edW=child.second;


                if(len+edW<dist[adjnode]){
                    dist[adjnode]=len+edW;
                    dp[adjnode]=dp[node];
                    pq.push({len+edW,adjnode});

                }else if(len+edW==dist[adjnode]){
                    dp[adjnode]=(dp[adjnode]+dp[node])%mod;
                }
            }
        }

        return (int)dp[n-1]%mod;



    }
};