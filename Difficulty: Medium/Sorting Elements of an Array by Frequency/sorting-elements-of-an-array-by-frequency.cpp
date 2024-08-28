//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Complete this function
    // Function to sort the array according to frequency of elements.
    bool static cmp(pair<int,int> a, pair<int,int> b){
        if(a.second == b.second){
            return a.first < b.first;
        }
        return a.second > b.second;
    }
    vector<int> sortByFreq(vector<int>& arr) {
        // Your code here
        //sort(arr.begin(),arr.end());
        unordered_map<int,int> mp;
        for(int it: arr){
            mp[it]++;
        }
        vector<pair<int,int>> res;
        for(auto it: mp){
            res.push_back({it.first,it.second});
        }
        sort(res.begin(), res.end(),cmp);
        
        vector<int> ans;
        for(auto it: res){
            for(int i =0; i <it.second;i++){
                ans.push_back(it.first);
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution obj;
        vector<int> v;
        v = obj.sortByFreq(arr);
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends