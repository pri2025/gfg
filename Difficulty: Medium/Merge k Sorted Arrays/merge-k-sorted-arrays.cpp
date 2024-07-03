//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++


class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> res;
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        priority_queue<pair<int, pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        
        for(int i =0; i<k; i++){
            pq.push({arr[i][0],{i,0}}); // i is array index and 0 value index
        }
        
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            
            res.push_back(top.first);// the value
            
            int apos = top.second.first;
            int vpos = top.second.second;
            
            if(vpos+1 < arr[apos].size()){
                pq.push({arr[apos][vpos+1],{apos,vpos+1}});
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}






// } Driver Code Ends