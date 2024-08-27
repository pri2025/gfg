class Solution {
    public int reverse(int x) {
        int newn = 0 ;
        int flag = 0;

        if(x < 0){
            x = -x;
            flag = 1;
        }
        while(x >0){
            int d = x%10;
            x = x/10;
            if(newn > INT_MAX/10) return 0 ;
            newn = newn*10 + d;
        }
        if(flag == 1){
            return -newn;
        }
        return newn;
    }
}