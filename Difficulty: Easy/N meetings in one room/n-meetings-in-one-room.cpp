//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    bool static cmp(pair<int,int> a, pair<int,int> b){
        return a.second < b.second;
        
    }
    int maxMeetings(int n, int start[], int end[]) {
        // Your code here
        vector<pair<int,int>> group;
        for(int i = 0; i<n;i++){
            group.push_back({start[i],end[i]});
        }
        
        sort(group.begin(),group.end(), cmp);
        int i = 0; int j = 1;
        int cnt = 1;
        while(j < n){
            if(group[j].first > group[i].second){
                cnt++;i = j;
            }
            j++;
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
        for (int i = 0; i < n; i++)
            cin >> start[i];

        for (int i = 0; i < n; i++)
            cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(n, start, end);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends