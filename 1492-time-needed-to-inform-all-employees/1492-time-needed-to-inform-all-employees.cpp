class Solution {
public:
    int numOfMinutes(int n, int hID, vector<int>& M, vector<int>& IT) {
       
        vector<int>adj[n+1];
        for(int i=0;i<n;i++){
            if(M[i]==-1)continue;
            adj[M[i]].push_back(i);
        }
        
        queue<pair<int,int>>q;
        //time,node
        q.push({IT[hID],hID});

        int ans=0;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int time=it.first;
            int node=it.second;

            for(auto child:adj[node]){
                q.push({time+IT[child],child});
                ans=max(ans,time+IT[child]);
            }

        }
        return ans;
    }
};