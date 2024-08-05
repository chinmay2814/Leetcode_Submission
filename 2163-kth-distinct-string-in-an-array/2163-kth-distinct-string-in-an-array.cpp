class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int>mpp;
        for(auto it:arr){
            mpp[it]++;
        }
       
        for(int i=0;i<arr.size();i++){
            if(mpp[arr[i]]==1){
                k--;
                if(k==0)return arr[i];
            }
        }
        return "";
    }
};