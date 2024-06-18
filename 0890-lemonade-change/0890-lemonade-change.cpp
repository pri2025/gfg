class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size(),cnt= 0, cnt1 = 0, cnt2 = 0;
        for(int i=0; i<n ; i++){
            if(bills[i] == 5){
                cnt++;
            }
            else if(bills[i] == 10){
                if(cnt > 0){
                    cnt--;
                    cnt1++ ;
                }
                else{
                    return false;
                }
            }
            else{
                if(cnt >= 1 && cnt1 >= 1){
                    cnt--, cnt1--;
                }
                else if(cnt >= 3 && cnt1 == 0){
                    cnt = cnt-3;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};