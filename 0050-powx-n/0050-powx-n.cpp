class Solution {
public: 
    // void fn(double x,int n, double &ans){
    //     if(n == 0) return;

    //     ans = ans*x;
    //     fn(x,n-1,ans);
    // }

    // void fnn(double x, int n, double &ans){
    //     if(n == 0) return;

    //     ans = ans/x;
    //     fnn(x,n+1, ans);
    // }
    double myPow(double x, int n) {
        double ans = 1.0;
        long long nn = n;
        if(nn < 0){
            nn = nn*-1;
        }
        
        while(nn){
            if(nn % 2){
                ans =  ans*x;
                nn = nn-1;
            }
            else{
                x = x*x;
                nn = nn/2;
            }
        }
        if(n < 0 ) return (double)(1.0)/(double)(ans);
        
        return ans;
    }
        // if(n > 0 && n%2== 0){
        //     fn(x,n/2,ans);
        //     return ans*ans;
        // }
        // else if(n>0 && n%2 != 0){
        //     fn(x,n/2,ans);
        //     return ans*ans*x;
        // }
        // n=n*-1;
        // if(n%2 == 0 ){
        //     fn(x,n/2,ans);
        //     return 1/(ans*ans);
        // }
    
        // fn(x,n/2,ans);
        // return 1/(ans*ans*x);
        
        // return ans;
        // if(n > 0){
        //     for(int i = 1; i<=n/2; i++){
        //         ans = ans*x;
        //     }
        // }
        // if(n<0){
        //     for(int i = n; i <0; i++){
        //         ans = ans/x;
        //     }
        // }
        // return ans;
    
    
};