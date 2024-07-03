class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mp;
        for(int i=0; i<tasks.size(); i++){
            mp[tasks[i]]++;
        }

        priority_queue<int, vector<int>> pq;

        for(auto i : mp){
            pq.push(i.second);
        }
        int r = 0;
        while(!pq.empty()){
            vector<int> tmp;
            int time = 0;
            for(int i = 0; i<=n; i++){
                if(!pq.empty()){
                    tmp.push_back(pq.top() -1);//cnt decrease krke
                    pq.pop();
                    time++;
                }
            }
            //push back to pq
            for(auto i : tmp){
                if(i) pq.push(i); // not zero
            }
             if(pq.empty()){
                r += time;
            }
            else{
                r += n+1;
            }
        }
        return r;
    }
};