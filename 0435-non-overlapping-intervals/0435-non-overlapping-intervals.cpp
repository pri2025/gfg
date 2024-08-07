class Solution {
public:
    bool static cmp(vector<int> &a , vector<int> &b){
        return a[1]< b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int cnt = 0; int n = intervals.size();
        sort(intervals.begin(), intervals.end(),cmp);
            
        int end  = intervals[0][1];
        for(int i =1; i<n ; i++){
            if(intervals[i][0] < end){
                cnt++;
            }
            else{
                end = max(end,intervals[i][1]);
            }
        }
        return cnt;
    }
};