class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>adj[n+1];
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        int INF=1e9;
        vector<int>dist(n+1,INF);
        //{wt,node}
        set<pair<int,int>>st;
        st.insert({0,k});
        dist[k]=0;
        while(st.size()){
            auto node =*st.begin();
            int len=node.first;
            int vertex=node.second;
            st.erase(st.begin());
            for(auto ele:adj[vertex]){
                int edW =ele.second;
                int child=ele.first;

                if(len+edW<dist[child]){
                    dist[child]=len+edW;
                    st.insert({len+edW,child});
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(dist[i]==INF)return -1;
            ans=max(ans,dist[i]);
        }
        return ans;



    }
};