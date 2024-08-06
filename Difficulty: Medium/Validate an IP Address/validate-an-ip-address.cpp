//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int countdot(string &str,string &a, string &b,string &c,string &d){
        int cnt = 0;
        for(auto it : str){
            if(it == '.') cnt++;
            else if(cnt == 0) a += it;
            else if(cnt == 1) b += it;
            else if(cnt == 2) c += it;
            else if(cnt == 3) d+= it;
        }
        return cnt;
    } 
    
    int valid(string &a, string &b, string &c, string &d){
        if(a == "" || b == "" || c == "" || d == "") return 0;
        
        if( (a.length() > 1 &&a[0] == '0') ||  (b.length() > 1 && b[0] == '0')
        || (c.length() > 1 && c[0] == '0') || (d.length() > 1 && d[0] == '0')){
            return 0;
        }
        if(a.length() > 3 || b.length() >3 ||c.length() >3 || d.length() >3) return 0;
        return 1;
    }
    int check(int x){
        if(x >=0 && x<=255) return 1;
        return 0;
    }
    int isValid(string str) {
        // code here
        string a = "", b = "", c="",d="";
        int count = countdot(str,a,b,c,d);
        if(count > 3) return 0;
        
        if(!valid(a,b,c,d)){
            return 0;
        }
        
        int x1 = stoi(a);
        int x2 = stoi(b);
        int x3 = stoi(c);
        int x4 = stoi(d);
        
        if(check(x1) && check(x2)&&check(x3)&&check(x4)) return 1;
        
        return 0;
        
        
        
        
    }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        // if (s.size() == 3) {
        //     cout << "false" << endl;
        //     return 0;
        // }
        Solution ob;
        bool f = ob.isValid(s);
        if (f)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends