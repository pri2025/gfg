class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int gs) {
        
        if(hand.size() % gs != 0) return false;
        map<int,int> mp;
        for(int i = 0; i<hand.size(); i++){
            mp[hand[i]]++;
        }

        for(auto it : mp){
            if(mp[it.first] > 0){
                for(int i =1; i<gs; i++){
                    mp[it.first + i] -= mp[it.first];
                    if(mp[it.first+i] < 0){
                        return false;
                    }
                }
            }
        }
        return true;

        // priority_queu<<int , greater<int>>> pq;
        // for(auto i:vec){
        //     pq.push(i.first); //numbers
        // }
        // int curr = INT_MIN;
        // while(!pq.empty()){
        //     if(mp[pq.top()] <=0 )
        // }
    }
};