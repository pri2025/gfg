class Solution {
public:
    int maxDepth(string s) {
        int cnt = 0;
        int ans = INT_MIN;
        for(char i : s){
            if(i == '(') cnt++;
            else if(i== ')')cnt--;
            ans = max(ans,cnt);
        }
        return ans;
    }
};