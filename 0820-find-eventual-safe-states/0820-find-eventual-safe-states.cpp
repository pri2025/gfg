class Solution {
public:
    // void dfs(int node,vector<int> &pathvis, vector<int> &vis,vector<vector<int>>& graph,vector<int> &res ){
    //     vis[node] = 1; pathvis[node] = 1;
    //     for(auto it:graph[node]){
    //         if(vis[it]== 1 && pathvis[it] == 1){
    //             return;
    //         }
    //         else if (!vis[it]) {
    //             dfs(it, pathvis, vis, graph, res);
    //             if (pathvis[it] == 1) {
    //                 return; // If it leads to a cycle, return
    //             }
    //         }
            
    //     }
    //     pathvis[node] = 0;
    //     res[node]= 1;
    // }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size(); int m = graph[0].size();
        // vector<int> pathvis(n,0);
        // vector<int> vis(n,0);
        //vector<int> res(n,0);

        //for(int i = 0; i<n;i++){
        //     if(!vis[i]){
        //         dfs(i,pathvis,vis,graph,res);
        //     }
        // }
        // vector<int> f;
        // for(int i=0; i<n;i++){
        //     if(res[i] == 1){
        //         f.push_back(i);
        //     }
        // }
        // sort(f.begin(),f.end());
        // return f;
        vector<int> d(n,0);
        vector<vector<int>> rev(n);
        for(int i = 0; i<n ; i++){
            for(auto it: graph[i]){
                rev[it].push_back(i);//reversing edges
                d[i]++;//indegree
            }
        }

        queue<int> q;
        for(int i = 0; i<n;i++){
            if(d[i] == 0) q.push(i);
        }
        vector<int> res;
        while(!q.empty()){
            int s = q.size();
            for(int i = 0; i<s;i++){
                int node = q.front(); q.pop();
                res.push_back(node);
                for(auto it: rev[node]){
                    d[it]--;
                    if(d[it] == 0) q.push(it);
                }
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
};