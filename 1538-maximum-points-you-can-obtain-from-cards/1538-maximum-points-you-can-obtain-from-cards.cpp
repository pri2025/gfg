class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int n = arr.size();
        int maxsum =0;  int leftsum =0, rsum = 0;
        if(n == k){
            for(int i=0;i<n;i++){
                maxsum = maxsum + arr[i];
            }
            return maxsum;
        }
        for( int i =0; i<k; i++){
            leftsum += arr[i];
        }
        maxsum = leftsum;
        int i = 0, j = n-1;
        

        for(int i = k-1; i>= 0; i--){
            leftsum -= arr[i];
            rsum += arr[j];
            j--;
            maxsum = max(maxsum, leftsum + rsum);
        }
        return maxsum;
    }
};