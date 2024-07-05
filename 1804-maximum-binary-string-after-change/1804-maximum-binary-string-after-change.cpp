class Solution {
public:
    string maximumBinaryString(string s) {
        int ct=0,i=0,temp=0;
        while(s[i]=='1'){
            i++;
            temp++;
        }
        while(i<s.size()){
            if(s[i]=='0')ct++;
            i++;
        }
        if(ct<2)return s;
        
        i=0;
        while(i<s.size()){
            s[i]='1';
            i++;

        }
        
        s[temp+ct-1]='0';

        return s;
        
    }
};