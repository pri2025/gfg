class Solution {
public:
    void fn(int index, int target,vector<int>& arr,vector<vector<int>> &res,vector<int> &ans){
        if(target == 0){
            res.push_back(ans);
            return;
        }
        if(index == arr.size() || target < 0){
            return;
        }

        for (int i = index; i < arr.size(); i++) {
        // Skip duplicates
            if (i > index && arr[i] == arr[i - 1]) continue;
            if(arr[i] > target) break;
        // Include the current element
            if (arr[i] <= target) {
                ans.push_back(arr[i]);
                fn(i + 1, target - arr[i], arr, res, ans);
                ans.pop_back();
            }
        }

        // if(arr[index] <= target){
        //     ans.push_back(arr[index]);
        //     fn(index+1, target-arr[index],arr,res,ans);
        //     ans.pop_back();
        // }
        // fn(index+1,target,arr,res,ans);
    }
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        vector<vector<int>> res;
        vector<int> ans;
        int index = 0;
        sort(arr.begin(), arr.end());
        fn(index, target,arr,res,ans);

        return res;
    }
};