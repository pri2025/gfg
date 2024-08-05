class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        int n = arr.size();
        if(n < k) return "";
        map<string,int> freq;
        for(int i =0; i<n;i++){
            freq[arr[i]]++;
        }
        int cnt = 0;
        for(int i =0 ; i<n ;i++){
            if(freq[arr[i]] == 1){
                cnt++;
                if(cnt == k) return arr[i];
            }
            
        }
        return "";
    }
};