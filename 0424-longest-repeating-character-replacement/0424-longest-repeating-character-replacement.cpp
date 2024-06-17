class Solution {
public:
    int characterReplacement(string s, int k) {
        int len = 0;
        for(int i = 0; i<s.length() ; i++){
            int mp[26] = {0};   int maxf = 0;
            int change=0;
            for(int j = i; j<s.length(); j++){
                mp[s[j] - 'A']++;
                maxf = max(maxf, mp[s[j] - 'A']);
                change = (j-i+1)- maxf; // abhi jitni substring hai usmein
                //kitna change kr skte
                if(change <= k){ //agr valid hai to maxlen cal krte raho else break
                    len = max(len, j-i+1);
                }
                else{
                    break;
                }
            }
        }
        return len;
    }
         
};



//while(j <n){
    //         mp[s[j]]++;
    //         if(s[i] != s[j]){
    //             change++;
    //         }
    //         while(change>k){
    //             if(s[i] == s[j]){
    //                 mp[s[i]]--;
    //                 change--;
    //             }
    //             mp[s[i]]--;
    //             i++;
    //         }
    //         len = max(len, j-i+1);
    //         j++;
    //     }
    // }