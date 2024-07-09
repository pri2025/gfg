class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if(n == 0) return 0;
        if(n == 1) return cost[0];

        int first = cost[0], sec = cost[1]; 
        int c = 0;
        for(int i = 2; i<n; i++){
            c = cost[i] + min(first, sec);
            first = sec;
            sec = c;
        }
        return min(first,sec);
    }
}; 