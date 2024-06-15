class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> st;
        int i=0;
         int j = 0;
         int len = 0;
        for(i = 0; i< s.length(); i++){
            while(st.find(s[i]) != st.end() && j <= i){ //abcabcbb
                st.erase(s[j]);
                j++;
            }
            st.insert(s[i]);
            len = max(len, i-j+1);
        }
        return len;
    }
};
//worst case o(2*n) vaise o(n);

//string ans = ""; 
        // string temp = "";
        // if(s == " "){
        //     return 1;
        // }
        // for(int i =0 ;i<s.length() ; i++){
        //     if(mpp.find(s[i]) == mpp.end()){
        //         mpp[s[i]] = 1;
        //         temp = temp+s[i];
        //     }
        //     else if(ans.empty()){
        //         ans =temp;
        //         temp = "";
        //         if(s[i] != s[i-1]){
        //             temp = temp + s[i-1];
        //         }
        //         //mpp[s[i]]++;
        //         temp = temp+s[i];
        //     }
        //     else{
        //         if(temp.length() > ans.length()){
        //             ans = temp;
        //         }
        //         for(int i = 0; i<s.length(); i++){
        //             mpp[s[i]] = 0;
        //         }
        //         temp = "";
        //         temp = temp+s[i];
        //     }
        // }
        // if(!temp.empty() && temp.length() > ans.length()){
        //     return temp.length();
        // }
        // return ans.length();