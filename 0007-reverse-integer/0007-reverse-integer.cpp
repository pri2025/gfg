class Solution {
public:
    int reverse(int x) {
        int num = x;
        int digit;
        int newn = 0;
        int bl = 0;
        if(num < 0){
            num = abs(num);
            bl = 1;
        }
        while(num>0){
            digit = num % 10;
            if(newn > INT_MAX/10) return 0; 
            newn = newn*10 + digit;
            num = num/10;
        }
        
        if(bl == 0){
            return newn;
        }
        return newn*(-1);
    }
};