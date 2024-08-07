//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
        // code 
        int n = arr1.size(); int m = arr2.size();
        vector<int> temp;
        int i =0, j= 0;
        while(i < n && j <m){
            if(arr1[i] <= arr2[j]){
                temp.push_back(arr1[i]);
                i++;
            }
            else{
                temp.push_back(arr2[j]); 
                j++;
            }
        }
        while(i <n){
            temp.push_back(arr1[i++]);
        }
        while(j < m){
            temp.push_back(arr2[j++]);
        }
        
        for(int i = 0; i<k;i++){
            if(i == k-1){
                return temp[i];
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> arr1, arr2;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr1.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            arr2.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(k, arr1, arr2) << endl;
    }
    return 0;
}
// } Driver Code Ends