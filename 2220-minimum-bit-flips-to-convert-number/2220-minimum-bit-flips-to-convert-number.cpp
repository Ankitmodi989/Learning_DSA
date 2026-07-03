class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ele = start ^ goal;
        int count =0;
        while(ele>0){
            int rem = ele%2;
            if(rem==1)
            count++;
            ele/=2;
        }
        return count;
    }
};