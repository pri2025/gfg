class Solution {
public:
    int countSeniors(vector<string>& arr) {
        int cnt = 0;
        for(auto it :arr){
           int temp = 0;
           temp = (it[11]- '0')*10 + it[12]-'0';
            if(temp > 60) cnt++;
        }
        return cnt;
    }
};