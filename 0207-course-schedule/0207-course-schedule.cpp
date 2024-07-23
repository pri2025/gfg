class Solution {
public:

    // bool dfs(int node, vector<int> &vis, vector<int> &re, vector<vector<int>> &adj){
    //     if(vis[node] == 1)return false;

    //     vis[node] = 1;
    //     for(auto it : adj[node]){
    //         if(!vis[it]){
    //             dfs(it,vis,adj);
    //         }
    //         else{
    //             return false;
    //         }
    //     }
    //     return true;
    // }
    bool canFinish(int num, vector<vector<int>>& arr) {
        int n = arr.size(); 
        if(n == 0) return true;
        vector<vector<int>> adj(num);
        vector<int> d(num,0);
        for(auto it: arr){
            adj[it[1]].push_back(it[0]);
            d[it[0]]++;
        }//dag
        
        // for(int i = 0; i<n;i++){
        //     for(auto it: adj[i]){
        //         d[it]++;
        //     }
        // }
        queue<int> q;
        for(int i = 0; i<num;i++){
            if(d[i] == 0) q.push(i);
        }
        //vector<int> order;
        int cnt = 0;
        while(!q.empty()){
            int s = q.size();
            for(int i = 0; i < s; i++){
                int node = q.front(); q.pop(); cnt++;
                //order.push_back(node);
                for(auto it : adj[node]){
                    d[it]--;
                    if(d[it] == 0)q.push(it);
                }
            }
        }
        if(cnt == num) return true;
        return false;
        
    }
};