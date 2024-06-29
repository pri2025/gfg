class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        if(tickets[k] ==0 ) return 0;
        int cnt = 0;

        for(int i =0; i<tickets.size(); i++){
            if(i <= k){
                if(tickets[i] <= tickets[k]){
                    cnt = cnt+ tickets[i];
                }
                else if(tickets[i] > tickets[k]){
                    cnt = cnt + tickets[k];
                }
            }
            else{
                cnt += min(tickets[i], tickets[k]-1);
            }
        }
        return cnt;
    }
};

//while(tickets[k] > 0){
        //     for(int i=0 ; i< tickets.size(); i++){
        //         if(tickets[i] >0){
        //             tickets[i]--;
        //             cnt++;
        //         }
        //         if(tickets[k] == 0){
        //             break;
        //         }
        //     }
        // }