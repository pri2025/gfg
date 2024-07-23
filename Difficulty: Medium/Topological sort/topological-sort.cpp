//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
// 	void dfs(int node,vector<int> &vis, vector<int> adj[],stack<int> &st){
// 	    if(vis[node] == 1){
// 	        return;
// 	    }
// 	    vis[node] = 1;
// 	    for(auto it: adj[node]){
// 	        if(!vis[it]){
// 	            dfs(it,vis,adj,st);
// 	        }
// 	    }
// 	    st.push(node);
// 	}
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> vis(V,0);
	    //stack<int> st;
	    queue<int> q;
	    vector<int> d(V,0);
	    vector<int> res;
	    //cal indegrees
	    for(int i = 0; i<V;i++){
	        for(auto it: adj[i]){
	            d[it]++;
	        }
	    }
	    //pushing nodes with 0 degree
	    for(int i = 0; i<V;i++){
	        if(d[i] == 0){
	            q.push(i);
	        }
	    }
	    
	    while(!q.empty()){
	        int n = q.size();
	        
	        for(int i = 0; i<n;i++){
	            int node = q.front(); q.pop();
	            
	            for(auto it: adj[node]){
	                d[it]--;
	                if(d[it] == 0) q.push(it);
	            }
	            
	            res.push_back(node);
	        }
	    }
	    
	   // for(int i =0;i<V;i++){
	   //     if(!vis[i]){
	   //         dfs(i,vis,adj,st);
	   //     }
	   // }
	   // vector<int> res;
	   // for(int i=0; i<V;i++){
	   //     res.push_back(st.top());
	   //     st.pop();
	   // }
	    return res;
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends