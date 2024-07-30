class Solution {
public:
    int minimumDeletions(string s) {
        int cnt = 0;
        stack<char>st;
        for(char it: s){
            if( !st.empty()  && it == 'a' && st.top() == 'b'){
                st.pop();
                cnt++;
            }
            else
            st.push(it);
        }
        return cnt;
        // int del = INT_MAX;
        // int n= s.length();
        
        // for(int i =0; i<n-1;i++){
        //     int cnt = 0;
        //     //int fa =0, fb =0 ;
        //     for(int j = i+1;j<n;j++){
        //         if(s[j] == 'a'){
        //             cnt++;// fa = 1;
        //         }
        //     }
        //     for(int k = i-1; k>=0 ; k--){
        //         if(s[k] == 'b'){
        //             cnt++; //fb = 1;
        //         }
        //     }
        //     if(cnt == n) return 0;
        //    // if(fa == 0 || fb == 0) return 0;
        //     del = min(del,cnt);
        // }
        // return del;
    }
};