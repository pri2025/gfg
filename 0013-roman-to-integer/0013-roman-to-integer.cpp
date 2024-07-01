class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        map<char,int> mp;

        mp['I'] = 1; mp['L'] = 50;
        mp['V'] = 5; mp['C'] = 100;
        mp['X']= 10; mp['D'] = 500; mp['M'] = 1000;
        for(int i =0; i<s.length(); i++){
           if(mp[s[i]] < mp[s[i+1]]){
            ans += abs(mp[s[i]] - mp[s[i+1]]);
            i++;
           }
           else{
            ans += mp[s[i]];
           }
        }
        return ans;
    }
};