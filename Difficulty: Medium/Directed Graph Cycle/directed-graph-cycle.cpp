//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    bool dfs(int node, vector<int> &vis, vector<int> &pathvis, vector<int> adj[]){
        if(vis[node] == 1 && pathvis[node] == 1){
            return true;
        }
        vis[node] = 1;
        pathvis[node] = 1;
        for(auto it: adj[node]){
            if(!vis[it]){
                if (dfs(it,vis,pathvis,adj)) return true;
            }
            else if(pathvis[it] == 1){
                return true;
            }
            
        }
        pathvis[node] = 0;
        return false;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        //vector<int> d(V,0);
        // queue<int> q;
        // for(int i=0; i<V;i++){
        //     for(auto it: adj[i]){
        //         d[it]++;
        //     }
        // }
        // for(int i = 0; i<V;i++){
        //     if(d[i] == 0) q.push(i);
        // }
        
        // while(!q.empty()){
        //     int n =q.size();
            
        //     for(int i= 0; i<n;i++){
        //         int node = q.front(); q.pop();
        //         for(auto it: adj[node]){
        //             d[it]--;
        //             if(d[it] == 0) q.push(it);
        //         }
                
        //     }
        // }
        
        //  for(int i = 0; i<V;i++){
        //     if(d[i] != 0) return true;
        // }
        vector<int> vis(V,0);
        vector<int> pathvis(V,0);
        for(int i = 0; i<V; i++){
            if(!vis[i]){
              if(dfs(i,vis,pathvis,adj)) return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends