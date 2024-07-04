class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string res = "";
        for(int i = 0; i <s.length();i++){
            if(s[i] != ' '){
                res += s[i];
            }
            else{
                if(!res.empty()){
                    words.push_back(res);
                    res = "";
                }
            }
        }
        if(!res.empty()){
            words.push_back(res);
        }

        string ans = "";
        for(int i = words.size()-1; i>=0; i--){
            ans += words[i];
            if(i != 0){
                ans += ' ';
            }
        }
        return ans;
    }
};

//string reverseWords(string &s) {
    //     vector<string> words;
    //     string word = "";
    //     for (int i = 0; i < s.length(); i++) {
    //         if (s[i] != ' ') {
    //             word += s[i];
    //         } else {
    //             if (!word.empty()) {
    //                 words.push_back(word);
    //                 word = "";
    //             }
    //         }
    //     }
    //     if (!word.empty()) {
    //         words.push_back(word);
    //     }

    //     string ans = "";
    //     for (int i = words.size() - 1; i >= 0; i--) {
    //         ans += words[i];
    //         if (i != 0) {
    //             ans += " ";
    //         }
    //     }
    //     return ans;
    // }