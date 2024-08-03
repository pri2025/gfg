class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int n= target.size(); int maxi =INT_MIN;
        vector<int> hash(1001,0);
        for(int i=0; i<n;i++){
            hash[target[i]]++;
            hash[arr[i]]--;

            maxi  =max({maxi,target[i],arr[i]});

        }

        for(int i=0; i<=maxi;i++){
            if(hash[i] !=0) return false;
        }
        return true;
        // sort(target.begin(), target.end());
        // sort(arr.begin(), arr.end());
        // int i =0, j=0;
        // while(i<n){
        //     if(target[i] != arr[j]){
        //         return false;
        //     }
        //     i++;j++;
        // }
        return true;
    }
};