class Solution {
public:
    int fn(int egg, int f, vector<vector<int>> &table){
        if(f == 0 || f == 1) return f;
        if(egg == 1) return f;

        if(table[egg][f] != -1) return table[egg][f];

        int mini = INT_MAX;
        for(int k = 1; k<=f; k++){
            int low, high;
            //if egg breaks;
            if(table[egg-1][k-1] != -1){
                low = table[egg-1][k-1];
            }
            else{
                low = fn(egg-1, k-1,table);
                table[egg-1][k-1] = low;
            }

            //if egg breaks;
            if(table[egg][f-k] != -1){
                high = table[egg][f-k];
            }
            else{
                high = fn(egg,f-k, table);
                table[egg][f-k] = high;
            }

            //take max of worst cases;
            int temp = max(low,high);
            //choose min of max
            mini = min(mini,temp+1);
        }

        return table[egg][f] = mini;
    }
    
    int twoEggDrop(int f) {
        vector<vector<int>> table(3, vector<int>(f+1 , -1));
        //table with 3 rows( 0 1 2 egg) and f+1 columns (0,1,2...f);
        return fn(2,f,table);
    }
};