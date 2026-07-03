class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        if(dividend == divisor)return 1;
        bool sign =  true;
        if((dividend>0 && divisor<0 )||(dividend<0 && divisor>0 ) ) sign = false;
        long long n = abs((long long)dividend);
        long long m = abs((long long)divisor);
        long long sum =0;
        while(n>=m){
            int count =0;
            while(n>=(m<<count)){
                count++;
            }
            count--;
            sum += (1LL<<count);
            n-=(m<<count);
        }
        if(sum>INT_MAX && sign){
            sum = INT_MAX;
        }
        if(sum>INT_MAX && !sign){
            sum = INT_MIN;
        }
        if(sign){
            return sum;
        }
        return -sum;
    }
};