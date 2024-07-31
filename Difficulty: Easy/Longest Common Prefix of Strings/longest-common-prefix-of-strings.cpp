//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    string fn(string &curr, string &temp){
        string ans = "";
        for(int i=0;i<curr.length();i++){
            if(curr[i] == temp[i]){
                ans += curr[i];
            }
            else{
                break;
            }
        }
        return ans;
    }

    string longestCommonPrefix(vector<string> arr) {
        // your code here
        int len = INT_MAX;
        for(int i= 0; i<arr.size();i++){
            if(arr[i].length()<len){
                //len = min(len,arr[i].length());
                len = arr[i].length();
            }
        }
        string temp = arr[0].substr(0,len);
        
        for(int i=0; i<arr.size();i++){
            string curr = arr[i].substr(0,len);
            if(curr != temp){
              temp =  fn(curr,temp);
            }
        }
        
        if(temp =="") return "-1";
        return temp;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.longestCommonPrefix(arr) << endl;
    }
}

// } Driver Code Ends