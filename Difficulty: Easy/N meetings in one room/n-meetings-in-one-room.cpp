//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    vector<pair<int,int>> vec;
    bool static comparator(pair<int,int> &a, pair<int,int> &b){
            return a.second < b.second;
        }
    int maxMeetings(int s[], int end[], int n)
    {
        
        // Your code here
        int i = 0, j = 0;
        while(i<n && j <n){
           vec.push_back({s[i],end[j]});
           i++; j++;
        }
        sort(vec.begin(), vec.end(), comparator);
        int k = 1;
        int cnt = 1;
        int it = 0;
        while(k < vec.size()){
            if(vec[k].first > vec[it].second){
                cnt++;
                it = k;
            }
            k++;
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends