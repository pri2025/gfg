class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newi) {
        int n = intervals.size();
        int i = 0;
        vector<vector<int>> res;
        while(i < n && intervals[i][1] < newi[0]){
            res.push_back(intervals[i]);
            i++;
        }
        while(i < n && intervals[i][0] <= newi[1]){
            newi[0] = min(intervals[i][0], newi[0]);
            newi[1] = max(intervals[i][1], newi[1]);
            i++; 
        }
        res.push_back(newi);

        while(i <n){
            res.push_back(intervals[i]);
            i++;
        }

        return res;
    }
};