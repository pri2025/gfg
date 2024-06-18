class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size(); int m = s.size();
        int count = 0;
        if(m == 0){
            return 0;
        }
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i=0 , j= 0;
        while(i <n && j <m){
            if(s[j] >= g[i]){
                count++;
                i++;
            }
            j++;
        }
        return count;
    }
};


//for(int i =0; i< n; i++){
        //     for(int j = 0 ; j< m; j++){
        //         if(s[j] >= g[i]){
        //             count++;
        //             s[j] = -1;
        //             break;
        //         }
        //     }
        // }