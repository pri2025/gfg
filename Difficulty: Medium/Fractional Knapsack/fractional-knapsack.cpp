//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value;
    int weight;
};


// } Driver Code Ends
// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n) {
        // Your code here
        vector<pair<double,int>> ratio;
        for(int i =0; i<n; i++){
            double x = (double) arr[i].value/arr[i].weight;
            ratio.push_back({x,i});
        }
        
        sort(ratio.begin(), ratio.end(), greater<pair<double,int>>());
        
        double score = 0;
        int currw = 0;
        
        for(int i = 0; i<ratio.size(); i++){
            if(currw + arr[ratio[i].second].weight <= w){
                score += arr[ratio[i].second].value;
                currw += arr[ratio[i].second].weight;
            }
            else{
                int rem = w - currw;
                score += (double)rem*ratio[i].first;
                 break;
            }
        }
        return score;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    // taking testcases
    cin >> t;
    cout << setprecision(6) << fixed;
    while (t--) {
        // size of array and weight
        int n, W;
        cin >> n >> W;

        Item arr[n];
        // value and weight of each item
        for (int i = 0; i < n; i++) {
            cin >> arr[i].value >> arr[i].weight;
        }

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(W, arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends