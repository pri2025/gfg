class Solution {
public:
    vector<int> findOrder(int num, vector<vector<int>>& arr) {
        int n = arr.size(); 
        vector<int> order;
        if(n == 0){
            for(int i = 0; i<num;i++){
                order.push_back(i);   
            }
            return order;
        }
        vector<vector<int>> adj(num);
        vector<int> d(num,0);
        for(auto it: arr){
            adj[it[1]].push_back(it[0]);
            d[it[0]]++;
        }//dag
     
        queue<int> q;
        for(int i = 0; i<num;i++){
            if(d[i] == 0) q.push(i);
        }
        int cnt = 0;
        while(!q.empty()){
            int s = q.size();
            for(int i = 0; i < s; i++){
                int node = q.front(); q.pop(); cnt++;
                order.push_back(node);
                for(auto it : adj[node]){
                    d[it]--;
                    if(d[it] == 0)q.push(it);
                }
            }
        }
        if(cnt == num) return order;
        return {};
        
    }
};