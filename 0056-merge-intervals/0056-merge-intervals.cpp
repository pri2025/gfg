class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size(); int i = 0; int j = 1;
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        res.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); ++i) {
        // If the current interval overlaps with the last interval in res
            if (intervals[i][0] <= res.back()[1]) {
            // Merge the current interval with the last interval in res
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            } else {
            // Otherwise, add the current interval to res
                res.push_back(intervals[i]);
            }
        }

        return res;

        // while(j <n && intervals[i][1] < intervals[j][0]){
        //     res.push_back(intervals[i]); i++; j++;
        // }

        // while(j<n && intervals[i][1] >= intervals[j][0]){
        //     intervals[i][0] = min(intervals[i][0], intervals[j][0]);
        //     intervals[i][1] = max(intervals[i][1], intervals[j][1]);
        //     j++;
        // }
        // res.push_back(intervals[i]);

        // while( j<n){
        //     res.push_back(intervals[j]);
        // }
        // return res;
    }
};