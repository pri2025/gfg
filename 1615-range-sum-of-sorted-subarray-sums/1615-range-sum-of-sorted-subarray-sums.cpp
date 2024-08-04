class Solution {
public:
    int mod = 1e9 + 7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<long long>res;
        for(int i = 0; i<n; i++){
            res.push_back(nums[i]);
            long long sum = nums[i];
            for(int j= i+1; j <n; j++){
                sum += nums[j];
                sum = sum % mod;
                res.push_back(sum);
            }
        }
        sort(res.begin(), res.end());
        int ans =  0;
        for(int i= left-1; i<=right-1;i++){
            ans += res[i];
            ans %= mod;
        }
        return ans;
    }
};