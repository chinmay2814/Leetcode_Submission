class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        long long ct=0;
        int n=hours.size();
        map<int,int>m;
        for(int i=0;i<n;i++){
            ct+=m[(24-(hours[i]%24))%24];
            m[hours[i]%24]++;
            

        }
        return ct;
    }
};