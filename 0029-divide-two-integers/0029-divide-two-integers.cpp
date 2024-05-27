class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==-2147483648&&divisor==-1){
           return pow(2,31)-1;
        }
        return dividend/divisor;
    }
};