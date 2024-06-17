class Solution {
public:
    int numberOfSubstrings(string s) {
        int count =0;
        int n = s.length();
        int i=0,j=0;
        map<char,int> mp;
        while(j <n){
            mp[s[j]]++;

            while(mp['a'] > 0 && mp['b'] > 0 && mp['c'] > 0){
                count = count + n - j;
                mp[s[i]]--;
                i++;
            }
            j++;
        }
        return count;
    }
};

//for(int i =0; i<n ; i++){
        //     int cnt1 = 0, cnt2 = 0, cnt3 = 0;
        //     for(int j= i;j<n ;j++){
        //         if(s[j] - 'a' == 0){
                   
        //             cnt1++;
        //            // cout<<cnt1<<" ";
        //         }
        //         if(s[j] -'a' == 1){
        //             ///cout<<"enterb"<<" ";
        //             cnt2++;
        //         }
        //         if(s[j] - 'a'== 2){
        //             //cout<<"enterc"<<" ";
        //             cnt3++;
        //         }
        //         if(cnt1 >0 && cnt2>0 && cnt3>0){
                
        //             count++;
                    
        //         }
        //     }
        // }