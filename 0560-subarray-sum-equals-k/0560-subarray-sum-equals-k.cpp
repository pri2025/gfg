class Solution {
public:
    int subarraySum(vector<int>& a, int k) {      int j=0, i = 0;
        int n = a.size();
        int count =0;
        map<int,int> mp;
        int sum = 0;
        for(int i = 0; i<n ; i++){
            sum = sum+a[i];
            if(sum == k){
                count++;
            }
            int rem = sum - k;
            if(mp.find(rem) != mp.end()){
                count+=mp[sum-k];
            }
            mp[sum]++;
        }
       
        return count;
    }
};


 // while(j<n){
        //     while(sum > k && i<=j){
        //         sum = sum - a[i];
        //         i++;
        //     }
        //     if(sum == k){
        //         count++;
        //     }
        //     if(j< n){
        //         j++;
        //         sum = sum + a[j];
                
        //     }
          
           
            
        // }