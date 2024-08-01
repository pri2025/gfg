//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &arr) {
        // code here
        vector<int> res;
        int n = arr.size(); int m = arr[0].size();
        int top = 0, bottom = n-1, right = m-1, left = 0;
        
        while(top <=bottom && left <= right){
            for(int i = left; i<=right;i++){
                res.push_back(arr[top][i]);
            }
            top++;
            for(int i =top;i<=bottom; i++){
                res.push_back(arr[i][right]);
            }
            right--;
            if(top<=bottom){
                for(int i =right; i>=left;i--){
                    res.push_back(arr[bottom][i]);
                }
                bottom--;
            }
            if(left <=right){
                for(int i = bottom; i>=top;i--){
                    res.push_back(arr[i][left]);
                }
                left++;
            }
            
        }
        return res;
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c, 0));

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends