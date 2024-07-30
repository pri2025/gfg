class Solution {
public:
    bool checkString(string s) {
        int ind = -1; int cnt = 0;
        for(char it : s){
            ind++;
            if(it == 'b') break;
            else cnt++;
        }
        if(cnt == s.length()) return true;

        for(int i = ind; i<s.length();i++){
            if(s[i] == 'a') 
            {
                return false;
            }
        }
        return true;
    }
};