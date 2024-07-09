class Solution {
public:
    // int fn(int index, unordered_map<int,int> mp){
    //     if(index == 0|| index== 1) return 1;

    //     if(mp.find(index)!= mp.end()) return mp[index];
    //     mp[index] = fn(index-1,mp) + fn(index-2,mp);
    //     return mp[index];
    // }
    int climbStairs(int n) {
        //vector<int> table(n+1, -1);
        //table[0]= 1; table[1] = 1;
        if(n == 0|| n==1) return 1;
        int first= 1; int second = 1;

        for(int i = 2; i <= n; i++){
           int curr = first+second;
           first = second;
           second = curr;
        }
        return second;
        //return table[n];
    }
};