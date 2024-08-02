class Solution {
public:
    
    string cal(string &str1, string &str2){ 
        string ans= "";
    for(int i = 0 ; i<min(str1.length(),str2.length());i++){
        if(str1[i] == str2[i]){
            ans.push_back(str1[i]);
        }//ab aaa
        else
        break;
    }
    cout<<ans<<" ";
  return ans;
}// abca aba aaab
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        int mini = INT_MAX;
        for(int i = 0; i<n; i++){
            if(strs[i].length() < mini){
                mini = strs[i].length();
            }
        }
        string temp = strs[0].substr(0, mini);
       
        for(int i = 0; i<n; i++){
            string curr = strs[i];
            if(curr.substr(0, mini) != temp){
                temp= cal(temp, curr);
            }
        }

        if(temp == ""){
            return "";
        }
        return temp;
    }
};