class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>> pq;

        for(auto it: points){
            pq.push({(it[0]*it[0] + it[1]*it[1]), {it[0],it[1]}});
            if(pq.size() > k){
                pq.pop();
            }
        }

        vector<vector<int>> res;

        while(!pq.empty()){
            auto i = pq.top();
            res.push_back({i.second.first, i.second.second});
            pq.pop();
        }

        return res;

    }
};