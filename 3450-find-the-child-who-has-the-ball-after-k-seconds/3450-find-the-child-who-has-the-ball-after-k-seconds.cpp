class Solution {
public:
    int numberOfChild(int n, int k) {
        n--;
        int dir=k/n;
        if(!(dir&1)){
            return k%n;
        }else{
            return n-(k%n);
        }
    }
};