class Solution {
public:
void dfs(int node, vector<int>& vis, vector<vector<int>>& isConnected) {
    vis[node] = 1;
    
    for (int i = 0; i < isConnected.size(); i++) {
        if (!vis[i] && isConnected[node][i]) {
            dfs(i, vis, isConnected);
        }
    }
}
    // void fn(int node, vector<int> &vis,vector<vector<int>>& isConnected){
    //     vis[node] = 1;
        
    //     for(int i = 0; i < isConnected[node].size(); i++){
    //         if(!vis[i+1] && isConnected[node][i] == 1){
    //             fn(i+1,vis,isConnected);
    //         }
    //     }
    // }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n,0);
        int cnt = 0;
        for(int i = 0; i < n;i++){
            if(!vis[i]){
                cnt++;
                dfs(i,vis,isConnected);
            }
        
        }
        return cnt;
    }
        
};