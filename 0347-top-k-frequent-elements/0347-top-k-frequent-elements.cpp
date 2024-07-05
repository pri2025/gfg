class Solution {
public:
    
    map<int,int> mp;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        for(int i : nums){
            mp[i]++;
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minheap;

        for(auto it : mp){
            if(minheap.size() < k){
                minheap.push({it.second,it.first});
            }
            else if(it.second > minheap.top().first){
                minheap.pop();
                minheap.push({it.second,it.first});
            }
        }
        vector<int> res;
        while(!minheap.empty()){
            res.push_back(minheap.top().second);
            minheap.pop();
        }
        return res;
    }
        
};

//vector<int> res;
        // int m = INT_MAX;
        // for(auto i :mp){
        //     if(k){
        //         if(i.second <= m){
        //             res.push_back(i.first);
        //             k--;
        //             m = i.second;
        //         }
        //     }
        // }
        // return res;