class Solution {
public:

    int fn(int n, map<int,int>& mp){
        if(n== 0 || n== 1) return n;

        if(mp.find(n) != mp.end()) return mp[n];
        mp[n] = fn(n-1,mp) + fn(n-2, mp);
        return mp[n];
    }
    int fib(int n) {
        map<int,int> mp;
        return fn(n,mp);
    }
};

//  if(n ==0)
//         return 0;
//         if(n == 1)
//         return 1;
//         return fib(n-1) + fib(n-2); 