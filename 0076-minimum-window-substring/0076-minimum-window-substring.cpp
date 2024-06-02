class Solution {
public:
    string minWindow(string s, string t) {
        
        map<char,int>m;
        int l=0,r=0,ans=1e9,start=-1;
        int sindex=0,eindex=0;
        int check=t.size();
        int ct=0;
        for(auto i:t){
            m[i]++;
        }
        while(r<s.size()){
             if(m[s[r]]>0){
                ct++;
            }
            m[s[r]]--;
           
            while(ct==check){
                 if(ans>r-l+1){
                    start=l;
                    sindex=l;
                    eindex=r;
                    ans=min(ans,r-l+1);
                }
                m[s[l]]++;
                if(m[s[l]]>0)ct--;
                l++;
               
                
            }

            r++;
        }
       
        string res="";
        cout << start << " " << sindex <<  " " << eindex;
        for(int i=sindex;i<=eindex;i++){
            res+=s[i];
        }

        return  (start==-1?"":res);
        
    }
};