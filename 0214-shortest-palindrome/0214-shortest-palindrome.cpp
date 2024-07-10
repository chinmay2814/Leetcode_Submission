class Solution {
public:
   
    string shortestPalindrome(string s) {
        int n=s.size();
        int MOD=1000000007;
        int ind=-1;
        long long k=31,p=1;
        int fHash=0,bHash=0;
        for(int i=0;i<n;i++){
            fHash=(fHash+(s[i]-'a')*p)%MOD;
            bHash=(bHash*k+(s[i]-'a'))%MOD;
            p=p*k%MOD;
            if(bHash==fHash)ind=i;
        }
        string rem="";
        for(int i=n-1;i>ind;i--){
            rem+=s[i];
        }
        cout <<rem;
        return(rem+s);
        
        
    }
};