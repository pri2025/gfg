class Solution {
public:
    
    bool fn(vector<int>& arr, int target){
        int n = arr.size();
       
        int i = 0;
        int j= n-1;
        while(i <= j){
            int mid = (i+j)/2;
            if(target == arr[mid]){
                return true;
            }
            else if(target < arr[mid]){
                j = mid-1;
            }
            else{
                i = mid+1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();

    for (int i = 0; i < n; i++) {
        if (matrix[i][0] <= target && target <= matrix[i][m - 1]) {
            if (fn(matrix[i], target)){
                return true;
            }
        }
    }
    return false;
}

};


