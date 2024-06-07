class Solution {
public:
    int singleNumber(vector<int>& arr) {
        int n = arr.size();
        int xorr = 0;
        for(int i=0; i<n ;i++){
            xorr = xorr ^ arr[i];
        }
        return xorr;



    //      map<int, int> mpp;
    // for (int i = 0; i < n; i++) {
    //     mpp[arr[i]]++;
    // }

    // //Find the single element and return the answer:
    // for (auto it : mpp) {
    //     if (it.second == 1)
    //         return it.first;
    // }
        // int maxi = nums[0];
        // for(int i=0; i<n; i++){
        //     maxi = max(maxi,nums[i]);
        // }

        // vector<int> hash(maxi+1,0);
        // for(int i = 0; i<n; i++){
        //     hash[nums[i]]++;
             
        // }

        // for(int i = 0; i<n;i++){
        //     if(hash[nums[i]] == 1){
        //         return nums[i];
        //     }
        // }
        
       // return -1;
    }
};


//  int curr ;
//         if(n ==1){
//             return nums[0];
//         }
//         int count = 0;
//         for(int i = 0; i<n; i++){
//              curr = nums[i];
//             count = 0;
//             for(int j= 0; j<n ; j++){
//                 if(curr == nums[j]){
//                     count++;
//                 }
//             }
//             if(count == 1)
//             break;

//         }


//int xorr = 0;
// for(int i = 0; i<n ;i ++){
//     xorr = xorr^arr[i];
// }
// return xorr;