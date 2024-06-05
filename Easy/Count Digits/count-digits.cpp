//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int count = 0;
    int digit =0;
    int temp;
    int evenlyDivides(int N){
        //code here
        if(N == 0){
            return 0;
        }
        temp = N;
        while(temp>0){
            digit = temp % 10;
            if(digit >0 && N % digit == 0){
                count++;
            }
            temp = temp / 10;
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.evenlyDivides(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends