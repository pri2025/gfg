class Solution {
public:
    void dfs(int node,vector<int> &pathvis, vector<int> &vis,vector<vector<int>>& graph,vector<int> &res ){
        vis[node] = 1; pathvis[node] = 1;
        for(auto it:graph[node]){
            if(vis[it]== 1 && pathvis[it] == 1){
                return;
            }
            else if (!vis[it]) {
                dfs(it, pathvis, vis, graph, res);
                if (pathvis[it] == 1) {
                    return; // If it leads to a cycle, return
                }
            }
            
        }
        pathvis[node] = 0;
        res[node]= 1;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> pathvis(n,0);
        vector<int> vis(n,0);
        vector<int> res(n,0);

        for(int i = 0; i<n;i++){
            if(!vis[i]){
                dfs(i,pathvis,vis,graph,res);
            }
        }
        vector<int> f;
        for(int i=0; i<n;i++){
            if(res[i] == 1){
                f.push_back(i);
            }
        }
        sort(f.begin(),f.end());
        return f;
        // vector<int> d(n,0);
        // vector<int> out;
        // for(int i = 0; i<n ; i++){
        //     if(graph[i] == NULL){
        //         out.push_back(i);// finding nodes with outdegree zero;
        //     }
        //     for(auto it: graph[i]){
        //         d[it]++;
        //     }//indegree

        //     queue<int> q;
        //     for(int i = 0 ; i<n ; i++){
        //         if(d[i] == 0) q.push(i);
        //     }

        //     while(!q.empty()){

        //     }
        // }


        

        
    }
};