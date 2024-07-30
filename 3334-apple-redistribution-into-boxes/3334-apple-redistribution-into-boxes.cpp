class Solution {
public:
    bool static cmp(int a,int b){
        return a>b;
    }
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(), capacity.end(),cmp);
        int sum=0;
        for(int i =0 ; i<apple.size();i++){
           sum += apple[i];
        }
        int cnt = 0;
        for(int j=0; j<capacity.size();j++){
                if(sum>0){
                    sum -= capacity[j];
                    cnt++;
                }  
        }
        return cnt;
    }
};