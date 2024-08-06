class Solution {
public:
    int minimumPushes(string word) {
        sort(word.begin(),word.end());
        map<char,int>m;
        for(auto it:word){
            m[it]++;
        }
        vector<int>v;
        
        ;
        int layer=m.size()/8;
        for(auto it:m){
            //cout << it.first<< " - "<<it.second<<endl;
            v.push_back(it.second);
        }
        sort(v.rbegin(),v.rend());
        
        int ans=0;
        for(int i=1;i<=v.size();i++){
            cout << v[i-1] << " ";
            ans+=v[i-1]*((i+7)/8);
        }
        return ans;

    }
};